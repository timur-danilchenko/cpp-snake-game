#include "../include/game.h"

game_t::game_t(int height, int width) {
    board = board_t(height, width);
    board.initialize();
    game_over = false;
    fruit = NULL;
    srand(time(NULL));
}

void game_t::process_input() {
    chtype input = board.get_input();
}

void game_t::update_state() {
    int y, x;
    board.get_empty_coordinates(y, x);
    if(fruit) {
        board.add(empty_t(fruit->get_y(), fruit->get_x()));
        delete fruit;
    }
    fruit = new fruit_t(y, x);
    board.add(*fruit);
}

void game_t::redraw() {
    board.refresh();
}

bool game_t::is_over() {
    return game_over;
}

game_t::~game_t() {
    delete fruit;
}