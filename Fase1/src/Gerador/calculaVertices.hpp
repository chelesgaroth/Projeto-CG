#include <cstdlib>
#include <vector>
#include <string>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

namespace generate
{
    struct point {
        float x;
        float y;
        float z;
    };

    class figure {
        std::vector<point> pontos;

    public:
        void addPoint(float, float, float);
        std::vector<point> getVector();
        void setVector(std::vector<point>);
    };


    figure createPlane(float, float);
    figure createBox(float, float, float, int);
    figure createSphere(float, int, int);
    figure createCone(float, float, int, int);
}