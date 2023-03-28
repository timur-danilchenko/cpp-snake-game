#include <ncurses.h>
#include "include/board.h"

#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main() {
    initscr();
    refresh();

    board_t board(BOARD_ROWS, BOARD_COLS);
    board.initialize();

    getch();
    endwin();
    return 0;
}