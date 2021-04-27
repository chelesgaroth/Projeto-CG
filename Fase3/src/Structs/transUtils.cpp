#include "transUtils.hpp"

using namespace transUtils;


void transform::setTransform() {
    x = 0;
    y = 0;
    z = 0;
    angle = 0;
    type = transtype::none;
}

void transform::setTransform(float xr, float yr, float zr, float ar, transtype t) {
    x = xr;
    y = yr;
    z = zr;
    angle = ar;
    type = t;
}

float transform::getX() {
    return x;
}
float transform::getY() {
    return y;
}
float transform::getZ() {
    return z;
}
float transform::getAngle() {
    return angle;
}
transtype transform::getType() {
    return type;
}

float transfTime::getX() {
    return x;
}
float transfTime::getY() {
    return y;
}
float transfTime::getZ() {
    return z;
}
transtype transfTime::getType() {
    return type;
}
std::vector<utils::point> transfTime::getPoints() {
    return points;
}

void transfTime::setTransfTime() {
    x = 0;
    y = 0;
    z = 0;
    time = 0;
    type = transUtils::transtype::none;
    std::vector<utils::point> v;
    points = v;
}

void transfTime::setTranslateTime(transtype t, int time, std::vector<utils::point> p) {

    time = time;
    type = t;
    points = p;
}

void transfTime::setRotateTime(transtype t, int time, float xr, float yr, float zr) {
    x = xr;
    y = yr;
    z = zr;
    time = time;
    type = t;
}