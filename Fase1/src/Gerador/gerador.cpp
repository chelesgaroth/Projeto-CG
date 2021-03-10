#include <iostream>
#include "../tinyXML/tinyxml.h"
#include "calculaVertices.cpp" //não seria suposto dar include ao hpp???
#include <fstream>
#include <sstream>

using namespace std;
TiXmlDocument doc;


int write_XML(string file) {

    if(!(doc.LoadFile("scenes.xml"))){
        TiXmlElement *element = new TiXmlElement("Scene");
        doc.LinkEndChild(element);
        TiXmlElement *element2 = new TiXmlElement("Model");
        element2->SetAttribute("file", file.c_str());
        element->LinkEndChild(element2);
        std::cout <<"\nXML File Created.\n"<< std::endl;
    }
    else{
        TiXmlHandle docHandle(&doc);
        TiXmlElement* fileLog = docHandle.FirstChild("Scene").ToElement();
        TiXmlElement* root = doc.RootElement();
        if (fileLog) {
            //Verifica se já existe uma entrada para esse mesmo ficheiro .3d no XML
            for(TiXmlElement* aux = root->FirstChild()->ToElement(); aux!=nullptr; aux = aux->NextSiblingElement()) {
                const char* ficheiro1 = aux->Attribute("file");
                if ( strcmp( ficheiro1, file.c_str()) == 0 ){
                    std::cout <<"\nFicheiro já existente atualizado em XML\n"<< std::endl;
                    return -1;
                }
            }

            TiXmlElement newCategory2("Model");
            newCategory2.SetAttribute("file", file.c_str());
            fileLog->InsertEndChild(newCategory2);
        }
    }
    doc.SaveFile("scenes.xml");
}


int createFileType (vector<point> vertices, string name){

    fstream file;
    // in out(write) mode
    // ios::out Open for output operations.
    file.open(name,ios::out);
    for(int i=0; i< vertices.size(); i++){
        file << vertices[i].x << " ";
        file << vertices[i].y << " ";
        file << vertices[i].z << " ";
        file << "\n";
    }


    if(!file){
        cout<<"Error in creating file!!!";
        return 0;
    }
    cout<<"File created successfully.";
    file.close();
}


int main(int argc, char* argv[]) {

    figure f;

    //Gerar os vértices para o desenho do plano e transcrever para o ficheiro .3d
    if((strcmp(argv[1],"plane")==0)&&(argc==5)) {

        float x = std::stof(argv[2]);
        float z = std::stof(argv[3]);

        f = createPlane(x, z);

        createFileType(f.getVector(), argv[4]);
        write_XML(argv[4]);
        std::cout << "Done\n" << std::endl;
    }

        //Gerar os vértices para o desenho do cubo/caixa e transcrever para o ficheiro .3d
    else if((strcmp(argv[1],"box")==0)&&(argc==7)){
        float x = std::stof(argv[2]);
        float y = std::stof(argv[3]);
        float z = std::stof(argv[4]);
        stringstream aux(argv[5]);
        int camadas = 0;
        aux >> camadas;

        f = createBox(x, y, z, camadas);

        createFileType(f.getVector(), argv[6]);
        write_XML(argv[6]);
        std::cout << "Done\n" << std::endl;
    }

        //Gerar os vértices para o desenho da esfera e transcrever para o ficheiro .3d
    else if((strcmp(argv[1],"sphere")==0)&&(argc==6)){
        float radius = std::stof(argv[2]);
        stringstream aux(argv[3]);
        int slices = 0;
        aux >> slices;
        stringstream aux2(argv[4]);
        int stacks = 0;
        aux2 >> stacks;

        f = createSphere(radius, stacks, slices);

        createFileType(f.getVector(), argv[5]);
        write_XML(argv[5]);
        std::cout << "Done\n" << std::endl;

    }

        //Gerar os vértices para o desenho do cone e transcrever para o ficheiro .3d
    else if((strcmp(argv[1], "cone")==0)&&(argc==7)){
        float radius = std::stof(argv[2]);
        float height = std::stof(argv[3]);
        stringstream aux(argv[4]);
        int slices = 0;
        aux >> slices;
        stringstream aux2(argv[5]);
        int stacks = 0;
        aux2 >> stacks;

        f = createCone(radius, height, stacks, slices);

        createFileType(f.getVector(), argv[6]);
        write_XML(argv[6]);
        std::cout << "Done\n" << std::endl;

    }

        //Tela de ajuda e comandos
    else if(strcmp(argv[1], "-help")==0){
        std::cout << "Plane         [x] [y]\n"
                     "Box           [x] [y] [z] [divisions per edge]\n"
                     "Sphere        [radius] [slices] [stacks]\n"
                     "Cone          [radius] [height] [slices] [stacks]\n" << std::endl;
    }
    else {
        std::cout <<"\nMissing arguments\n"<< std::endl;
    }

    return 1;
}
