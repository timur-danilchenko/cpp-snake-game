#include "../include/drawable.h"

drawable_t::drawable_t() {
    y = x = 0;
    icon = ' ';
}

drawable_t::drawable_t(int y, int x, chtype c): y(y), x(x), icon(c) {}

int drawable_t::get_x() {
    return x;
}

int drawable_t::get_y() {
    return y;
}

chtype drawable_t::get_icon() {
    return icon;
}