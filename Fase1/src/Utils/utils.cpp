#define _USE_MATH_DEFINES
#include <cmath>

#include "utils.hpp"

using namespace utils;

// cria um ponto com as dadas coordenadas, e adiciona-o à lista de pontos da figura
void figure::addPoint(float a, float b, float c) {
    point p;
    p.x = a;
    p.y = b;
    p.z = c;
    pontos.push_back(p);
}

// retorna o vetor de pontos da figura
std::vector<point> figure::getVector() {
    return pontos;
}

// passa um vetor para a figura
void figure::setVector(std::vector<point> v) {
    pontos = v;
}