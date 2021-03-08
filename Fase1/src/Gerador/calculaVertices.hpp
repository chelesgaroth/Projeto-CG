#ifndef PROJETOCG_CALCULAVERTICES_H
#define PROJETOCG_CALCULAVERTICES_H
#include <string>
#include <vector>

namespace calculaVertices {

    vector<point> plane(float x, float z, string ficheiro);
    vector<point> box(float x, float y, float z, int camadas, string ficheiro);
    vector<point> sphere(float raio, int stacks, int slices, string ficheiro);
    void cone(float raio, float altura, int slices, int stacks, string ficheiro);

}


#endif //PROJETOCG_CALCULAVERTICES_H
