/*
 * Controller.h
 * Controllerクラス
 *
 * クラス名: Controller(C)
 * 属性:
 * 操作: 
 * 関連: RotationSpeed(RS), PCcontrolMethod(PC
 */

#ifndef _CONTROLLER
#define _CONTROLLER

#include "MotorSpeed.h"
#include "MotorPwm.h"
#include "PControlMethod.h"

// 初期化
extern void C_init();

/**
 * 目標回転速度を設定する
 * @param target 目標回転速度 [rps]
 */
extern void C_setTargetValue(int target);

/**
 * 目標回転速度を取得する
 * @return 目標回転速度 [rps]
 */
extern int C_getTargetValue(void);

/**
 * 1サイクル制御を行う 
 */
extern void C_doControl();


/**
 * 制御を開始する
 */
extern void C_start();

/**
 * 制御を停止する
 */
extern void C_stop();


#endif // _CONTROLLER