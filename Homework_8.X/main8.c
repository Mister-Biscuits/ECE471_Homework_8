/*
 * File:   main8.c
 * Author: skyler
 *
 * Created on March 22, 2026, 7:03 PM
 */


#include <xc.h>
#include "pic_hal.h"
#pragma config OSC = IRCIO
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDTEN = OFF

#define _XTAL_FREQ 4000000

int main() {
    DIO_CHAN_ENB(CHAN1); //Enable pin RD0
    DIO_CHAN_OUT(CHAN1); //Set RD2 (CHAN1) to output
    
    DIO_CHAN_ENB(CHAN3); //Enable pin RD2
    DIO_CHAN_OUT(CHAN3); //Set RD2 (CHAN3) to output
    
    //Debug Test
    //PORTDbits.RD0 = 1;

    while(1) { /*generate a square wave at pin PD0*/
        
        DIO_CHAN_HI(CHAN1); //Set RD0 (CHAN1) to 1
        DIO_CHAN_WRITE(CHAN3, DIO_CHAN_READ(CHAN1)); //Read and copy CHAN1
        
        for(int i=0; i<300; i++) { } /* Delay */
        
        DIO_CHAN_LO(CHAN1); //Set RD0 (CHAN1) to 0
        DIO_CHAN_WRITE(CHAN3, DIO_CHAN_READ(CHAN1)); //Read and copy CHAN1
        
        for(int i=0; i<300; i++) { } /* Delay */
    }

}
