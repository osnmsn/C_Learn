// Input_engine.c
#include <conio.h>
#include "Input_engine.h"

// 获取键盘输入，如果没有输入就返回 0
int getInput(void) {
    if (_kbhit()) {        // 判断有没有按键
        return _getch();   // 返回键的 ASCII 码
    }
    return 0;
}
