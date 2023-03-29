#include "../include/snake.h"

snake_piece_t::snake_piece_t(): drawable_t(0, 0, 'S') {}

snake_piece_t::snake_piece_t(int y, int x): drawable_t(y, x, 'S') {}

snake_t::snake_t(): direction(down) {}

snake_piece_t snake_t::head() {
    return pieces.front();
}

snake_piece_t snake_t::tail() {
    return pieces.back();
}

void snake_t::add_piece(snake_piece_t piece) {
    pieces.push(piece);    
}

void snake_t::remove_piece() {
    pieces.pop();
}