#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <ncurses.h>
#include "drawable.h"
#include <time.h>
#include <stdlib.h>

class board_t{
public:
    board_t();
    board_t(int height, int width, int speed);

    void initialize();
    
    void add_border();
    void add_at(int y, int x, chtype c);
    void add(drawable_t drawable);

    chtype get_input();
    void get_empty_coordinates(int& y, int &x);
    void set_timeout(int timeout);
    chtype get_char_at(int y, int x); 
    int get_start_row();
    int get_start_col();

    void clear();
    void refresh(); // a.k.a. update
private:
    WINDOW* board_window;
    int height, width;
    int start_row, start_col;

    void construct(int height, int width, int speed);
};

#endif