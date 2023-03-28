#include "../include/board.h"

board_t::board_t(int height, int width) {
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

    board_window = newwin(height, width, (y_max/2) - (height / 2), (x_max/2) - (width / 2));
    this->height = height;
    this->width = width;
}

void board_t::initialize() {
    clear();
    refresh();
}

void board_t::add_border() {
    box(board_window, 0, 0);
}

void board_t::add_at(int y, int x, chtype c) {
    mvwaddch(board_window, y, x, c);
}

chtype board_t::get_input() {
    return wgetch(board_window);
} 

void board_t::clear(){
    wclear(board_window);
    add_border();
}

void board_t::refresh() {
    wrefresh(board_window);
}