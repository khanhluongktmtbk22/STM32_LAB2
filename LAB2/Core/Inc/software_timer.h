/*
 * software_timer.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Acer
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define no_timer 10
extern int timer_flag[no_timer];

void setTimer(int index, int duration);
void runTimer(int index);

#endif /* INC_SOFTWARE_TIMER_H_ */
