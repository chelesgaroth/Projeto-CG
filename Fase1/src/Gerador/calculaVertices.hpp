#include <cstdlib>
#include <vector>
#include <string>

#include "../Utils/utils.hpp"


namespace generate{

    utils::figure createPlane(float, float);
    utils::figure createBox(float, float, float, int);
    utils::figure createSphere(float, int, int);
    utils::figure createCone(float, float, int, int);
}