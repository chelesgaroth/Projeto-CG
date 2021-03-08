#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "../tinyXML/tinyxml.h"


namespace draw {
    struct point {
        float x;
        float y;
        float z;
    };

    class figure {
        std::vector<point> pontos;
    private:
        void drawTriangle(point, point, point);
    public:
        void addPoint(float, float, float);
        void drawFigure();
        void drawReferencial();
    };
}