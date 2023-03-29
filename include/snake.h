#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <ncurses.h>
#include <queue>
#include "drawable.h"

enum direction_e{
    up, down, left, right,
};

class snake_piece_t: public drawable_t {
public:
    snake_piece_t();
    snake_piece_t(int y, int x);
};

class snake_t {
public: 
    snake_t();

    snake_piece_t head();
    snake_piece_t tail();

    void add_piece(snake_piece_t piece);
    void remove_piece();
    direction_e get_direction();
    void set_direction(direction_e direction);
    snake_piece_t next_head();
private:
    std::queue<snake_piece_t> pieces;
    direction_e direction;
};

#endif