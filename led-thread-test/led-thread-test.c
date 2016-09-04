/*
 * Broadcom Proprietary and Confidential. Copyright 2016 Broadcom
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Broadcom Corporation.
 */

/** @file
 *
 * GPIO API Application
 *
 * This application demonstrates how to use the WICED GPIO API
 * to toggle LEDs and read button states
 *
 * Features demonstrated
 *  - GPIO API
 *
 */

#include "wiced.h"

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *               Static Function Declarations
 ******************************************************/

/******************************************************
 *               Variable Definitions
 ******************************************************/

/******************************************************
 *               Function Definitions
 ******************************************************/
void processLed1()
{
	const int led1Delay = 500;
	while(1)
	{
		wiced_gpio_output_high(WICED_LED1);
		wiced_rtos_delay_miliseconds( led1Delay );
		wiced_gpio_output_low(WICED_LED1);
		wiced_rtos_delay_miliseconds( led1Delay );
	}
}


void processLed2()
{
	const int led2Delay = 200;
	while(1)
	{
		wiced_gpio_output_high( WICED_LED1 );
		wiced_rtos_delay_miliseconds(led2Delay);
		wiced_gpio_output_low( WICED_LED1 );
		wiced_rtos_delay_miliseconds(led2Delay);
	}
}

void processAdc()
{
//    wiced_adc_init( THERMISTOR_ADC, 5 );

}

void application_start( )
{

    wiced_thread_t threadLed1;

    /* Initialise the WICED device */
    wiced_init();

    WPRINT_APP_INFO( ( "The LEDs are flashing. Holding a button will force the corresponding LED on\n" ) );

    wiced_rtos_create_thread(&threadLed1,10,"led1",processLed1,1024,NULL);


    while ( 1 )
    {
        wiced_rtos_delay_milliseconds( 250 );

    }

}
