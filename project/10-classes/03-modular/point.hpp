#ifndef POINT_CPP
#define POINT_CPP

struct Point {
    double x {};
    double y {};

    Point set_x(double x);

    Point set_y(double y);

    Point get_coords();
};

#endif
