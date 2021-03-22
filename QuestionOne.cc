//Question one For COEN 317
//Ewan McNeil 40021787
//Luca Tomassi 

/*
Red -> connected to pin 0 channel 0
Green -> connected to pin 1 channel 0
Algo is

loop:
    Turn off Red, Turn on Green
    Delay for 1s
    Turn on Red, Turn off Green
    Delay for 1s
*/



#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"
#include "xil_io.h"
#include "xil_exception.h"
#include <iostream>
using namespace std;


#define DELAY_SECOND 10000
void delay();

int main()
{

//only need one pointer, LEDs are on same channel
static XGpio GPIO_PTR_LED;      
int ledStatus


//device ID is found in the parameters header file
ledStatus = XGpio_initalized(&GPIO_PTR_LED, XPAR_GPIO_DEVICE_ID);   
if(ledStatus != XST_SUCESSS){

    cout << "initalization of the LED GPIO has FAILED" << endl;
    return -1;
}


//setting one for output, and channel = 0
XGpio_setDataDirection(&GPIO_PTR_LED,1,0);


bool greenON[2] = {1,0};
bool redON[2] = {0,1};

while(true){

    XGpio_DiscreteWrite(&GPIO_PTR_LED,1,greenON);
    delay();
    XGpio_DiscreteWrite(&GPIO_PTR_LED,1,redON);
    delay();

}



}


//delay function is considered a subroutine that is called in multiple places
//so it has been defined outside of the main for reusablilty 
void delay(){

for (int delay = 0; delay <DELAY_SECOND; delay ++);

}