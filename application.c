#include "sfr29.h"
	
#include "init_devices.h"
#include "utility.h"
#include "led_driver.h"
#include "switch_driver.h"

#include "PControlMethod.h"
#include "MotorSpeed.h"
#include "Controller.h"

void test_C();

void main() 
{
	init_devices();
	test_C();
}

void test_C() {
	
	// ��ᐧ��̃p�����[�^�ݒ�
	PC_setControlParameter(0.5);

	// Controller�̏�����
	C_init();
	
	// ���[�^��]���x�̖ڕW�l�ݒ�
	C_setTargetValue(0);
	
	// ����J�n
	C_start();
	
	while(1){ // 1000[ms]���ƂɃ��[�^��]���x�̖ڕW�l���X�V����
		C_setTargetValue(get_switch());
		set_led((char)MS_getValue());	
		wait_ms(1000);	
	}
}

