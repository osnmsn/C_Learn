#include "Render_engine.h"
#include "Input_engine.h"

int main() {
    initRender();
    while (1) {
        int key = getInput();
        if (key) {
            if (key == 'a') player_x--;
            if (key == 'd') player_x++;
        }
        draw(); // 刷新画面
    }
    return 0;
}
