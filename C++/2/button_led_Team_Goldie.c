//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  J. Stevenson
//  Texas Instruments, Inc
//  July 2011
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>				
	unsigned int X=0x0;
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	//unsigned int i=0;
	P1DIR = 0x01;
	P1OUT=0x08;
	P1REN=0x08;


//	for(;;) {
while(1)
{

		//X=P1IN;
		//X&=0x08;
		//X=X;
		 if (0x08 & P1IN) P1OUT |= 0x01;         // if P1.3 set, set P1.0
		    else P1OUT &= ~0x01;                    // else reset
	//	P1OUT=X;

//	}
}

	return 0;
}
