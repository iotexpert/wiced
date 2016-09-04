#include "wiced.h"

void application_start( )
{


    /* Initialise the WICED device */
    wiced_init();

    WPRINT_APP_INFO( ( "Started WICED\n" ) );


    const wiced_i2c_device_t psoc4 = {
    		.port = WICED_I2C_2,
			.address = 0x08,
			.address_width = I2C_ADDRESS_WIDTH_7BIT,
			.speed_mode = I2C_STANDARD_SPEED_MODE
    };

    wiced_result_t result;

    result = wiced_i2c_init(&psoc4);

    if(result == WICED_SUCCESS)
    {
    	WPRINT_APP_INFO(("Initialized I2C successfully \n"));
    }
    else
    {
    	WPRINT_APP_INFO(("I2C Initialization Failed\n"));
    }

    /*
    if(wiced_i2c_probe_device(&psoc4,1) == WICED_TRUE)
    {
    	WPRINT_APP_INFO(("Found Device\n"));
    }
    else
    {
    	WPRINT_APP_INFO(("Device Probe Failed\n"));
    }

*/
    wiced_i2c_message_t msg;

    uint8_t tx_buffer[3];
    tx_buffer[0]= 0;
    tx_buffer[1] = 20;
    tx_buffer[2] = 100;


    msg.flags = 0;
    msg.retries = 1;
    msg.tx_buffer = 0;
    msg.tx_length = 0;
    msg.rx_buffer = &tx_buffer;
    msg.rx_length = 2;


    if(wiced_i2c_transfer(&psoc4,&msg,1) == WICED_SUCCESS)
    {
    	WPRINT_APP_INFO(("Read succeeded\n"));
    }
    else
    {
    	WPRINT_APP_INFO(("Read Failed\n"));

    }

    WPRINT_APP_INFO(("Value = %d\n",tx_buffer[0]));

/*
    msg.flags = 0;
    msg.retries = 1;
    msg.tx_buffer = (const void *)&tx_buffer;
    msg.tx_length = 3;
    msg.rx_buffer = NULL;
    msg.rx_length = 0;


    if(wiced_i2c_transfer(&psoc4,&msg,1) == WICED_SUCCESS)
    {
    	WPRINT_APP_INFO(("Write succeeded\n"));
    }
    else
    {
    	WPRINT_APP_INFO(("Write Failed\n"));

    }

*/
    while(1);

}
