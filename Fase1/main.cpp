#include <iostream>
#include "tinyXML/tinyxml.h"


void write_app_settings_doc(){
    TiXmlDocument doc;
    //TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
    //doc.LinkEndChild( decl );

    TiXmlElement* element = new TiXmlElement( "Scene" );
    doc.LinkEndChild( element );

    /*TiXmlText* text = new TiXmlText( "Opening a new salutation" );
    element->LinkEndChild( text );*/

    //for(long i=0; i<3; i++){

    TiXmlElement* element2 = new TiXmlElement( "Model" );
    //TiXmlText* text2 = new TiXmlText( "" );

    element2->SetAttribute("file","plane.3d");

    TiXmlElement* element3 = new TiXmlElement( "Model" );
    element3->SetAttribute("file","box.3d");

    element->LinkEndChild( element2 );
    element->LinkEndChild( element3 );
    //element2->LinkEndChild( text2 );
    //}
    if (doc.SaveFile( "teste.xml" ))
        printf("\n");
        doc.Print();
        printf("\nFile Created");

}

bool LoadFile(){
    TiXmlDocument doc("teste.xml");
    if(doc.LoadFile()){
        printf("XML File Loaded");
        return true;
    }
    else
    {
        printf("Could not load XML File.");
        return false;
    }
}



int main(){
    if (!LoadFile())
        write_app_settings_doc();
    else write_app_settings_doc();

    return 0;
}