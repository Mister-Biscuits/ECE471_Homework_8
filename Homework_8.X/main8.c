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

main() {
    int i;

    DIO_CHAN_ENB(CHAN1); /* Enable PS0 as I/O port */
    DIO_CHAN_OUT(CHAN1); /* Set PA0 as a output port */

    while(1) { /*generate a square wave at port PA0*/

        DIO_CHAN_HI(CHAN1); /*write 1 to port PS0*/

        for (i=0;i<30000; i++) { }/* Delay */

        DIO_CHAN_LO(CHAN1); /*write 0 to port PS0*/

        for (i=0;i<30000; i++) { }
    }

}
