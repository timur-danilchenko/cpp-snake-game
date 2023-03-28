#include "../include/game.h"

game_t::game_t(int height, int width) {
    board = board_t(height, width);
    board.initialize();
    game_over = false;
}

void game_t::process_input() {
    chtype input = board.get_input();
}

void game_t::update_state() {

}

void game_t::redraw() {
    board.refresh();
}

bool game_t::is_over() {
    return game_over;
}