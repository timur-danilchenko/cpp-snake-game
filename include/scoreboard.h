#ifndef SNAKE_SCOREBOARD_H
#define SNAKE_SCOREBOARD_H

#include <ncurses.h>

class scoreboard_t {
public:
    scoreboard_t();
    scoreboard_t(int width, int y, int x);
    void initialize(int initial_score);
    void update_score(int score);
    void clear();
    void refresh();
private:
    WINDOW* score_window;
};

#endif