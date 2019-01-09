#include "msp430.h"                     /* include MSP430 definitions */


/* **** definitions **** */
#define SAMPLE_PERIOD   0x7FFF          /* clocks between ADC sampling */

/* pinout */
#define LED1            0x01            /* LED1 is on P1.0; the LED is to be an output; originally 0x01 was BIT0 */
#define SENSOR          0x02            /* sensor input on P1.1; the sensor is an input; originally 0x02 was BIT1 */
#define SENSOR_GND      0x04            /* connect sensor to GND on P1.2; GND is to be connected to ground; originally 0x04 was BIT2 */

/* shortcuts */
#define RED_LED         LED1

/** mainloop */
void main(void) {

    unsigned short data;                /* data read from ADC */


    /* *************************************************************************
     * initialize system
     **************************************************************************/

    /* disable global interrupts - don't need interrupts on this project */
    __disable_interrupt();

    /* disable WDT so that the processor does not reset */
    WDTCTL = WDTPW | WDTHOLD;

    /* *************************************************************************
     * configure pins
     **************************************************************************/

    /* configure all pins as digital inputs with pull-downs (to save power) */

    /* PORT 1 */
    P1DIR = 0;                          /* set as inputs */
    P1SEL = 0;                          /* set as digital I/Os */
    P1OUT = 0;                          /* set resistors as pull-downs */
    P1REN = 0xFF;                       /* enable pull-down resistors */
    /* PORT 2 */
    P2DIR = 0;                          /* set as inputs */
    P2SEL = 0;                          /* set as digital I/Os */
    P2OUT = 0;                          /* set resistors as pull-downs */
    P2REN = 0xFF;                       /* enable pull-down resistors */


    /* now configure the pins that we will actually use */

    /* configure both LEDs as digital outputs */
    P1REN &= ~(LED1);            /* disable pull-up/downs */
    P1DIR |= (LED1);             /* configure as outputs */

    /* configure the sensor ground pin */
    P1REN &= ~(SENSOR_GND);             /* disable pull-up/down */
    P1OUT &= ~(SENSOR_GND);             /* SENSOR_GND should be at GND */
    P1DIR |= SENSOR_GND;                /* SENSOR_GND must be an output */

    /* configure the sensor pin as an ADC pin with a pull-up resistor
     *
     * Note: this is quite strange to do in normal situations, I am just trying
     * to use the internal pull-up resistor rather than putting my own on the
     * board */
    P1REN |= SENSOR;                    /* enable pull-up on SENSOR */
    P1OUT |= SENSOR;                    /* set resistor as pull-up */

    /* *************************************************************************
     * configure ADC
     **************************************************************************/

    /* configure ADC using the following parameters:
     *  - Vcc and GND references
     *  - 16 clock sample and hold
     *  - use A1 input
     *  - clock source: MCLK/8
     *  - single conversion mode under software control
     *  - 10-bit unsigned value
     */
    ADC10CTL0 = SREF_0 | ADC10SHT_2 | ADC10ON;
    ADC10CTL1 = INCH_1 | ADC10DIV_7 | ADC10SSEL_2;
    ADC10AE0 = SENSOR;


    /* *************************************************************************
     * run mainloop
     **************************************************************************/

    while (1) {                         /* mainloop never exits */

        /* start ADC conversion */
        ADC10CTL0 |= (ENC | ADC10SC);

        /* wait for ADC conversion to complete */
        while (ADC10CTL1 & ADC10BUSY);

        /* grab data from ADC */
        data = ADC10MEM;                /* this is a 10-bit unsigned value */

        __delay_cycles(SAMPLE_PERIOD);
    }
}

