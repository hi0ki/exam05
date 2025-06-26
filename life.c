#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE '0'
#define DEAD ' '

typedef struct {
    int width, height, iterations;
    char grid[1096][1096];
} Life;

int main(int ac, char **av) {
    if(ac != 4) return 1;

    if(atoi(av[1]) <= 0 || atoi(av[2]) <= 0 || atoi(av[3]) <= 0)
        return 1;

    Life l = {
        .width = atoi(av[1]),
        .height = atoi(av[2]),
        .iterations = atoi(av[3]),
    };

    for(int i = 0; i < l.height; i++) {
        for(int j = 0; j < l.width; j++) {
            l.grid[i][j] = 0;
        }
    }

    int x = 0, y = 0, c = 0, pen_down = 0;

    ssize_t bytes = 0;
    while(1) {
        bytes = read(0, &c, 1);
        if(bytes <= 0) break;
        switch (c) {
            case 'w': y--; break;
            case 'a': x--; break;
            case 's': y++; break;
            case 'd': x++; break;
            case 'x': pen_down = !pen_down; break;
            default: break;
        }
        if(pen_down && x >= 0 && y >= 0)
            l.grid[y][x] = 1;
    }

    for(int i = 0; i < l.iterations; i++)
        l.evolves(l);

    for(int i = 0; i < l.height; i++) {
        for(int j = 0; j < l.width; j++)
            putchar(l.grid[i][j] ? ALIVE : DEAD);
        putchar('\n');
    }
}
