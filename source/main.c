/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
*/ 
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include "timer.h"
#include "scheduler.h"
#endif

//--------------------------------------
//--------------------------------------
//
//
unsigned char pc_temp;
unsigned char pd_temp;

enum rectangle1_States{ out_R1};

int rectangle1_Tick(int state){
	switch(state){
		case out_R1:
			break;
		default:
			state = out_R1;
			break;
		}
	switch(state){
		case out_R1:
		//	pd_temp = 0xdf;
		  //     pc_temp = 0x3c;
	    
			PORTC = 0X3C;
			PORTD =0XD7;
			break;
	 	default:
			break;
	}
	return state;
}

enum rectangle2_States{ out_R2};

int rectangle2_Tick(int state){
	switch(state){
		case out_R2:
			break;
		default:
			state = out_R2;
			break;
	}
	switch(state){
		case out_R2:
		//	pd_temp = 0xef;
		//	pc_temp = 0x24;

			PORTC = 0X24;
			PORTD = 0XEF;
			break;
		default:
			break;
	}
	return state;
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0Xff; PORTC = 0X00;
	DDRD = 0Xff; PORTD = 0X00;
    /* Insert your solution below */
	static task task1, task2;//, task3;//, task4;
	task *tasks[] = {&task1, &task2};//, &task3};//, &task4};
const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	const char start = -1;

	task1.state = start;
	task1.period = 1;
	task1.elapsedTime = task1.period;
	task1.TickFct = &rectangle1_Tick;

	task2.state = start;
	task2.period = 1;
	task2.elapsedTime = task2.period;
	task2.TickFct = &rectangle2_Tick;

/*	task3.state = start;
	task3.period =1;
	task3.elapsedTime = task3.period;
	task3.TickFct = &rectangle3_Tick;
*/
/*	task4.state = start;
	task4.period = 1;
	task4.elapsedTime = task4.period;
	task4.TickFct = &output_Tick;
*/
	unsigned long int findGCD(unsigned long int a, unsigned long int b){
		unsigned long int c;
		while(1){
			c = a%b;
			if (c==0){
				return b;
			}
			a = b;
			b = c;
		}
		return 0;
	}
	unsigned short i;
	unsigned long GCD = tasks[0]->period;
	for(i=1; i< numTasks; i++){
		GCD = findGCD(GCD, tasks[i]->period);
	}
	TimerSet(GCD);
	TimerOn();

    while (1) {
	for(i=0; i<numTasks; i++){
		if(tasks[i]->elapsedTime == tasks[i]->period){
			tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
			tasks[i]->elapsedTime = 0;
		}
		tasks[i]->elapsedTime += GCD;
	}
	while(!TimerFlag){};
	TimerFlag = 0;		

    }

//	PORTC = 0xff;
//	PORTD= 0xfe;
//	PORTC = 0XFF;
//	PORTD = 0X00;
    return 1;
}


