#ifndef OOP_POINT_H
#define OOP_POINT_H

#include <iostream>

struct point {
    double x, y;
    point (double  a,double b) { x = a, y = b;};
    point() = default;

};
//std::istream& operator >> (std::istream& is,point& p );
//std::ostream& operator << (std::ostream& os,const point& p);

std::istream& operator >> (std::istream& is,point& p ) {
    return  is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os,const point& p) {
    return os << p.x <<' '<< p.y;
}
#endif
