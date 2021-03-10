#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


namespace utils
{
    struct point {
        float x;
        float y;
        float z;
    };

    class figure {

    public:
        void addPoint(float, float, float);
        std::vector<point> getVector();
        void setVector(std::vector<point>);

        std::vector<point> pontos;
    };
}