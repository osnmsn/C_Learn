#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

void initRender(void);
void draw(void);
void movePlayer(int dx, int dy);

extern int player_x;
extern int player_y;

#define WIDTH  40
#define HEIGHT 20

#endif
