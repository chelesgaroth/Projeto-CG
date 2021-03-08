#include "drawFunctions.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
		h = 1;
	// compute window's aspect ratio
	float ratio = w * 1.0f / h;
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Set the perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

draw::figure teste;

void renderScene(void)
{
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set camera
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	teste.drawReferencial();
	teste.drawFigure();

	// End of frame
	glutSwapBuffers();
}
/*
void lerFicheiroXML(string ficheiro) {

    TiXmlDocument f;
    TiXmlElement* root = f.RootElement();
    bool b = f.LoadFile(ficheiro.c_str());


    if (b) {
        for (TiXmlElement* elem = root->FirstChild()->ToElement(); elem!=NULL; elem = elem->NextSiblingElement()) {
            const char* ficheiro1 = elem->Attribute("file");

            fstream fs;
            fs.open(ficheiro1);

            if (fs.is_open()) {
                string line;
                float x1, y1, z1;

                while (getline(fs, line)) {
                    //ler linha do ficheiro e colocar valores nas respetivas variáveis
                    int  i = sscanf(line.c_str(), "%f %f %f\n", &x1, &y1, &z1);
                    point p;
                    p.x = x1;
                    p.y = y1;
                    p.z = z1;
                    pontos.push_back(p);
                }

                fs.close();
            }

            else {printf("ERROR OPENING FILE");}
        }

    }

    else printf("ERROR IN LOADING FILE XML");
}*/

int main(int argc, char** argv){
    if (argc != 1) {
        printf("ERROR IN THE NUMBER OF ARGUMENTS");

    }
    else {

        //lerFicheiroXML(argv[1]);
        // put GLUT init here
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(800, 800);
        glutCreateWindow("Motor");

        // inicializar valores de teste
        //1 base baixo
        teste.addPoint(1, -1, 1);
        teste.addPoint(-1, -1, 1);
        teste.addPoint(-1, -1, -1);

        //2 base baixo
        teste.addPoint(1, -1, 1);
        teste.addPoint(1, -1, -1);
        teste.addPoint(-1, -1, -1);

        //3 base cima
        teste.addPoint(1, 1, 1);
        teste.addPoint(-1, 1, 1);
        teste.addPoint(-1, 1, -1);

        //4 base cima
        teste.addPoint(1, 1, 1);
        teste.addPoint(1, 1, -1);
        teste.addPoint(-1, 1, -1);

        //5 frente
        teste.addPoint(1, -1, 1);
        teste.addPoint(1, 1, 1);
        teste.addPoint(-1, 1, 1);

        //6 frente
        teste.addPoint(1, -1, 1);
        teste.addPoint(-1, -1, 1);
        teste.addPoint(-1, 1, 1);

        //7 esquerda
        teste.addPoint(-1, -1, -1);
        teste.addPoint(-1, -1, 1);
        teste.addPoint(-1, 1, 1);

        //8 esquerda
        teste.addPoint(-1, -1, -1);
        teste.addPoint(-1, 1, -1);
        teste.addPoint(-1, 1, 1);

        //9 direita
        teste.addPoint(1, -1, -1);
        teste.addPoint(1, -1, 1);
        teste.addPoint(1, 1, 1);

        //10 direita
        teste.addPoint(1, -1, -1);
        teste.addPoint(1, 1, -1);
        teste.addPoint(1, 1, 1);

        //11 tras
        teste.addPoint(1, -1, -1);
        teste.addPoint(1, 1, -1);
        teste.addPoint(-1, 1, -1);

        //12 tras
        teste.addPoint(1, -1, -1);
        teste.addPoint(-1, -1, -1);
        teste.addPoint(-1, 1, -1);



        // put callback registry here
        glutDisplayFunc(renderScene);
        glutReshapeFunc(changeSize);

        // some OpenGL settings
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        // enter GLUT�s main cycle
        glutMainLoop();
    }

	return 1;
}