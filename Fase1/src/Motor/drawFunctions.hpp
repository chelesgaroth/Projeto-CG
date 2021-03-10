#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "../tinyXML/tinyxml.h"
#include "../Utils/utils.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


namespace draw {


    void drawTriangle(utils::point, utils::point, utils::point);
    void drawFigure(utils::figure);
    void drawReferencial();

}