#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <ncurses.h>

class board_t{
public:
    board_t(int height, int width);

    void initialize();
    
    void add_border();
    void add_at(int y, int x, chtype c);

    chtype get_input();

    void clear();
    void refresh(); // a.k.a. update
private:
    WINDOW* board_window;
    int height, width;
};

#endif