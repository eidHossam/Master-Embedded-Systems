/*
 * io.h
 *
 * Created: 8/28/2023 8:44:43 PM
 *  Author: Hossam Eid
 */ 


#ifndef IO_H_
#define IO_H_

#define IO_BASE 0x20
#define SFIOR       *((volatile unsigned char *)(IO_BASE + 0x30))

/************************************************************************/
/*	                     PORTA Registers                                */
/************************************************************************/
#define PORTA       *((volatile unsigned char *)(IO_BASE + 0x1B))
#define DDRA        *((volatile unsigned char *)(IO_BASE + 0x1A))
#define PINA        *((volatile unsigned char *)(IO_BASE + 0x19))

/************************************************************************/
/*	                     PORTB Registers                                */
/************************************************************************/
#define PORTB       *((volatile unsigned char *)(IO_BASE + 0x18))
#define DDRB        *((volatile unsigned char *)(IO_BASE + 0x17))
#define PINB        *((volatile unsigned char *)(IO_BASE + 0x16))

/************************************************************************/
/*	                     PORTC Registers                                */
/************************************************************************/
#define PORTC       *((volatile unsigned char *)(IO_BASE + 0x15))
#define DDRC        *((volatile unsigned char *)(IO_BASE + 0x14))
#define PINC        *((volatile unsigned char *)(IO_BASE + 0x13))


/************************************************************************/
/*	                     PORTD Registers                                */
/************************************************************************/
#define PORTD       *((volatile unsigned char *)(IO_BASE + 0x12))
#define DDRD        *((volatile unsigned char *)(IO_BASE + 0x11))
#define PIND        *((volatile unsigned char *)(IO_BASE + 0x10))


/************************************************************************/
/*Pins                                                                  */
/************************************************************************/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#endif /* IO_H_ */