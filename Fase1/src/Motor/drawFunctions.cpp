#include "drawFunctions.hpp"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void draw::figure::drawTriangle(point p1, point p2, point p3) {

	glBegin(GL_TRIANGLES);

	glColor3ub(rand() % 255, rand() % 255, rand() % 255);

	//desenhar os 3 vertices do triangulo
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p3.x, p3.y, p3.z);

	glEnd();
}

// cria um ponto com as dadas coordenadas, e adiciona-lo à lista de pontos da figura
void draw::figure::addPoint(float a, float b, float c) {
	draw::point p;
	p.x = a;
	p.y = b;
	p.z = c;
	pontos.push_back(p);
}

// recebe a lista de pontos, e o n�mero de pontos contidos na lista
void draw::figure::drawFigure() {
	int i;
	for (i = 0; i+2 < pontos.size(); i+=3) {
		//desenha os triangulos partindo da lista de pontos da figura
		drawTriangle(pontos[i], pontos[i + 1], pontos[i + 2]);
	}
}

void draw::figure::drawReferencial() {
	// Desenhar referencial
	glBegin(GL_LINES);
	
	// X axis in red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	
	// Y Axis in Green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	
	// Z Axis in Blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -100.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	
	glEnd();
}
