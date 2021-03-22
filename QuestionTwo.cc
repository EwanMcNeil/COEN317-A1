//Assignment Two 
//Ewan McNeil 40021787
//Luca Tomassi 

/*
Question Two reqs
AXI time/counter connected to an ARM processor
frequency is 25 MHz

a) find the requiried configuration Mode and TCSR to generate a periodic signal with perdio of 10 ms
 count up config
	the mode should be gernate mode for the use case is a repetative interrupt


//TODO register values for TCSR


*/

#include "stdbool.h"
#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"
#include "xil_io.h"
#include "xil_execption.h"
#include "xtmrctr.h"
#include <iostream>

using namespace std;



int main(){
//only need one pointer, LEDs are on same channel
static XGpio GPIO_PTR_LED;    
XtmrCtr timerInstance;

int timerStatus


//device ID is found in the parameters header file
timerStatus = XtmrCtr_initalized(&GPIO_PTR_LED, XPAR_AXI_TIMER_0_DEVICE_ID);   
if(timerStatus != XST_SUCESSS){

    cout << "initalization of the Timer has FAILED" << endl;
    return -1;
}


//TODO set the maximum count up value, (not sure if the set values has to be set because it should be zero)
//set thr reset values for the timer
XtmrCtr_SetResetValue(&timerInstance,0 ,0 )



//Specifcications ask for a count up timer

XtmrCtr_SetOptions(&timerInstance,XPAR_AXI_TIMER_0_DEVICE_ID, XTC_COUNT_UP_OPTION);


//TODO check what the zero is for
XtmrCtr_Start(&timerInstance,0)
}



