#include "point2.h"
#include <iostream>
#include <cstdlib>
#include <math.h>

using std::cout;
using std::endl;

Point2::Point2(float _x, float _y){
    x = _x;
    y = _y;
}

float Point2 :: DistanceBetween(Point2 _point2){
    float distance;
    float _x = abs(this -> x - _point2.x);
    float _y = abs(this -> y - _point2.y);
    distance = sqrt(_x*_x + _y * _y);
    return distance;
}

int Point2 :: Quadrant(){
    int quad;
    if (x > 0 && y >= 0){
        quad = 1;
    }else if (x <= 0 &&  y > 0){
        quad = 2;
    }else if (x < 0 && y <= 0){
        quad = 3;
    }else if (x >= 0 && y < 0){
        quad = 4;
    }else{
        quad = 0;
    }
    return quad;
}

void Point2 :: Print(){
    cout << "(" << x << ", " << y << ")" << endl;
}