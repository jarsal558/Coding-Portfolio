#include <msp430.h>


#define NUM_BYTES  2                       // How many bytes?
//**** Please note this value needs to be the same as NUM_BYTES_RX in the
//     associated master code. This definition lets the slave know when to
//     switch from RX interrupt sources to TX interrupt sources. This is
//     important since the interrupt vectors are shared by TX and RX flags.

/* **** definitions **** */
#define SAMPLE_PERIOD   0x7FFF          /* clocks between ADC sampling */
/* pinout */
#define LED1            BIT0            /* LED1 is on P1.0 */
#define LED2            BIT6            /* LED2 is on P1.6 */
#define SENSOR          BIT1            /* sensor input on P1.1 */
#define SENSOR_GND      BIT2            /* connect sensor to GND on P1.2 */

unsigned char *PTxData;                     // Pointer to TX data
unsigned char *PRxData;                     // Pointer to RX data
volatile unsigned char RxBuffer[128];       // Allocate 128 byte of RAM
char SLV_Data = 0x11;
volatile unsigned char TXByteCtr, RXByteCtr, RX = 0;
volatile unsigned char RxBuffer[128];       // Allocate 128 byte of RAM


void USCI_SLAVE_SETUP(void);
void Setup_RX(void);
void Receive(void);

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  /* configure the sensor ground pin */
  P1REN &= ~(SENSOR_GND);             /* disable pull-up/down */
  P1OUT &= ~(SENSOR_GND);             /* SENSOR_GND should be at GND */
  P1DIR |= SENSOR_GND;                /* SENSOR_GND must be an output */

  P1REN |= SENSOR;                    /* enable pull-up on SENSOR */
  P1OUT |= SENSOR;                    /* set resistor as pull-up */

  ADC10CTL0 = SREF_0 | ADC10SHT_2 | ADC10ON;
  ADC10CTL1 = INCH_1 | ADC10DIV_7 | ADC10SSEL_2;
  ADC10AE0 = SENSOR;

  while(1){
  USCI_SLAVE_SETUP();

  /* start ADC conversion */
  ADC10CTL0 |= (ENC | ADC10SC);

  /* wait for ADC conversion to complete */
  while (ADC10CTL1 & ADC10BUSY);

  /* grab data from ADC */
  *PRxData = ADC10MEM;                /* this is a 10-bit unsigned value */

  }
}

//------------------------------------------------------------------------------
// The USCI_B0 data ISR is used to move data from MSP430 memory to the
// I2C master. PTxData points to the next byte to be transmitted, and TXByteCtr
// keeps track of the number of bytes transmitted.
//------------------------------------------------------------------------------
#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void)
{
  if(RX == 0)
  { UCB0TXBUF = SLV_Data++;      // Transmit data at address PTxData
  	TXByteCtr++;                              // Increment TX byte counter
  }
  if(RX == 1)
  {	*PRxData++ = UCB0RXBUF;       // Move RX data to address PRxData
  	RXByteCtr++;                              // Increment RX byte count
  	if(RXByteCtr >= NUM_BYTES){        //>=       // Received enough bytes to switch
	  RX = 0;                                   // to TX?
	  IE2 &= ~UCB0RXIE;
	  IE2 |= UCB0TXIE;
	  RXByteCtr = 0;
	}
  }
}

//------------------------------------------------------------------------------
// The USCI_B0 state ISR is used to wake up the CPU from LPM0 in order to do
// processing in the main program after data has been transmitted. LPM0 is
// only exit in case of a (re-)start or stop condition when actual data
// was transmitted.
//------------------------------------------------------------------------------
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIAB0RX_ISR(void)
{
  if(RX == 0)
  { UCB0STAT &= ~(UCSTPIFG + UCSTTIFG);       // Clear interrupt flags
  	if (TXByteCtr)                            // Check TX byte counter
      __bic_SR_register_on_exit(CPUOFF);       // Exit LPM0 if data was
  }                                           // transmitted
  if(RX == 1)
  {
	UCB0STAT &= ~(UCSTPIFG + UCSTTIFG);       // Clear interrupt flags
  }
}
void Setup_RX(void){
  _DINT();
  RX = 1;
  IE2 &= ~UCB0TXIE;                         // Disable TX interrupt
  UCB0CTL1 |= UCSWRST;                      // Enable SW reset
  UCB0CTL0 = UCMODE_3 + UCSYNC;             // I2C Slave, synchronous mode
  UCB0I2COA = 0x48;                         // Own Address is 048h
  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
  UCB0I2CIE |= UCSTPIE + UCSTTIE;           // Enable STT and STP interrupt
  IE2 |= UCB0RXIE;                          // Enable RX interrupt

}

void Receive(void){
    PRxData = (unsigned char *)RxBuffer;    // Start of RX buffer
    RXByteCtr = 0;                          // Clear RX byte count
    TXByteCtr = 0;
    __bis_SR_register(CPUOFF + GIE);        // Enter LPM0 w/ interrupts
                                            // Remain in LPM0 until master
                                            // finishes TX
}
void USCI_SLAVE_SETUP(void){
  P1SEL |= BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
  P1SEL2|= BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
  Setup_RX();
  Receive();
}
