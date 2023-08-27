/*
 * Lab2_Atmega32.c
 *
 * Created: 8/28/2023 1:02:14 AM
 * Author : Hossam Eid
 */ 
#define F_CPU 8000000ul
#define IO_BASE     0x20
#define SFIOR       *((volatile unsigned char *)(IO_BASE + 0x30))

/*PortD Registers-------------------------------------------------*/
#define PORTD       *((volatile unsigned char *)(IO_BASE + 0x12))
#define DDRD        *((volatile unsigned char *)(IO_BASE + 0x11))
#define PIND        *((volatile unsigned char *)(IO_BASE + 0x10))


void GPIO_init(void);
void wait(int i);

int main(void)
{
    int pin = 5;
    GPIO_init();
    
    while (1) 
    {
        if(pin == 8)
            pin = 4;

        PORTD |= (1 << pin);
        wait(1);
        PORTD &= ~(1 << pin++);
    }
}

/*Set PD4 : 7 as output pins*/
void GPIO_init(void)
{
    DDRD |= (0b1111 << 4);
}

void wait(int i)
{
    volatile int j, k;
    for(j=0; j < i; j++)
        for(k = 0; k < 25000; k++);
}