/**
 * @brief this file implements a simple bare-metal SW to toggle
 * an LED on the tivaC board.
 * 
 */

#define SYSCTL_RCGC2_R       (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DATA_R    (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R     (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R     (*((volatile unsigned long *)0x4002551c))


int main()
{
   volatile unsigned long delay,i;

   SYSCTL_RCGC2_R   |= 0x20;
   delay             = SYSCTL_RCGC2_R;
   GPIO_PORTF_DIR_R |= (1 << 3);
   GPIO_PORTF_DEN_R |= (1 << 3);
   
   while (1)
   {
   		GPIO_PORTF_DATA_R |= (1 << 3);
   		for(i = 0; i < 500000; i++);
   		GPIO_PORTF_DATA_R &= ~(1 << 3);
   		for(i = 0; i < 500000; i++);
   }
   return 0;
}
