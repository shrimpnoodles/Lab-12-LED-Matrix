/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *	DEMO : https://drive.google.com/file/d/1bSb-PeV0yiGGGC1Dyhk5B40eNYKnUL7J/view?usp=sharing
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

unsigned char button;
unsigned char vert_button;
unsigned char horz_button;

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
	    	if(vert_button == 6 && horz_button == 3){
			PORTC = 0X3C;
			PORTD =0XD7;
		}
		else if(vert_button == 7 && horz_button == 3){
			PORTC = 0x3c;
			PORTD = 0xaf;
		}
		else if(vert_button == 8 && horz_button == 3){
			PORTC = 0X3C;
			PORTD = 0X5F;
		}
		else if(vert_button == 5 && horz_button == 3){
			PORTC = 0X3C;
			PORTD = 0XEB;
		}
		else if(vert_button == 4 && horz_button == 3){
			PORTC = 0X3C;
			PORTD = 0XF5;
		}
		else if(vert_button == 3 && horz_button == 3){
			PORTC = 0x3c;
			PORTD = 0XFA;
		}
		else if(vert_button == 6 && horz_button == 4){
			PORTC = 0X1e;
			PORTD =0XD7;
		}
		else if(vert_button == 7 && horz_button == 4){
			PORTC = 0x1e;
			PORTD = 0xaf;
		}
		else if(vert_button == 8 && horz_button == 4){
			PORTC = 0X1e;
			PORTD = 0X5F;
		}
		else if(vert_button == 5 && horz_button == 4){
			PORTC = 0X1e;
			PORTD = 0XEB;
		}
		else if(vert_button == 4 && horz_button == 4){
			PORTC = 0X1e;
			PORTD = 0XF5;
		}
		else if(vert_button == 3 && horz_button == 4){
			PORTC = 0x1e;
			PORTD = 0XFA;
		}
		else if(vert_button == 6 && horz_button == 5){
			PORTC = 0X0f;
			PORTD =0XD7;
		}
		else if(vert_button == 7 && horz_button == 5){
			PORTC = 0x0f;
			PORTD = 0xaf;
		}
		else if(vert_button == 8 && horz_button == 5){
			PORTC = 0X0f;
			PORTD = 0X5F;
		}
		else if(vert_button == 5 && horz_button == 5){
			PORTC = 0X0f;
			PORTD = 0XEB;
		}
		else if(vert_button == 4 && horz_button == 5){
			PORTC = 0X0f;
			PORTD = 0XF5;
		}
		else if(vert_button == 3 && horz_button == 5){
			PORTC = 0x0f;
			PORTD = 0XFA;
		}
		else if(vert_button == 6 && horz_button == 2){
			PORTC = 0X78;
			PORTD =0XD7;
		}
		else if(vert_button == 7 && horz_button == 2){
			PORTC = 0x78;
			PORTD = 0xaf;
		}
		else if(vert_button == 8 && horz_button == 2){
			PORTC = 0X78;
			PORTD = 0X5F;
		}
		else if(vert_button == 5 && horz_button == 2){
			PORTC = 0X78;
			PORTD = 0XEB;
		}
		else if(vert_button == 4 && horz_button == 2){
			PORTC = 0X78;
			PORTD = 0XF5;
		}
		else if(vert_button == 3 && horz_button == 2){
			PORTC = 0x78;
			PORTD = 0XFA;
		}
		else if(vert_button == 6 && horz_button == 1){
			PORTC = 0Xf0;
			PORTD =0XD7;
		}
		else if(vert_button == 7 && horz_button == 1){
			PORTC = 0xf0;
			PORTD = 0xaf;
		}
		else if(vert_button == 8 && horz_button == 1){
			PORTC = 0Xf0;
			PORTD = 0X5F;
		}
		else if(vert_button == 5 && horz_button == 1){
			PORTC = 0Xf0;
			PORTD = 0XEB;
		}
		else if(vert_button == 4 && horz_button == 1){
			PORTC = 0Xf0;
			PORTD = 0XF5;
		}
		else if(vert_button == 3 && horz_button == 1){
			PORTC = 0xf0;
			PORTD = 0XFA;
		}


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

		//	PORTC = 0X24;
		//	PORTD = 0XEF;
		if(vert_button == 6 && horz_button == 3){
			PORTC = 0X24;
			PORTD =0Xef;
		}
		else if(vert_button == 7 && horz_button == 3){
			PORTC = 0x24;
			PORTD = 0xdf;
		}
		else if(vert_button == 8 && horz_button == 3){
			PORTC = 0X24;
			PORTD = 0XbF;
		}
		else if(vert_button == 5 && horz_button == 3){
			PORTC = 0X24;
			PORTD = 0Xf7;
		}
		else if(vert_button == 4 && horz_button == 3){
			PORTC = 0X24;
			PORTD = 0Xfb;
		}
		else if(vert_button == 3 && horz_button == 3){
			PORTC = 0x24;
			PORTD = 0XFD;
		}
		else if(vert_button == 6 && horz_button == 4){
			PORTC = 0x12;
			PORTD =0Xef;
		}
		else if(vert_button == 7 && horz_button == 4){
			PORTC = 0x12;
			PORTD = 0xdf;
		}
		else if(vert_button == 8 && horz_button == 4){
			PORTC = 0X12;
			PORTD = 0Xbf;
		}
		else if(vert_button == 5 && horz_button == 4){
			PORTC = 0X12;
			PORTD = 0xf7;
		}
		else if(vert_button == 4 && horz_button == 4){
			PORTC = 0X12;
			PORTD = 0Xfb;
		}
		else if(vert_button == 3 && horz_button == 4){
			PORTC = 0x12;
			PORTD = 0Xfd;
		}
		else if(vert_button == 6 && horz_button == 5){
			PORTC = 0X09;
			PORTD =0Xef;
		}
		else if(vert_button == 7 && horz_button == 5){
			PORTC = 0x09;
			PORTD = 0xdf;
		}
		else if(vert_button == 8 && horz_button == 5){
			PORTC = 0X09;
			PORTD = 0Xbf;
		}
		else if(vert_button == 5 && horz_button == 5){
			PORTC = 0X09;
			PORTD = 0Xf7;
		}
		else if(vert_button == 4 && horz_button == 5){
			PORTC = 0X09;
			PORTD = 0Xfb;
		}
		else if(vert_button == 3 && horz_button == 5){
			PORTC = 0x09;
			PORTD = 0Xfd;
		}
		else if(vert_button == 6 && horz_button == 2){
			PORTC = 0X48;
			PORTD =0Xef;
		}
		else if(vert_button == 7 && horz_button == 2){
			PORTC = 0x48;
			PORTD = 0xdf;
		}
		else if(vert_button == 8 && horz_button == 2){
			PORTC = 0X48;
			PORTD = 0Xbf;
		}
		else if(vert_button == 5 && horz_button == 2){
			PORTC = 0X48;
			PORTD = 0Xf7;
		}
		else if(vert_button == 4 && horz_button == 2){
			PORTC = 0X48;
			PORTD = 0Xfb;
		}
		else if(vert_button == 3 && horz_button == 2){
			PORTC = 0x48;
			PORTD = 0Xfd;
		}
		else if(vert_button == 6 && horz_button == 1){
			PORTC = 0X90;
			PORTD =0Xef;
		}
		else if(vert_button == 7 && horz_button == 1){
			PORTC = 0x90;
			PORTD = 0xdf;
		}
		else if(vert_button == 8 && horz_button == 1){
			PORTC = 0X90;
			PORTD = 0Xbf;
		}
		else if(vert_button == 5 && horz_button == 1){
			PORTC = 0X90;
			PORTD = 0Xf7;
		}
		else if(vert_button == 4 && horz_button == 1){
			PORTC = 0X90;
			PORTD = 0Xfb;
		}
		else if(vert_button == 3 && horz_button == 1){
			PORTC = 0x90;
			PORTD = 0Xfd;
		}
		break;
		default:
			break;
	}
	return state;
}

