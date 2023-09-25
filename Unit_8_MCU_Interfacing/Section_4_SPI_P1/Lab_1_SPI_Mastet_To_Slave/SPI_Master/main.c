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
uint8_t SPI_MasterTransmit(uint8_t data);

int main(void)
{
	SPI_MasterInit();
	
	/*Set 7-segment pins as output*/
	DDRA = 0xFF;
	uint8_t data;
		
    while (1) 
    {
		
		for(data = 0 ; data<=255 ; data++)
		{
			_delay_ms(1000);
			PORTA = SPI_MasterTransmit(data);
		}
    }
}

void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	SPI_DIR_PORT |= ((1 << SPI_MOSI_PIN) | (1 << SPI_SCK_PIN) | (1 << SPI_SS_PIN));
	SPI_DIR_PORT &= ~(1 << SPI_MISO_PIN);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= SPCR_MSTR;
	SPCR |= SPCR_FCK_DIV_16;
	SPCR |= SPCR_SPE;
}

uint8_t SPI_MasterTransmit(uint8_t data)
{
	SPDR = data;
	
	/*Wait until the transmission is completed*/
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}