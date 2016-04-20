#include <p18f4550.h>
#include "kleurensensor.h"
#include "dwengoDelay.h"

void initColorSensor(){
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
}

void readIn(){
    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 1;
    
    /*rood*/
   /* LATAbits.LATA2 = 0; 
    LATAbits.LATA3 = 0;
    LATAbits.LATA0 = 0;
    LATAbits.LATA1 = 0;
    delay_s(2);*/
    
    /*blauw*/
   /* LATAbits.LATA3 = 1;
    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 1;
    delay_s(200);*/
    
    /*clear*/
    LATAbits.LATA2 = 1;
    LATAbits.LATA3 = 0;
    
    /*groen*/
  /*  LATAbits.LATA3 = 1;
    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 1;
    delay_ms(200);*/
}
