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

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
/* Channel naming ( use the same names as the chip manual for easily
check the hardware) */

#include <iob32.h>
 
/* iob32.h is the register file of HC12 */

/*or link with mc9s12e128.c*/

/* Define bit masks for 8 bit registers */

typedef unsigned char UBYTE;

#define _B0_ (UBYTE) 0x01
 
/* B0 is the lsb of an 8 bit register*/

#define CHAN1 1 
/* Define CHAN1 as the 1st logical channel. User
can use either the logical channel number (1) or
physical channel symbol (CHAN1) to index a channel */

// Channel 1
#define CHAN_ENB_1 PORTS /* Dummy enable register*/
#define CHAN_DIR_1 DDRS /* Direction register of PS0*/
#define CHAN_PORT_1 PORTS /* PORTA is data register */
#define CHAN_MASK_1 _B0_/* The bit field of PS0 */
#define CHAN_ENMASK_1 0xFF
 
/* Dummy enable operator */
#define CHAN_TO_ENB(n)CHAN_ENB_##n
#define CHAN_TO_DIR(n) CHAN_DIR_##n
#define CHAN_TO_PORT(n) CHAN_PORT_##n
#define CHAN_TO_MASK(n) CHAN_MASK_##n
#define CHAN_TO_ENMASK(n) CHAN_ENMASK_##n
#define DIO_CHAN_ENB(n) ((CHAN_TO_ENB(n)) &= CHAN_TO_ENMASK(n))
#define DIO_CHAN_IN(n) ((CHAN_TO_DIR(n)) &=~CHAN_TO_MASK(n))
#define DIO_CHAN_OUT(n) ((CHAN_TO_DIR(n)) |=CHAN_TO_MASK(n))
#define DIO_CHAN_READ(n) ((CHAN_TO_PORT(n)) &= CHAN_TO_MASK(n))
#define DIO_CHAN_HI(n) ((CHAN_TO_PORT(n)) |= CHAN_TO_MASK(n))
#define DIO_CHAN_LO(n) ((CHAN_TO_PORT(n)) &= ~CHAN_TO_MASK(n))

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

