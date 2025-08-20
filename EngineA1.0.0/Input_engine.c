// Input_engine.c
#include <conio.h>
#include "Input_engine.h"

int getInput(void) {
    if (_kbhit()) {
        return _getch();  // 返回按下的键
    }
    return 0; // 没有按键
}
