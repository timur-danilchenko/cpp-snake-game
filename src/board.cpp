#include "../include/board.h"

board_t::board_t() {
    construct(0, 0);
}

board_t::board_t(int height, int width) {
    construct(height, width);
}

void board_t::construct(int height, int width) {
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

    board_window = newwin(height, width, (y_max/2) - (height / 2), (x_max/2) - (width / 2));
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

void board_t::clear(){
    wclear(board_window);
    add_border();
}

void board_t::refresh() {
    wrefresh(board_window);
}