/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
PWM1.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/**************************************************************************
Esta practica consiste en realizar un control PWM
para regular la luminosidad de un led
**************************************************************************/

#include <16F887.h>                          //Incluye el microcontrolador con el que se va a trabajar 
#use delay ( clock=20Mhz, crystal )          //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

unsigned int16 Duty = 0;                     //Variable para guardar el valor para PWM

void main ( void )
{
   setup_timer_2 (T2_DIV_BY_16, 254, 1);     //Configura Timer2, periodo ajustado a 342uS
   setup_ccp1 (CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L); //Configura el m�dulo CCP para uso del PWM

   while ( 1 ) {
      for ( Duty = 0; Duty < 255; Duty++ ) {
         set_pwm1_duty ( Duty );             //Asigna el valor del Duty al PWM
         delay_ms ( 5 );                     //Retardo de 5ms
      }
      
      for ( Duty = 255; Duty > 0; Duty-- ) { // Ciclo para disminuir el valor de la variable
         set_pwm1_duty ( Duty );             //Asigna el valor del Duty al PWM
         delay_ms ( 5 );                     // Retardo de 5ms
      }
   }
}