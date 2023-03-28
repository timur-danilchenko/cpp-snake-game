#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <ncurses.h>
#include "drawable.h"

class board_t{
public:
    board_t();
    board_t(int height, int width);

    void initialize();
    
    void add_border();
    void add_at(int y, int x, chtype c);
    void add(drawable_t drawable);

    chtype get_input();

    void clear();
    void refresh(); // a.k.a. update
private:
    WINDOW* board_window;

    void construct(int height, int width);
};

#endif