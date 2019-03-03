#include "Box.h"

bool InsideBox(int &x, int &y, Box &curBox) {
    return (curBox.x1 <= x && x <= curBox.x2 && curBox.y1 <= y && y <= curBox.y2) ;
}
