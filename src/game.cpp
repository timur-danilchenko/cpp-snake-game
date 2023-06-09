#include "../include/game.h"

game_t::game_t(int height, int width, int speed) {
    board = board_t(height, width, speed);
    scoreboard = scoreboard_t(width, board.get_start_row() + height, board.get_start_col());
    initialize();
}

void game_t::initialize() {
    board.initialize();
    game_over = false;
    fruit = NULL;
    srand(time(NULL));
    score = 0;
    scoreboard.initialize(score);

    handle_next_piece(snake_piece_t(1, 1));
    handle_next_piece(snake.next_head());
    
    if(!fruit) {
        create_fruit();
    }
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
    handle_next_piece(snake.next_head());
    
    if(!fruit) {
        create_fruit();
    }
}

void game_t::redraw() {
    board.refresh();
    scoreboard.refresh();
}

bool game_t::is_over() {
    return game_over;
}

int game_t::get_score() {
    return score;
}

game_t::~game_t() {
    delete fruit;
}

void game_t::create_fruit() {
    int y, x;
    board.get_empty_coordinates(y, x);
    fruit = new fruit_t(y, x);
    board.add(*fruit);
}

void game_t::handle_next_piece(snake_piece_t next) {
    if (fruit) {
        switch (board.get_char_at(next.get_y(), next.get_x())) {
            case 'F': 
                eat_fruit();
                break;
            case ' ': {
                int empty_row = snake.tail().get_y();
                int empty_col = snake.tail().get_x();
                board.add(empty_t(empty_row, empty_col));
                snake.remove_piece();
                break;
            }
            default: 
                game_over = true;
                break;
        }
    }
    board.add(next);
    snake.add_piece(next);   
}

void game_t::eat_fruit() {
    delete fruit;
    fruit = nullptr;
    score += 1;
    scoreboard.update_score(score);
}