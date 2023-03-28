#ifndef SNAKE_EMPTY_H
#define SNAKE_EMPTY_H

#include <ncurses.h>
#include "drawable.h"

class empty_t : public drawable_t {
public:
    empty_t(int y, int x);
};

#endif