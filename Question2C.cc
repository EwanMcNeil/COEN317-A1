

//count-down config. single pulse: 100ms

/* Configuration Explained 

Generate Mode -> MDT0 = 0
Count down configuration -> UDT0 = 1
Generate Out -> GENT0 = 1
Capture Trigger Timer -> CAPT0 = 0

//* setting the ARHT to 0, whilst retaining GENT0 to 1, will ensure a single pulse is generated 
Auto-Reload -> ARHT = 0
Load Timer -> LOAD0 = 1
Enable Interrupt -> ENIT0 = 0
Enable Timer -> ENT0 = 1

1) TCSR -> 0x0A6
2) TCSR -> 0x086

*/



int main()
{

//timer instance
    XTmrCtr TimerInstancePtr;
    int xStatus;



//pointer used to get access to the registers
u32* timer_pointer = (u32*)XPAR_TMRCTR__0_BASEADDR;


//initialize the timercounter

xStatus = XTmrCtr_Initialize(&TimerInstancePtr, XPAR_AXI_TIMER_0_DEVICE_ID);
if (xStatus != XST_SUCCESS)
{
    cout<<" timer init failed" << endl;
    return 0;
}
    
//reset value to TLR0
*(timer_pointer+1) = 0x26259E;

//generate mode, count down mode.
*(timer_pointer) = 0x0A6;

//deassert load 1.
*(timer_pointer) = 0x086;


return 0;

}