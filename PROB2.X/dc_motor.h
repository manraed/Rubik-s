/* 
 * File:   dc_motor.h
 * Author: michiel
 *
 * Created on 2 maart 2016, 13:54
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initPWM(void);
    void motor1(char richting, int tijd);
    void motor2(char richting, int tijd);


#ifdef	__cplusplus
}
#endif

#endif	/* DC_MOTOR_H */


