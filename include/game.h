#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ncurses.h>
#include "board.h"
#include "drawable.h" 
#include "fruit.h"
#include "empty.h"

class game_t {
public:
    game_t(int height, int width);
    void process_input();
    void update_state();
    void redraw();
    bool is_over();
    ~game_t();
private:
    board_t board;
    bool game_over;
    fruit_t* fruit;
};

#endif