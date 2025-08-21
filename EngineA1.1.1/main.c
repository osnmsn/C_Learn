#include "Render_engine.h"
#include "UI_engine.h"
#include "Input_engine.h"
//神秘小代码：chcp 65001 && cl /utf-8 /Zi /EHsc /nologo main.c Input_engine.c Render_engine.c UI_engine.c /Fe:game.exe && game.exe

int HP = 100;

int main() {
    initRender();

    while (1) {
        int key = getInput();

        if (key == 'a' || key == 'A') movePlayer(-1, 0);
        if (key == 'd' || key == 'D') movePlayer(1, 0);
        if (key == 'w' || key == 'W') movePlayer(0, -1);
        if (key == 's' || key == 'S') movePlayer(0, 1);

        draw();          // 画地图+玩家
        drawUI(HP);      // 单独画UI
    }

    return 0;
}
