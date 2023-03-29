#include <iostream>
#include <ncurses.h>
#include "include/game.h"

#define BOARD_DIM 13
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2
#define GAME_SPEED 500

int main() {
    initscr();
    refresh();
    noecho();
    curs_set(0);

    game_t game(BOARD_ROWS, BOARD_COLS, GAME_SPEED);

    while(!game.is_over()) {
        game.process_input();
        game.update_state();
        game.redraw();
    }

    endwin();

    std::cout << "Your total score: " << game.get_score() << "\n";
    return 0;
}