#include "Controller.h"
#include "timer_driver.h"


const int T_CONTROL = 100; // [ms]


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

/**
 * 1サイクル制御を行う
 * このメソッドは100ms周期で呼ばれる
 */
void C_doControl() {
	int targetValue;
	int value;
	int level;	
	// MortorSpeed クラスから目標値 targetValueを取得する
	targetValue = MS_getTargetValue();
	// MortorSpeed クラスから測定値 valueを取得する
	value = MS_getValue();
	// PControlMethodクラスに制御量を問い合わせる。
	level = PC_calcControlValue(targetValue,value,T_CONTROL);
	// MortorPwmクラスのPWMのlevelを更新する
	MP_setLevel(level);
}

