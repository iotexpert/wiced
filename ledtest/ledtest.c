#include "wiced.h"

#define MY_PIN ARD_GPIO_0

void application_start( )
{
    /* Initialize the WICED device */
    wiced_init();

    wiced_gpio_init(MY_PIN,OUTPUT_PUSH_PULL);

	const int ledDelay = 200;
	while(1)
	{
		wiced_gpio_output_high( MY_PIN );
		wiced_rtos_delay_miliseconds(ledDelay);
		wiced_gpio_output_low( MY_PIN );
		wiced_rtos_delay_miliseconds(ledDelay);
	}

}
