#include "../include/board.h"

board_t::board_t() {
    construct(0, 0, 500);
}

board_t::board_t(int height, int width, int speed) {
    construct(height, width, speed);
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

void board_t::add(drawable_t drawable) {
    add_at(drawable.get_y(), drawable.get_x(), drawable.get_icon());
}

chtype board_t::get_input() {
    return wgetch(board_window);
} 

void board_t::get_empty_coordinates(int& y, int& x) {
    while(mvwinch(board_window, y = rand() % height, x = rand() % width) != ' ');
}

void board_t::set_timeout(int timeout) {
    wtimeout(board_window, timeout);
}

chtype board_t::get_char_at(int y, int x) {
    return mvwinch(board_window, y, x);
}

int board_t::get_start_row() {
    return start_row;
}

int board_t::get_start_col() {
    return start_col;
}

void board_t::clear(){
    wclear(board_window);
    add_border();
}

void board_t::refresh() {
    wrefresh(board_window);
}

void board_t::construct(int height, int width, int speed) {
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

    start_row = (y_max/2) - (height / 2);
    start_col = (x_max/2) - (width / 2);
    board_window = newwin(height, width, start_row, start_col);
    this->height = height;
    this->width = width;

    set_timeout(speed);
    keypad(board_window, true);
}