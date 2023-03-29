#include <ncurses.h>
#include "include/game.h"

#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main() {
    initscr();
    refresh();
    noecho();
    curs_set(0);
    
    game_t game(BOARD_ROWS, BOARD_COLS);

    while(!game.is_over()) {
        game.process_input();
        game.update_state();
        game.redraw();
    }

    getch();
    endwin();
    return 0;
}