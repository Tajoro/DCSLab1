#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer

char Id = 208516039;

enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  
  while(1){
	switch(state){
	  case state0:
	    for(int i = 0;i<10;i++){
	        printSWs2LEDs(Id());
	    }

        enterLPM(lpm_mode);
		break;
		 
	  case state1:
		disable_interrupts();
		printArr2SWs(Id);
		//delay(LEDs_SHOW_RATE);	// delay of 62.5 [ms]
		enable_interrupts();
		break;
		 
	  case state2:
		disable_interrupts();
		clrLEDs();
        incLEDs(0x001);
        for(int i = 0; i < 200; i++){
            delay(LEDs_SHOW_RATE);				// delay of 62.5 [ms]
            shiftLEDs();
        }
		enable_interrupts();
		break;
		
	  case state3:
	      disable_interrupts();


	}
  }
}
  
  
  
  
  
  