enum button_States{presses};

int button_Tick(int state){
	switch(state){
		case presses:
		/*	if(button == 0x01){
				state = waitPress;
			}
			else if(button == 0x02){
				state = waitPress;
			}
			else if(button == 0x04){
				state = waitPress;
			}
			else if(button == 0x08){
				state = waitPress;
			}*/

			break;
	/*	case waitPress:
			if(button == 0x00){
				state = presses;
			}
			break;*/
		default:
			state = presses;
			break;
	}
	switch(state){
		case presses:
			if(button == 0x01){
				if(vert_button <8){
				vert_button++;
				}
			}
			else if(button == 0x02){
				if(vert_button > 3){
				vert_button--;
				}
			}
			else if(button == 0x04){
				if(horz_button >1){
				horz_button--;
				}
			}
			else if(button == 0x08){
				if(horz_button < 5){
				horz_button++;
				}
			}
			break;
	//	case waitPress:
	//		break;
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
	button = 0x00;
	vert_button = 6;
	horz_button = 3;
	button = ~PINA;
	static task task1, task2, task3;//, task4;
	task *tasks[] = {&task1, &task2, &task3};//, &task4};
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

	task3.state = start;
	task3.period =10;
	task3.elapsedTime = task3.period;
	task3.TickFct = &button_Tick;

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
	    button = ~PINA;
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


