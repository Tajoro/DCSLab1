#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer

char Id[] = "315602938"; //Kfir's ID

enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  
  while(1){
	switch(state){
	  case state0: // sleep after clearing leds
	    /*for(int i = 0;i<10;i++){
	        printSWs2LEDs(Id());
	    }*/
		clrLEDs();      
        enterLPM(lpm_mode);
		break;
		 
	  case state1: // ID display
		disable_interrupts();
		printArr2LEDs(Id,9,LEDs_SHOW_RATE);
		//delay(LEDs_SHOW_RATE);	// delay of 62.5 [ms]
		enable_interrupts();
		break;
		 
	  case state2: // LED swing
		disable_interrupts();
		clrLEDs();
        incLEDs(0x001);
        for(int i = 0; i < 7; i++){ // shift left 7 times
            delay(LEDs_SHOW_RATE);				// delay of 62.5 [ms]
            shiftLEDsLeft();
        }
		for(int i = 0; i < 7; i++){ // shift left 7 times
            delay(LEDs_SHOW_RATE);				// delay of 62.5 [ms]
            shiftLEDsRight();

        }
		enable_interrupts();
		break;
		
	  case state3: // PWM 75% dutycycle
	    PWMPort ^= 0x80;
		delay(PWM_ON_RATE);
        PWMPort ^= 0x80;
        delay(PWM_OFF_RATE);
		break;


	}
  }
}
  
  
  
  
  
  
