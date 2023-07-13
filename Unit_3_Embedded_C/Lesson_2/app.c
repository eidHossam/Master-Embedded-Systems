#include "uart.h"

char string_buffer[100] = "Learn-in-depth: Hossam";
const char string_buffer2[100] = "Learn-in-depth: Hossam";

int main(void)
{
	uart_send_string(string_buffer);
	return 0;
}
