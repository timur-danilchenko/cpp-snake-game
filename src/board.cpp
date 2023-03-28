#include "../include/board.h"

board_t::board_t(int height, int width) {
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    board_window = newwin(height, width, (yMax/2) - 10, (xMax/2) - 10);
    box(board_window, 0, 0);
    wrefresh(board_window);

    this->height = height;
    this->width = width;
}