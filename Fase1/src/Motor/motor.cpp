#include "drawFunctions.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <string.h>

using namespace std;

utils::figure figura;


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



void renderScene(void)
{
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set camera
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);


	draw::drawReferencial();
	draw::drawFigure(figura);

	// End of frame
	glutSwapBuffers();
}

void lerFicheiroXML(string name) {
    TiXmlDocument f;
    //Load do ficheiro XML com o nome que foi passado como argumento
    bool b = f.LoadFile(name.c_str());

    if (b) {
        TiXmlElement* root = f.RootElement();

        //Inicialização do ciclo que percorre pelo ficheiro XML e lê os files que nele estão guardados
        for (TiXmlElement* elem = root->FirstChild()->ToElement(); elem!=nullptr; elem = elem->NextSiblingElement()) {
            const char* ficheiro = elem->Attribute("file");
            fstream fs;

            //Abre o ficheiro .3d
            fs.open(ficheiro);
            if (fs.is_open()) {
                string line;
                float x1, y1, z1 = 0.0f; //Inicializa as coordenadas de cada ponto

                //Lê linha a linha do ficheiro, não esquecendo que cada linha é um vértice/ponto
                while (getline(fs, line)) {
                    float cood[3]; //guarda num array as coordenadas de cada ponto

                    string delimiter = " ";
                    size_t pos = 0;
                    string token;
                    int i = 0;
                    while ((pos = line.find(delimiter)) != string::npos) {
                        token = line.substr(0, pos);
                        cood[i] = std::stof(token); //converte para float e guarda a coordenada
                        i++;
                        line.erase(0, pos + delimiter.length());
                    }
                    x1=cood[0],y1=cood[1],z1=cood[2];
                    figura.addPoint(x1,y1,z1);
                }
                fs.close();
                //Apaga o ficheiro .3d já lido do XML !!!!!!


            }
            else std::cout << "Can't open file!"<< std::endl;
        }
    }
    else std::cout <<"File does not exist!\n" << std::endl;
}

int main(int argc, char** argv){
    if (argc <=1) {
        std::cout << "\nMissing arguments\n" << std::endl;
    }
    else if(argc > 2){
        std::cout << "\nToo many arguments\n" << std::endl;
    }
    else {
        std::cout << "\nLendo .... ..... ....\n" << std::endl;
        lerFicheiroXML(argv[1]);

        // put GLUT init here
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(800, 800);
        glutCreateWindow("Projeto-CG");


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