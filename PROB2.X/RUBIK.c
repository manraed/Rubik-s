#include <p18f4550.h>
#include <delays.h>
#include <string.h>
#include "dwengoDelay.h"
#include "dwengoConfig.h"
#include "dwengoBoard.h"
#include "dwengoLCD.h"
#include "dc_motor.h"




// main program
void main(void) {
    char vlag = 0;
   /* PR2 = 0b10000000;   periode */
    /*CCPR2L = 0b10000000; /* duty cycle*/
    /*TRISBbits.RB3 = 0; /* als output zetten*/
    /*TRISCbits.RC1 = 0;/* als output zetten */
    /*CCP2CONbits.DC2B1 = 0; /* Duty cycle LSBs */
    /*CCP2CONbits.DC2B0 = 0; /* Duty cycle LSBs */
    /*CCP2CONbits.CCP2M = 0b1100;/* instellen PWM als output*/
    /*T2CONbits.TMR2ON = 1; /* zet timer op voor PWM*/
    while(0){
       delay_s(1);
       if(vlag==0){
           LATBbits.LATB3 = 1;
           CCPR2L = 0b00000000;
           vlag = 1;
       }
       else {
           LATBbits.LATB3 = 0;
           CCPR2L = 0b10000000;
           vlag = 0;
       }
    }
    //CCPR2L = 0;
    initPWM();
    //delay_s(1);
    //motor2(1,3); /* vooruit */
    //delay_s(2);
    //motor2(0,3); /*  achteruit/open */
    motor1(1,3);
    delay_s(1);
    motor2(0,3);
    delay_s(1);
    motor2(1,3);
    delay_s(1);
    motor1(0,3);
    delay_s(1);
    
    
    
 }

