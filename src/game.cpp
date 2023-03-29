#include "../include/game.h"

game_t::game_t(int height, int width) {
    board = board_t(height, width);
    initialize();
}

void game_t::initialize() {
    board.initialize();
    game_over = false;
    fruit = NULL;
    srand(time(NULL));

    snake_piece_t next = snake_piece_t(1, 1);
    board.add(next);
    snake.add_piece(next);

    next = snake.next_head();
    board.add(next);
    snake.add_piece(next);
    
    next = snake.next_head();
    board.add(next);
    snake.add_piece(next);
}

void game_t::process_input() {
    chtype input = board.get_input();

    switch (input)
    {
    case KEY_UP:
    case 'w':
        snake.set_direction(up);
        break;
    case KEY_DOWN:
    case 's':
        snake.set_direction(down);
        break;
    case KEY_LEFT:
    case 'a':
        snake.set_direction(left);
        break;
    case KEY_RIGHT:
    case 'd':
        snake.set_direction(right);
        break;
    case 'p':
        while(board.get_input() != 'p');
        break;
    }
}

void game_t::update_state() {
    if(!fruit) {
        int y, x;
        board.get_empty_coordinates(y, x);
        fruit = new fruit_t(y, x);
        board.add(*fruit);
    }
    snake_piece_t next = snake.next_head();
    if(next.get_y() != fruit->get_y() && next.get_x() != fruit->get_x()) {
        int empty_row = snake.tail().get_y();
        int empty_col = snake.tail().get_x();
        board.add(empty_t(empty_row, empty_col));
        snake.remove_piece();
    }
    board.add(next);
    snake.add_piece(next);
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