#include <string>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

struct point {
    float x;
    float y;
    float z;
};

// Função que desenha o plano utilizando dois triângulos (6 pontos)
vector<point> plane(float x, float z) {

    vector <point> pontos;

    float x1 = x / 2;
    float z1 = z / 2;

    point p1,p2,p3,p4,p5,p6;

    //Triângulo 1

    p1.x = x1;
    p1.y = 0;
    p1.z = z1;

    p2.x = x1;
    p2.y = 0;
    p2.z = -z1;

    p3.x = -x1;
    p3.y = 0;
    p3.z = -z1;


    // Triângulo 2

    p4.x = -x1;
    p4.y = 0;
    p4.z = -z1;

    p5.x = -x1;
    p5.y = 0;
    p5.z = z1;

    p6.x = x1;
    p6.y = 0;
    p6.z = z1;

    pontos.push_back(p1);
    pontos.push_back(p2);
    pontos.push_back(p3);

    pontos.push_back(p4);
    pontos.push_back(p5);
    pontos.push_back(p6);

    return pontos;
}





// Função que desenha a box que pode ter camadas
vector<point> box(float x, float y, float z, int camadas) {
    vector<point> pontos;

    float x1 = x/2;
    float z1 = z/2;
    float camadaX = camadas / x;
    float camadaY = camadas / y;
    float camadaZ = camadas / z;

    // Pontos de um plano
    point p1;
    point p2;
    point p3;
    point p4;
    point p5;
    point p6;

    // Desenhar a base
    float auxX = -x1;
    float auxZ = -z1;
    for (int i = 0; i < camadas; i++) {
        for (int j = 0; j < camadas; j++) {

            p1.x = auxX;
            p1.y = 0;
            p1.z = auxZ;

            p2.x = auxX + camadaX;
            p2.y = 0;
            p2.z = auxZ;

            p3.x = auxX + camadaX;
            p3.y = 0;
            p3.z = auxZ + camadaZ;


            p4.x = auxX + camadaX;
            p4.y = 0;
            p4.z = auxZ + camadaZ;

            p5.x = auxX;
            p5.y = 0;
            p5.z = auxZ + camadaZ;

            p6.x = auxX;
            p6.y = 0;
            p6.z = auxZ;

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);

            auxZ += camadaZ;
        }
        auxX += camadaX;
    }


    // Desenhar o teto
    auxX = -x1;
    auxZ = -z1;
    float auxY = y;
    for (int i = 0; i < camadas; i++) {
        for (int j = 0; j < camadas; j++) {

            p1.x = auxX + camadaX;
            p1.y = auxY;
            p1.z = auxZ + camadaZ;

            p2.x = auxX + camadaX;
            p2.y = auxY;
            p2.z = auxZ;

            p3.x = auxX;
            p3.y = auxY;
            p3.z = auxZ;

            p4.x = auxX;
            p4.y = auxY;
            p4.z = auxZ;

            p5.x = auxX;
            p5.y = auxY;
            p5.z = auxZ + camadaZ;

            p6.x = auxX + camadaX;
            p6.y = auxY;
            p6.z = auxZ + camadaZ;

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);

            auxZ += camadaZ;
        }
        auxX += camadaX;
    }

    // Desenhar o lado direito
    auxX = x1;
    auxZ = z1;
    auxY = y;
    for (int i = 0; i < camadas; i++) {
        for (int j = 0; j < camadas; j++) {

            p1.x = auxX;
            p1.y = auxY;
            p1.z = auxZ;

            p2.x = auxX;
            p2.y = auxY - camadaY;
            p2.z = auxZ;

            p3.x = auxX;
            p3.y = auxY - camadaY;
            p3.z = auxZ - camadaZ;

            p4.x = auxX;
            p4.y = auxY - camadaY;
            p4.z = auxZ - camadaZ;

            p5.x = auxX;
            p5.y = auxY;
            p5.z = auxZ - camadaZ;

            p6.x = auxX;
            p6.y = auxY;
            p6.z = auxZ;

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);

            auxZ -= camadaZ;
        }
        auxY -= camadaY;
    }

    // Desenhar o lado esquerdo
    auxX = -x1;
    auxZ = -z1;
    auxY = y;
    for (int i = 0; i < camadas; i++) {
        for (int j = 0; j < camadas; j++) {

            p1.x = auxX;
            p1.y = auxY;
            p1.z = auxZ;

            p2.x = auxX;
            p2.y = auxY - camadaY;
            p2.z = auxZ;

            p3.x = auxX;
            p3.y = auxY - camadaY;
            p3.z = auxZ + camadaZ;

            p4.x = auxX;
            p4.y = auxY - camadaY;
            p4.z = auxZ + camadaZ;

            p5.x = auxX;
            p5.y = auxY;
            p5.z = auxZ + camadaZ;

            p6.x = auxX;
            p6.y = auxY;
            p6.z = auxZ;

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);

            auxZ += camadaZ;
        }
        auxY -= camadaY;
    }

    // Desenhar frente
    auxX = -x1;
    auxZ = z1;
    auxY = y;
    for (int i = 0; i < camadas; i++) {
        for (int j = 0; j < camadas; j++) {

            p1.x = auxX;
            p1.y = auxY;
            p1.z = auxZ;

            p2.x = auxX;
            p2.y = auxY - camadaY;
            p2.z = auxZ;

            p3.x = auxX + camadaX;
            p3.y = auxY - camadaY;
            p3.z = auxZ;

            p4.x = auxX + camadaX;
            p4.y = auxY - camadaY;
            p4.z = auxZ;

            p5.x = auxX + camadaX;
            p5.y = auxY;
            p5.z = auxZ;

            p6.x = auxX;
            p6.y = auxY;
            p6.z = auxZ;

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);

            auxX += camadaX;
        }
        auxY -= camadaY;
    }

    // Desenhar trás
    auxX = x1;
    auxZ = -z1;
    auxY = y;
    for (int i = 0; i < camadas; i++) {
        for (int j = 0; j < camadas; j++) {

            p1.x = auxX;
            p1.y = auxY;
            p1.z = auxZ;

            p2.x = auxX;
            p2.y = auxY - camadaY;
            p2.z = auxZ;

            p3.x = auxX - camadaX;
            p3.y = auxY - camadaY;
            p3.z = auxZ;

            p4.x = auxX - camadaX;
            p4.y = auxY - camadaY;
            p4.z = auxZ;

            p5.x = auxX - camadaX;
            p5.y = auxY;
            p5.z = auxZ;

            p6.x = auxX;
            p6.y = auxY;
            p6.z = auxZ;

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);

            auxX -= camadaX;
        }
        auxY -= camadaY;
    }

    return pontos;
}

