#include <p18f4550.h>
#include <delays.h>
#include <string.h>
#include "dwengoDelay.h"
#include "dwengoBoard.h"
#include "servo.h"

#define HOEK0 12
#define HOEKN90 5
#define HOEK90 20


int timervlag = 0;
char state1 = 15;
char state2 = 15;
char state3 = 15;
char state4 = 15;

void initServo() {
    
    /* Initialisatie Timer */
    RCONbits.IPEN = 1; /* Interrupt priority enable bit */
    IPR1bits.TMR1IP = 0 ; 
    PIE1bits.TMR1IE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    RCONbits.SBOREN = 0;
    PIR1bits.TMR1IF = 0;

    //T1CONbits.RD16 = 0; /* 16 bit read/write mode uit */

    TMR1H = 0b11111111; /* zet timer overflow op 1/10 van 1ms*/
    TMR1L = 0b01101001; /* buffers voor timer: als die overflowt, vlag gaat op, 105 */
    T1CONbits.T1CKPS0 = 1;
    T1CONbits.T1CKPS1 = 1;
    
    /* Zetten servo-outputs */
    TRISBbits.RB4 = 0; /* als output maken */
    TRISBbits.RB5 = 0;
    TRISBbits.RB6 = 0;
    TRISBbits.RB7 = 0;
    LATBbits.LATB4 = 0;
    LATBbits.LATB5 = 0;
    LATBbits.LATB6 = 0;
    LATBbits.LATB7 = 0;

    /*Timer 1 aan*/
    T1CONbits.TMR1ON = 1;
    
    
}
void updateServo(void){
    timervlag++;
    if(timervlag==200){
        SERV1 = 1;
        SERV2 = 1;
        SERV3 = 1;
        SERV4 = 1;
        timervlag = 0;
    }

    if(timervlag >= state1) SERV1 = 0;
    if(timervlag >= state2) SERV2 = 0;
    if(timervlag >= state3) SERV3 = 0;
    if(timervlag >= state4) SERV4 = 0;
}

char servo1(int hoek){
    switch(hoek){
        case -90: state1 = HOEKN90;
        case 90: state1 = HOEK90;
        default: state2 = HOEK0;
    }

}

char servo2(int hoek){
    switch(hoek){
        case -90: state2 = HOEKN90;
        case 90: state2 = HOEK90;
        default: state2 = HOEK0;
    }
}

char servo3(int hoek){
    switch(hoek){
        case -90: state3 = HOEKN90;
        case 90: state3 = HOEK90;
        default: state3 = HOEK0;
    }
}

char servo4(int hoek){
    switch(hoek){
        case -90: state4 = HOEKN90;
        case 90: state4 = HOEK90;
        default: state4 = HOEK0;
    }
}