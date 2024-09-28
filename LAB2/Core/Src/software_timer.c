/*
 * software_timer.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Acer
 */

#include "software_timer.h"

int timer_counter[no_timer];
int timer_flag[no_timer];

void setTimer(int index, int duration){
	timer_counter[index] = duration;
	timer_flag[index] = 0;
}
void runTimer(int index){
	if(timer_counter[index] > 0){
		timer_counter[index]--;
		if(timer_counter[index] <= 0){
			timer_flag[index] = 1;
		}
	}
}
