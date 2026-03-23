/* 
 * File:   pic_hal.h
 * Author: Skyler
 * Comments: Taking code from example 16.1 in ECE471 slideshow SkillOne and 
 * adapting it to the PIC from HC12
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

typedef unsigned char UBYTE;

#define _B0_ (UBYTE) 0x01 /* B0 is the lsb of an 8 bit register*/

// Channel 1
#define CHAN1 1 
#define CHAN_ENB_1 PORTD /* Dummy enable register*/
#define CHAN_DIR_1 TRISD /* Direction register of PS0*/
#define CHAN_PORT_1 PORTD /* PORTA is data register */
#define CHAN_MASK_1 _B0_ /* The bit field of PS0 */
#define CHAN_ENMASK_1 0xFF

//Channel 2
#define CHAN2 2
#define CHAN_ENB_2 PORTB /* Dummy enable register*/
#define CHAN_DIR_2 TRISB /* Direction register of PS0*/
#define CHAN_PORT_2 PORTB /* PORTA is data register */
#define CHAN_MASK_2 _B0_ /* The bit field of PS0 */
#define CHAN_ENMASK_2 0xFF

#define CHAN3 3
#define CHAN_ENB_3   PORTD
#define CHAN_DIR_3   TRISD
#define CHAN_PORT_3  PORTD
#define CHAN_MASK_3  (UBYTE)0x04    /* bit 2 = RD2 */
#define CHAN_ENMASK_3 0xFF

 
/* Dummy enable operator */
#define CHAN_TO_ENB(n)CHAN_ENB_##n
#define CHAN_TO_DIR(n) CHAN_DIR_##n
#define CHAN_TO_PORT(n) CHAN_PORT_##n
#define CHAN_TO_MASK(n) CHAN_MASK_##n
#define CHAN_TO_ENMASK(n) CHAN_ENMASK_##n
#define DIO_CHAN_ENB(n) ((CHAN_TO_ENB(n)) &= CHAN_TO_ENMASK(n))
#define DIO_CHAN_IN(n) ((CHAN_TO_DIR(n)) |= CHAN_TO_MASK(n))
#define DIO_CHAN_OUT(n) ((CHAN_TO_DIR(n)) &= ~CHAN_TO_MASK(n))
#define DIO_CHAN_READ(n) ((CHAN_TO_PORT(n)) &= CHAN_TO_MASK(n))
#define DIO_CHAN_HI(n) ((CHAN_TO_PORT(n)) |= CHAN_TO_MASK(n))
#define DIO_CHAN_LO(n) ((CHAN_TO_PORT(n)) &= ~CHAN_TO_MASK(n))
#define DIO_CHAN_WRITE(n, val) ((val) ? DIO_CHAN_HI(n) : DIO_CHAN_LO(n))