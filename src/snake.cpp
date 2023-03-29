#include "../include/snake.h"

snake_piece_t::snake_piece_t(): drawable_t(0, 0, 'S') {}

snake_piece_t::snake_piece_t(int y, int x): drawable_t(y, x, 'S') {}

snake_t::snake_t(): direction(down) {}

snake_piece_t snake_t::head() {
    return pieces.back();
}

snake_piece_t snake_t::tail() {
    return pieces.front();
}

void snake_t::add_piece(snake_piece_t piece) {
    pieces.push(piece);    
}

void snake_t::remove_piece() {
    pieces.pop();
}

direction_e snake_t::get_direction() {
    return direction;
}

void snake_t::set_direction(direction_e direction) {
    this->direction = direction;
}

snake_piece_t snake_t::next_head() {
    int row = head().get_y();
    int col = head().get_x();

    switch (direction)
    {
    case up:
        --row;
        break;

    case down:
        ++row;
        break;

    case left:
        --col;
        break;

    case right:
        ++col;
        break;
    }

    return snake_piece_t(row, col);
}