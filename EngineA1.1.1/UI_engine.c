#include <stdio.h>
#include <windows.h>
#include "UI_engine.h"

void drawUI(int HP) {
    // 光标移动到画布下方，避免覆盖地图
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 22}; // 地图高度20，所以写在22行
    SetConsoleCursorPosition(hOut, pos);

    printf("HP: %d\n", HP);
}
