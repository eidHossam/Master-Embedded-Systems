/*
 * SPI_Master.c
 *
 * Created: 9/25/2023 4:16:14 PM
 * Author : Hossam Eid
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

/*SPI ports and pins configuration--------------------------------------*/
#define SPI_DIR_PORT		DDRB

#define SPI_SS_PIN			4
#define SPI_MOSI_PIN		5
#define SPI_MISO_PIN		6
#define SPI_SCK_PIN			7
/*----------------------------------------------------------------------------*/

/*-------SPI Control register pin macros---------------------------------*/
#define SPCR_SPE			(1 << 6)
#define SPCR_MSTR			(1 << 4)
#define SPCR_FCK_DIV_16		(1 << 0)
/*----------------------------------------------------------------------------*/

/*-------SPI Status register pin macros---------------------------------*/
#define SPSR_SPIF    (1 << 7)

void SPI_MasterInit(void);
void SPI_MasterTransmit(uint8_t data);
void MAX7221_Execute(uint8_t cmd, uint8_t data);
int main(void)
{
	uint8_t display_index, counter = 0;
	SPI_MasterInit();
	MAX7221_Execute(0x09, 0xFF);
	MAX7221_Execute(0x0A, 0xFF);
	MAX7221_Execute(0x0B, 0xF7);
	MAX7221_Execute(0x0C, 0x01);
	
    while (1) 
    {
		for(display_index = 1; display_index < 9;display_index++)
		{
			MAX7221_Execute(display_index, counter++);
		}
		_delay_ms(1000);	
    }
}

void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	SPI_DIR_PORT |= ((1 << SPI_MOSI_PIN) | (1 << SPI_SCK_PIN) | (1 << SPI_SS_PIN));
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= SPCR_MSTR;
	SPCR |= SPCR_FCK_DIV_16;
	SPCR |= SPCR_SPE;
}

void SPI_MasterTransmit(uint8_t data)
{
	SPDR = data;
	
	/*Wait until the transmission is completed*/
	while(!(SPSR & (1<<SPIF)));
}

void MAX7221_Execute(uint8_t cmd, uint8_t data)
{
	PORTB &= ~(1 << SPI_SS_PIN);
	SPI_MasterTransmit(cmd);
	
	SPI_MasterTransmit(data);
	PORTB |= (1 << SPI_SS_PIN);
	
}