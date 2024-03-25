/**
******************************************************************************
* @file           : main.c
* @author         : Hossam Eid
* @brief          : Main program body
******************************************************************************
*/

/** @defgroup 
  * @{
  */
int result = 0;
int operand1 = 7;
int operand2 = 3;
/**
  * @}
  */
int main(void)
{
	__asm("nop \n\t"
		  "nop\n\t"
		  "nop\n\t");

	__asm("add %[out], %[in1], %[in2]"
		  :[out] "=r" (result)       	/*The first column is the output registers*/
		  :[in1] "r" (operand1),		/*The second column is the input registers*/
		   [in2] "r" (operand2)
          : "r2");                      /*The last column is to reseve registers*/

	__asm("nop \n\t"
		  "nop\n\t"
		  "nop\n\t");

}

