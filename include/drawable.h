#ifndef SNAKE_DRAWABLE_H
#define SNAKE_DRAWABLE_H

#include <ncurses.h>

class drawable_t {
public:
    drawable_t();
    drawable_t(int y, int x, chtype c);

    int get_x();
    int get_y();
    chtype get_icon();

protected:
    int y, x;
    chtype icon;
};

#endif