#include <p18f4550.h>
#include <delays.h>
#include <string.h>
#include "dwengoDelay.h"
#include "dwengoConfig.h"
#include "dwengoBoard.h"
#include "dwengoLCD.h"
#include "dc_motor.h"
#include "servo.h"
//#include "rotaties.h"


#define SERV1 LATBbits.LATB4
#define SERV2 LATBbits.LATB5
#define SERV3 LATBbits.LATB6
#define SERV4 LATBbits.LATB7

unsigned char state1;
unsigned char state2;
unsigned char state3;
unsigned char state4;
unsigned char vlag = 0;

 int timervlag = 0;
 
void YourHighPriorityISRCode();
void YourLowPriorityISRCode();
 
// interrupt handler routines DO NOT EDIT
#pragma code high_vector=0x08
void high_vector() {
	_asm
		goto YourHighPriorityISRCode
	_endasm
}
#pragma code

#pragma code low_vector=0x18
void low_vector() {
	_asm
		goto YourLowPriorityISRCode
	_endasm
}
#pragma code


// interrupt handler routines
#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode() {

}
 
#pragma interrupt YourLowPriorityISRCode
void YourLowPriorityISRCode() { 
	if(PIR1bits.TMR1IF==1){
        timervlag++;
        if(timervlag==200){
            SERV1 = 1;
            SERV2 = 1;
            SERV3 = 1;
            SERV4 = 1;
            timervlag = 0;
        }
        
        if(timervlag >= 4) SERV1 = 0;
        if(timervlag >= 23) SERV2 = 0;
        if(timervlag >= 17) SERV3 = 0;
        if(timervlag >= 15) SERV4 = 0;
        
        /*if(vlag==0){
            vlag = 1;
            SERV4 = 1;
        }
        else{
            vlag = 0;
            SERV4 = 0;
        }*/
        
        
        PIR1bits.TMR1IF = 0;
        TMR1H = 0b11111111;
        TMR1L = 0b01110001;  
    }
}





// main program
void main(void) {
    
   /* PR2 = 0b10000000;   periode */
    /*CCPR2L = 0b10000000; /* duty cycle*/
    /*TRISBbits.RB3 = 0; /* als output zetten*/
    /*TRISCbits.RC1 = 0;/* als output zetten */
    /*CCP2CONbits.DC2B1 = 0; /* Duty cycle LSBs */
    /*CCP2CONbits.DC2B0 = 0; /* Duty cycle LSBs */
    /*CCP2CONbits.CCP2M = 0b1100;/* instellen PWM als output*/
    /*T2CONbits.TMR2ON = 1; /* zet timer op voor PWM*/
    //while(0){
    //   delay_s(1);
     //  if(vlag==0){
    //       LATBbits.LATB3 = 1;
    //       CCPR2L = 0b00000000;
    //       vlag = 1;
    //   }
    //   else {
    //       LATBbits.LATB3 = 0;
    //       CCPR2L = 0b10000000;
    //       vlag = 0;
    //   }
    //}
    //CCPR2L = 0;
    //initPWM();
    //delay_s(1);
    //motor2(1,3); /* vooruit */
    //delay_s(2);
    //motor2(0,3); /*  achteruit/open */
  while(0){  motor1(1,3);
    delay_s(1);
    motor2(0,3);
    delay_s(1);
    motor2(1,3);
    delay_s(1);
    motor1(0,3);
    delay_s(1);
    
  }
    
    // servo proberen
    initServo();
    state1 = 100; /* begin altijd bij 1.5 ms*/
    state2 = 25; 
    state3 = 25; 
    state4 = 25;
    while(1){
        
    }
 }

