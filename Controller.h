/*
 * Controller.h
 * Controller�N���X
 *
 * �N���X��: Controller(C)
 * ����:
 * ����: 
 * �֘A: RotationSpeed(RS), PCcontrolMethod(PC
 */

#ifndef _CONTROLLER
#define _CONTROLLER

#include "MotorSpeed.h"
#include "MotorPwm.h"
#include "PControlMethod.h"

// ������
extern void C_init();

/**
 * �ڕW��]���x��ݒ肷��
 * @param target �ڕW��]���x [rps]
 */
extern void C_setTargetValue(int target);

/**
 * �ڕW��]���x���擾����
 * @return �ڕW��]���x [rps]
 */
extern int C_getTargetValue(void);

/**
 * 1�T�C�N��������s�� 
 */
extern void C_doControl();


/**
 * ������J�n����
 */
extern void C_start();

/**
 * ������~����
 */
extern void C_stop();


#endif // _CONTROLLER