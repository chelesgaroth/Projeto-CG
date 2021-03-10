#define _USE_MATH_DEFINES
#include <cmath>

#include "calculaVertices.hpp"

using namespace generate;


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


figure generate::createPlane(float x, float z) {

    figure f;

    float x1 = x / 2;
    float z1 = z / 2;

    //Triângulo 1
    f.addPoint(x1, 0, z1);
    f.addPoint(x1, 0, -z1);
    f.addPoint(-x1, 0, -z1);

    // Triângulo 2
    f.addPoint(-x1, 0, -z1);
    f.addPoint(-x1, 0, z1);
    f.addPoint(x1, 0, z1);

    return f;
}


figure generate::createBox(float x, float y, float z, int camadas) {
    figure f;

    float x1 = x / 2;
    float z1 = z / 2;
    float camadaX = camadas / x;
    float camadaY = camadas / y;
    float camadaZ = camadas / z;
    int i, j;

    // Desenhar a base
    float auxX = -x1;
    float auxZ = -z1;
    for (i = 0; i < camadas; i++) {
        for (j = 0; j < camadas; j++) {

            f.addPoint(auxX, 0, auxZ);
            f.addPoint(auxX + camadaX, 0, auxZ);
            f.addPoint(auxX + camadaX, 0, auxZ + camadaZ);

            f.addPoint(auxX + camadaX, 0, auxZ + camadaZ);
            f.addPoint(auxX, 0, auxZ + camadaZ);
            f.addPoint(auxX, 0, auxZ);

            auxZ += camadaZ;
        }
        auxX += camadaX;
    }

    // Desenhar o teto
    auxX = -x1;
    auxZ = -z1;
    float auxY = y;
    for (i = 0; i < camadas; i++) {
        for (j = 0; j < camadas; j++) {

            f.addPoint(auxX + camadaX, auxY, auxZ + camadaZ);
            f.addPoint(auxX + camadaX, auxY, auxZ);
            f.addPoint(auxX, auxY, auxZ);

            f.addPoint(auxX, auxY, auxZ);
            f.addPoint(auxX, auxY, auxZ + camadaZ);
            f.addPoint(auxX + camadaX, auxY, auxZ + camadaZ);

            auxZ += camadaZ;
        }
        auxX += camadaX;
    }

    // Desenhar o lado direito
    auxX = x1;
    auxZ = z1;
    auxY = y;
    for (i = 0; i < camadas; i++) {
        for (j = 0; j < camadas; j++) {

            f.addPoint(auxX, auxY, auxZ);
            f.addPoint(auxX, auxY - camadaY, auxZ);
            f.addPoint(auxX, auxY - camadaY, auxZ - camadaZ);

            f.addPoint(auxX, auxY - camadaY, auxZ - camadaZ);
            f.addPoint(auxX, auxY, auxZ - camadaZ);
            f.addPoint(auxX, auxY, auxZ);

            auxZ -= camadaZ;
        }
        auxY -= camadaY;
    }

    // Desenhar o lado esquerdo
    auxX = -x1;
    auxZ = -z1;
    auxY = y;
    for (i = 0; i < camadas; i++) {
        for (j = 0; j < camadas; j++) {

            f.addPoint(auxX, auxY, auxZ);
            f.addPoint(auxX, auxY - camadaY, auxZ);
            f.addPoint(auxX, auxY - camadaY, auxZ + camadaZ);

            f.addPoint(auxX, auxY - camadaY, auxZ + camadaZ);
            f.addPoint(auxX, auxY, auxZ + camadaZ);
            f.addPoint(auxX, auxY, auxZ);

            auxZ += camadaZ;
        }
        auxY -= camadaY;
    }

    // Desenhar frente
    auxX = -x1;
    auxZ = z1;
    auxY = y;
    for (i = 0; i < camadas; i++) {
        for (j = 0; j < camadas; j++) {

            f.addPoint(auxX, auxY, auxZ);
            f.addPoint(auxX, auxY - camadaY, auxZ);
            f.addPoint(auxX + camadaX, auxY - camadaY, auxZ);

            f.addPoint(auxX + camadaX, auxY - camadaY, auxZ);
            f.addPoint(auxX + camadaX, auxY, auxZ);
            f.addPoint(auxX, auxY, auxZ);

            auxX += camadaX;
        }
        auxY -= camadaY;
    }

    // Desenhar trás
    auxX = x1;
    auxZ = -z1;
    auxY = y;
    for (i = 0; i < camadas; i++) {
        for (j = 0; j < camadas; j++) {

            f.addPoint(auxX, auxY, auxZ);
            f.addPoint(auxX, auxY - camadaY, auxZ);
            f.addPoint(auxX - camadaX, auxY - camadaY, auxZ);

            f.addPoint(auxX - camadaX, auxY - camadaY, auxZ);
            f.addPoint(auxX - camadaX, auxY, auxZ);
            f.addPoint(auxX, auxY, auxZ);

            auxX -= camadaX;
        }
        auxY -= camadaY;
    }
    return f;
}

figure generate::createSphere(float raio, int stacks, int slices)
{
    figure f;

    float delta1 = M_PI / stacks;
    float delta2 = 2 * M_PI / slices;
    float angulo1, angulo2, temp, x, y, z;

    for (int i = 0; i < stacks; i++) {

        angulo1 = -M_PI / 2.0 + i * delta1;
        temp = raio * cos(angulo1);
        y = raio * sin(angulo1);

        for (int j = 0; j < slices; j++) {

            angulo2 = j * delta2;
            x = temp * sin(angulo2);
            z = temp * cos(angulo2);

            f.addPoint(x, y, z);
        }
    }
    return f;
}

figure generate::createCone(float radius, float height, int slices, int stacks) {
    figure f;

    float theta = 0;
    float nextTheta = 0;
    float delta = (2 * M_PI) / slices;
    float raio = radius / stacks;
    float alturas = height / stacks;
    int i, j;

    //fazer a circunferência da base
    for (i = 0; i < slices; i++) {

        nextTheta = theta + delta;

        f.addPoint(0, 0, 0);
        f.addPoint(radius * sin(nextTheta), 0, radius * cos(nextTheta));
        f.addPoint(radius * sin(theta), 0, cos(theta));

        theta = nextTheta;
    }

    // Fazer as laterais
    float r1 = radius;
    float r2 = radius - raio;
    float alt1 = 0;
    float alt2 = alturas;
    theta = 0;
    nextTheta = 0;

    for (i = 0; i < slices; i++) {

        nextTheta += delta;

        for (j = 0; j < stacks; j++) {

            f.addPoint(r1 * sin(nextTheta), alt1, r1 * cos(nextTheta));
            f.addPoint(r2 * sin(nextTheta), alt2, r2 * cos(nextTheta));
            f.addPoint(r1 * sin(theta), alt1, r1 * cos(theta));

            f.addPoint(r2 * sin(nextTheta), alt2, r2 * cos(nextTheta));
            f.addPoint(r2 * sin(theta), alt2, r2 * cos(theta));
            f.addPoint(r1 * sin(theta), alt1, r1 * cos(theta));

            r1 -= raio;
            r2 -= raio;
            alt1 += alturas;
            alt2 += alturas;
        }
        r1 = radius;
        r2 = radius - raio;
        alt1 = 0;
        alt2 = alturas;
        theta = nextTheta;
    }
    return f;
}