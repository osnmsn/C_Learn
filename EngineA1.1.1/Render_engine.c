#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Render_engine.h"

int player_x = 5;
int player_y = 10;

static char backbuf[HEIGHT][WIDTH + 1]; 

// 初始化
void initRender(void) {
    for (int y = 0; y < HEIGHT; y++) {
        backbuf[y][WIDTH] = '\0';
    }
}

static void renderer_clear(void) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            backbuf[y][x] = ' ';
        }
    }
}

static void renderer_put(int x, int y, char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        backbuf[y][x] = c;
    }
}

static void renderer_present(void) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(hOut, pos);

    for (int y = 0; y < HEIGHT; y++) {
        puts(backbuf[y]);
    }
}

// 绘制一帧
void draw(void) {
    static int t = 0;
    renderer_clear();

    // 绘制边框
for (int x = 0; x < WIDTH; x++) {
    renderer_put(x, 0, '-');              // 顶边
    renderer_put(x, HEIGHT - 1, '-');     // 底边
}
for (int y = 0; y < HEIGHT; y++) {
    renderer_put(0, y, '|');              // 左边
    renderer_put(WIDTH - 1, y, '|');      // 右边
}

    // 四个角替换
    renderer_put(0, 0, '/');                  // 左上
    renderer_put(WIDTH - 1, 0, '\\');         // 右上
    renderer_put(0, HEIGHT - 1, '\\');        // 左下
    renderer_put(WIDTH - 1, HEIGHT - 1, '/'); // 右下

    // 玩家
    renderer_put(player_x, player_y, '@');

    // 动画：闪烁的星星
    if ((t / 10) % 2 == 0) {
        renderer_put(WIDTH / 2, HEIGHT / 2, '*');
    }

    renderer_present();
    t++;
}

void movePlayer(int dx, int dy) {
    if (player_x + dx > 0 && player_x + dx < WIDTH - 1) {
        player_x += dx;
    }
    if (player_y + dy > 0 && player_y + dy < HEIGHT - 1) {
        player_y += dy;
    }
}
