/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.55
        Device            :  PIC18F25K42
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    char temp1, temp2, temp3;   //Set three variables to save the Default Values for the Table Pointer Values in the Non-Volatile Memory
    uint8_t temp4;              //Set a variable to store the Table Latch Value which contains the value read from the Device Information Area
  
    uint32_t DIAaddress = 0;    
    DIAaddress = 0x3f0026;      //Defines which Device Information Address the program reads, in this case 3f0026 is the location of "Temperature Indicator ADC reading at @ 90?C (low range setting)"
    
    __delay_ms(100);
    temp1 = TBLPTRU;            //Save Table Pointer Upper Default Value
    temp2 = TBLPTRH;            //Save Table Pointer High Default Value
    temp3 = TBLPTRL;            //Save Table Pointer Lower Default Value
      
    TBLPTR = DIAaddress;        //Set the Table Pointer Value to the DIA address you want to access

    NVMCON1bits.NVMREG = 0b11;  //Tells the Control Register for Memory Access that the program will be accessing the Device ID    
    asm( "TBLRD*" );            //Use the assembly code TBLRD to store read the value of the DIA address given and store it in the TABLAT register
    temp4 = TABLAT;             //Store the TABLAT register value
    
    //The enclosed step is only required if using printf to display the value read in the DIA address, if using UART you can skip//
    TBLPTRU = temp1;            //Return the default value of the Table Pointer Upper Default Value
    TBLPTRH = temp2;            //Return the default value of the Table Pointer High Default Value
    TBLPTRL = temp3;            //Return the default value of the Table Pointer Lower Default Value
    //***************************************************************************************************************************//
    
    printf( "The temp value is %u \n\r", temp4);    //Print the value of "Temperature Indicator ADC reading at @ 90?C (low range setting)"
    __delay_ms(100);

    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/
