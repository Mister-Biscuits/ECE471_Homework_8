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
    DIO_CHAN_ENB(CHAN1); /* Enable PD0 as I/O port */
    DIO_CHAN_OUT(CHAN1); /* Set PD0 as a output port */
    
    DIO_CHAN_ENB(CHAN3);
    DIO_CHAN_IN(CHAN3);     /* RD2 set as input first to read... */
    DIO_CHAN_OUT(CHAN3);    /* then output to write result */
    
    //Debug Test
    //PORTDbits.RD0 = 1;

    while(1) { /*generate a square wave at port PD0*/
        DIO_CHAN_HI(CHAN1); /*write 1 to RD0*/
        DIO_CHAN_WRITE(CHAN3, DIO_CHAN_READ(CHAN1));
        for(int i=0; i<300; i++) { } /* Delay */
        DIO_CHAN_LO(CHAN1); /*write 0 to RD0*/
        DIO_CHAN_WRITE(CHAN3, DIO_CHAN_READ(CHAN1));
        for(int i=0; i<300; i++) { } /* Delay */
    }

}
