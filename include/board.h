#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <ncurses.h>

class board_t{
public:
    board_t(int height, int width);
private:
    WINDOW* board_window;
    int height, width;
};

#endif