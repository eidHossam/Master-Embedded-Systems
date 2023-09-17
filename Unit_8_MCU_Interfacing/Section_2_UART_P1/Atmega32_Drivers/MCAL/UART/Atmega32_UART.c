/**
**************************************************************************************************************************
* brief     : This module contains functions for configuring and controlling the USART module.
* Author    : Hossam Eid
* Created on: 9/17/2023
**************************************************************************************************************************
*/
/*
===============================================
*                   Includes
*===============================================
*/
#include "Atmega32_UART.h"
#include "Atmega32.h"

/**************************************************************************************************************************
===============================================
*           APIs functions definitions
*===============================================
*/

/*
======================================================================================================================
* @Func_name	:   MCAL_USART_Init
* @brief		:   Initializes the USART module with a char size of 8 bits, no parity, one stop bit and 9600 baud-rate.
* @param [in]	:   none.
* @param [out]	:   none.
* @return_value :   none.
* Note			:   none.
======================================================================================================================
*/
void MCAL_USART_Init(void)
{
    /*Setting the baud-rate to be 9600*/
	UBRRL = 51;

    /*Setting the frame*/
    UCSRC = 0b10000110;   /*8bits character, no parity, 1 stop bit, asynch*/

    /*Enable the Tx and Rx*/
    SET_BIT(UCSRB, TXEN);  
    SET_BIT(UCSRB, RXEN);  
}

/*
======================================================================================================================
* @Func_name	:   MCAL_USART_Send_Char
* @brief		:   Send an 8 bit character through the USART.
* @param [in]	:   data: the 8 bit data to be sent.
* @param [out]	:   none.
* @return_value :   none.
* Note			:   none.
======================================================================================================================
*/
void MCAL_USART_Send_Char(uint8_t data)
{
    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) )
    ;
    /* Put data into buffer, sends the data */
    UDR = data;
}

/*
======================================================================================================================
* @Func_name	:   MCAL_USART_Get_Char
* @brief		:   Recives an 8 bit character from the USART.
* @param [in]	:   none.
* @param [out]	:   none.
* @return_value :   The data to be received.
* Note			:   none.
======================================================================================================================
*/
uint8_t MCAL_USART_Get_Char(void)
{
    /* Wait for data to be received */
    while ( !(UCSRA & (1<<RXC)) )
    ;
    /* Get and return received data from buffer */
    return (uint8_t)UDR;
}

/*
======================================================================================================================
* @Func_name	:   MCAL_USART_Send_String
* @brief		:   Sends a string through the USART.
* @param [in]	:   string to send.
* @param [out]	:   none.
* @return_value :   none.
* Note			:   none.
======================================================================================================================
*/
void MCAL_USART_Send_String(uint8_t* string)
{
    while(*string)
    {
        MCAL_USART_Send_Char(*string++);
    }
}

/*
======================================================================================================================
* @Func_name	:   MCAL_USART_Get_String
* @brief		:   Receives a string through the USART.
* @param [in]	:   buffer the buffer to store the string in.
* @param [in]	:   bufferSize: maximum length of the string to be received.
* @return_value :   none.
* Note			:   This function will receive characters until the end of the string or until the return carriage *               :   character is pressed.
======================================================================================================================
*/
void MCAL_USART_Get_String(uint8_t* buffer, uint8_t bufferSize)
{
    uint8_t count = 0, input;
    while(count < bufferSize - 1)
    {
        input = MCAL_USART_Get_Char();
        if(input == '\r')
        {
            break;
        }
        buffer[count++] = input; 
    }

    buffer[count] = '\0';
}

