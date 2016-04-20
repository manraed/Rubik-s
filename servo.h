/* 
 * File:   servo.h
 * Author: michiel
 *
 * Created on 2 maart 2016, 16:36
 */


//#ifdef	__cplusplus
//extern "C" {
//#endif

#ifndef SERVO_H
#define	SERVO_H

#define SERV1 LATBbits.LATB4
#define SERV2 LATBbits.LATB5
#define SERV3 LATBbits.LATB6
#define SERV4 LATBbits.LATB7

    extern char state1;
    extern char state2;
    extern char state3;
    extern char state4;
    extern int  timervlag;

    void initServo(void);
    void updateServo(void);
    char servo1(int hoek);//TODO
    char servo2(int hoek);//TODO
    char servo3(int hoek);//TODO
    char servo4(int hoek);//TODO
    

#endif  /* SERVO_H */

//#ifdef	__cplusplus
//}
//#endif

