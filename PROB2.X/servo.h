/* 
 * File:   servo.h
 * Author: michiel
 *
 * Created on 2 maart 2016, 16:36
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif
    void initServo(void) ; 
    char servo1(int hoek);
    char servo2(int hoek);
    char servo3(int hoek); 
    char servo4(int hoek);
    



#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

