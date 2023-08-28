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
/*	                     PORTD Registers                                */
/************************************************************************/
#define PORTD       *((volatile unsigned char *)(IO_BASE + 0x12))
#define DDRD        *((volatile unsigned char *)(IO_BASE + 0x11))
#define PIND        *((volatile unsigned char *)(IO_BASE + 0x10))

#endif /* IO_H_ */