vector<point> sphere(float raio, int stacks, int slices) {

    vector <point> pontos;

    float delta1 = M_PI / stacks ;
    float delta2 = 2*M_PI / slices;

    for (int i = 0; i < stacks; i++) {

        float angulo1 = -M_PI / 2.0 + i * delta1;
        float temp = raio * cos(angulo1);
        float y = raio * sin(angulo1);

        for (int j = 0; j < slices; j++) {

            float angulo2 = j * delta2;
            float x = temp * sin(angulo2);
            float z = temp * cos(angulo2);

            point p1;
            p1.x = x;
            p1.y = y;
            p1.z = z;
            pontos.push_back(p1);
        }
    }
    return pontos;
}


vector<point> cone(float radius, float height, int slices, int stacks) {
    vector<point> pontos;
    float theta = 0;
    float nextTheta = 0;
    float delta = (2 * M_PI) / slices;
    float raio = radius / stacks;
    float alturas = height / stacks;

    point p1;
    point p2;
    point p3;
    point p4;
    point p5;
    point p6;

    //fazer a circunferência da base

    for (int i = 0; i < slices; i++) {

        nextTheta = theta + delta;
        p1.x = 0;
        p1.y = 0;
        p1.z = 0;

        p2.x = radius * sin(nextTheta);
        p2.y = 0;
        p2.z = radius * cos(nextTheta);

        p3.x = radius * sin(theta);
        p3.y = 0;
        p3.z = radius * cos(theta);


        theta = nextTheta;
        pontos.push_back(p1);
        pontos.push_back(p2);
        pontos.push_back(p3);

    }

    // Fazer as laterais
    float r1 = radius;
    float r2 = radius - raio;
    float alt1 = 0;
    float alt2 = alturas;
    theta = 0;
    nextTheta = 0;

    for (int i = 0; i < slices; i++) {

        nextTheta += delta;

        for (int j = 0; j < stacks; j++) {

            p1.x = r1 * sin(nextTheta);
            p1.y = alt1;
            p1.z = r1 * cos(nextTheta);

            p2.x = r2 * sin(nextTheta);
            p2.y = alt2;
            p2.z = r2 * cos(nextTheta);

            p3.x = r1 * sin(theta);
            p3.y = alt1;
            p3.z = r1 * cos(theta);

            p4.x = r2 * sin(nextTheta);
            p4.y = alt2;
            p4.z = r2 * cos(nextTheta);

            p5.x = r2 * sin(theta);
            p5.y = alt2;
            p5.z = r2 * cos(theta);

            p6.x = r1 * sin(theta);
            p6.y = alt1;
            p6.z = r1 * cos(theta);

            r1 -= raio;
            r2 -= raio;
            alt1 += alturas;
            alt2 += alturas;
            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            pontos.push_back(p4);
            pontos.push_back(p5);
            pontos.push_back(p6);
        }
        r1 = radius;
        r2 = radius - raio;
        alt1 = 0;
        alt2 = alturas;
        theta = nextTheta;
    }
    return pontos;
}
