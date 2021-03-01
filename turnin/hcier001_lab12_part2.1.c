/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *	DEMO : https://drive.google.com/file/d/1HQ_FtGNljM2qZ5bmj4A9yJq3UJD2goC7/view?usp=sharing
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
// LED Matrix Demo SynchSM
// Period: 100 ms
//--------------------------------------
unsigned char button;
unsigned char row;
unsigned char pattern;

enum changeRow_States{start, middle, init, up, wait1, down, wait2} state;

void changeRow_Tick(){
	switch(state){
	case start:
		state = middle;
		break;
	case middle:
		state = init;
		break;
	case init:
		if(button == 0x01){
			state = up;
		}
		else if(button == 0x02){
			state = down;
		}
		break;
	case up:
		state = wait1;
		break;
	case wait1:
		if(button == 0x00){
			state = init;
		}
		break;
	case down:
		state = wait2;
		break;
	case wait2:
		if(button == 0x00){
			state = init;
		}
		break;
	default:
		state = start;
		break;
	}
	switch(state){
		case start:
			break;
		case middle:
			row = 0x00;
			pattern = 0x08;

			PORTD = row;
			PORTC = pattern;
			break;
		case init:
			break;
		case up:
			if(pattern == 0x01){
				pattern = 0x02;
			}
			else if(pattern == 0x02){
				pattern = 0x04;
			}
			else if(pattern == 0x04){
				pattern = 0x08;
			}
			else if(pattern == 0x08){
				pattern = 0x10;
			}
			else if(pattern == 0x10){
				pattern = 0x20;
			}
			else if(pattern == 0x20){
				pattern = 0x40;
			}
			else if(pattern == 0x40){
				pattern = 0x80;
			}
			PORTC = pattern;
			break;
		case wait1:
			break;
		case down:
			if(pattern == 0x80){
				pattern = 0x40;
			}
			else if(pattern == 0x40){
				pattern = 0x20;
			}
			else if(pattern == 0x20){
				pattern = 0x10;
			}
			else if(pattern == 0x10){
				pattern = 0x08;
			}
			else if(pattern == 0x08){
				pattern = 0x04;
			}
			else if(pattern == 0x04){
				pattern = 0x02;
			}
			else if(pattern == 0x02){
				pattern = 0x01;
			}
			PORTC = pattern;
			break;
		case wait2:
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0Xff; PORTC = 0X00;
	DDRD = 0Xff; PORTD = 0X00;
    /* Insert your solution below */
	button = 0x00;
	state = start;
/*	static task task1, task2;
	task *tasks[] = {&task1, &task2};
const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

	const char start = -1;

	task1.state = start;
	task1.period = 100;
	task1.elapsedTime = task1.period;
	task1.TickFct = &row_Tick;

	task2.state = start;
	task2.period = 100;
	task2.elapsedTime = task2.period;
	task2.TickFct = &output_Tick;

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

*/
    while (1) {
	 button = ~PINA;
	 changeRow_Tick();
/*	for(i=0; i<numTasks; i++){
		if(tasks[i]->elapsedTime == tasks[i]->period){
			tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
			tasks[i]->elapsedTime = 0;
		}
		tasks[i]->elapsedTime += GCD;
	}
	while(!TimerFlag){};
	TimerFlag = 0;
	*/

    }


//	PORTC = 0XFF;
//	PORTD = 0X00;
    return 1;
}


