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
 * 1�T�C�N��������s��
 * ���̃��\�b�h��100ms�����ŌĂ΂��
 */
void C_doControl() {
	int targetValue;
	int value;
	int level;	
	// MortorSpeed �N���X����ڕW�l targetValue���擾����
	targetValue = MS_getTargetValue();
	// MortorSpeed �N���X���瑪��l value���擾����
	value = MS_getValue();
	// PControlMethod�N���X�ɐ���ʂ�₢���킹��B
	level = PC_calcControlValue(targetValue,value,T_CONTROL);
	// MortorPwm�N���X��PWM��level���X�V����
	MP_setLevel(level);
}

