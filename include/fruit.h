#ifndef SNAKE_FRUIT_H
#define SNAKE_FRUIT_H

#include <ncurses.h>
#include "drawable.h"

class fruit_t : public drawable_t {
public:
    fruit_t(int y, int x);
};

#endif