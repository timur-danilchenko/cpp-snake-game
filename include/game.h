#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ncurses.h>
#include "board.h"
#include "drawable.h" 
#include "fruit.h"
#include "empty.h"
#include "snake.h"
#include "scoreboard.h"

class game_t {
public:
    game_t(int height, int width, int speed);
    void initialize();
    void process_input();
    void update_state();
    void redraw();
    bool is_over();
    int get_score();
    ~game_t();
private:
    board_t board;
    bool game_over;
    fruit_t* fruit;
    snake_t snake;
    scoreboard_t scoreboard;
    int score;

    void create_fruit();
    void handle_next_piece(snake_piece_t);
    void eat_fruit();
};

#endif