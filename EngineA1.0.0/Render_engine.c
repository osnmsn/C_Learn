// render_engine.c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Render_engine.h"

#define WIDTH  40
#define HEIGHT 20

int player_x = 5;//玩家的x方向定义

static char backbuf[HEIGHT][WIDTH + 1]; // 每行+1 存 '\0'

// 初始化渲染器
void initRender(void) {
    for (int y = 0; y < HEIGHT; y++) {
        backbuf[y][WIDTH] = '\0';
    }
}

// 清空缓冲区
static void renderer_clear(void) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            backbuf[y][x] = ' ';
        }
    }
}

// 写像素
static void renderer_put(int x, int y, char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        backbuf[y][x] = c;
    }
}

// 显示缓冲区
static void renderer_present(void) {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        puts(backbuf[y]);
    }
}

void draw(void) {
    static int t = 0;
    renderer_clear();

    // 边框
    for (int x = 0; x < WIDTH; x++) {
        renderer_put(x, 0, '#');
        renderer_put(x, HEIGHT - 1, '#');
    }
    for (int y = 0; y < HEIGHT; y++) {
        renderer_put(0, y, '#');
        renderer_put(WIDTH - 1, y, '#');
    }

    // 移动的 @
    int x = 2 + (t % (WIDTH - 4));
    renderer_put(x, HEIGHT / 2, '@');

    renderer_present();
    Sleep(50);
    t++;
}
