#include "../include/scoreboard.h"

scoreboard_t::scoreboard_t() {}

scoreboard_t::scoreboard_t(int width, int y, int x) {
    score_window = newwin(1, width, y, x);
}

void scoreboard_t::initialize(int initial_score) {
    clear();
    mvwprintw(score_window, 0, 0, "score: ");
    update_score(initial_score);
    refresh();
}

void scoreboard_t::update_score(int score) {
    mvwprintw(score_window, 0, score_window->_maxx - 10, "%11llu", (long long unsigned)score);
}

void scoreboard_t::clear() {
    wclear(score_window);
}

void scoreboard_t::refresh() {
    wrefresh(score_window);
}