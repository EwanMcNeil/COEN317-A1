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
#include "xil_exception.h"
#include "xtmrctr.h"
#include <iostream>

using namespace std;



int main(){

XtmrCtr timerInstancePointer;

u32* timer_register_ptr = (u32*)XPAR_TMRCTR_0_BASEADDR;


int timerStatus;
//device ID is found in the parameters header file
timerStatus = XtmrCtr_initalized(&GPIO_PTR_LED, XPAR_AXI_TIMER_0_DEVICE_ID);
if(timerStatus != XST_SUCESSS){

    cout << "initalization of the Timer has FAILED" << endl;
    return -1;
}

//CASC = 0
//ENALL = 0
//PWMA0 = 0
//TOINT = 0
//ENTO = 1 		//enable timer
//ENIT0 = 0 	//disable the interupt
//LOAD0 = 1 	//equals one to start and then needs to be deasserted
//ARHT = 1		//reload generate value or overwrite capture value
//CAPTO = 0
//GENT0 = 1
//UDTO = 0		//counting up equals zero
//MDTO = 0

//yeilds
//0000_1011_0100
//0B4



//then after the reset it is
//0000_1001_0100
//094


//reset values is
//FFFC2F71



//Writing the reset value to the TLRO
*(timer_register_ptr+1) = 0xFFFC2F71;


//write first config value to load value
*(timer_register_ptr) = 0x1B4;

//write second to start timer
*(timer_register_ptr) = 0x194;

	return 0;
}



