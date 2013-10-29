#include "Controller.h"
#include "timer_driver.h"


const int DeltaTime = 100; // [ms]


void C_init()
{
	set_timer_task(C_doControl);
}

void C_setTargetValue(int target)
{
	MS_setTargetValue(target);
}

int C_getTargetValue(void)
{
	return MS_getTargetValue();
}

void C_start()
{
	timer_start();
}

void C_stop()
{
	timer_stop();
}

void C_setControlParameter(float kp)
{
	PC_setControlParameter(kp);
}

void C_doControl() {
	MP_setLevel(PC_calcControlValue(MS_getTargetValue(),MS_getValue(),DeltaTime));
}


/*
void int_ta2()
{
	C_doControl();
}
*/