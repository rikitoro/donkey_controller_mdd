#ifndef _SWITCH_DRIVER
#define _SWITCH_DRIVER

/**
 * スイッチ使用時の初期化
 */
extern void init_switch();

/**
 * スイッチSW7~0のパターンを取得する 
 * @return SW7~0のパターン
 */
extern char get_switch();

#endif // _SWITCH_DRIVER