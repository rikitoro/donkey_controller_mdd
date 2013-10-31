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
	
	// 比例制御のパラメータ設定
	PC_setControlParameter(0.5);

	// Controllerの初期化
	C_init();
	
	// モータ回転速度の目標値設定
	C_setTargetValue(0);
	
	// 制御開始
	C_start();
	
	while(1){ // 1000[ms]ごとにモータ回転速度の目標値を更新する
		C_setTargetValue(get_switch());
		set_led((char)MS_getValue());	
		wait_ms(1000);	
	}
}

