#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    size_t step = 100 * 1024 * 1024; // 每次分配 100MB
    size_t total = 0;
    char **blocks = NULL;
    size_t count = 0;

    while (1) {
        char *p = malloc(step);
        if (p == NULL) {
            printf("内存分配失败，总共分配了 %.2f GB\n", total / 1024.0 / 1024 / 1024);
            break;
        }
        for (size_t i = 0; i < step; i += 4096)
            p[i] = 0;
        total += step;
        blocks = realloc(blocks, sizeof(char *) * (count + 1));
        blocks[count++] = p;
        printf("已分配 %.2f GB\n", total / 1024.0 / 1024 / 1024);
        sleep(1);
    }

    // 释放内存
    for (size_t i = 0; i < count; i++)
        free(blocks[i]);
    free(blocks);

    return 0;
}
//你这扯不扯，写了个sz玩意出来
