#ifndef OOP_FACTORY_H
#define OOP_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "square.h"
#include "rectangle.h"
#include "trapez.h"
#include <string>

struct factory {

    std::shared_ptr<figure> FigureCreate(std::istream &is) {
        std::string name;
        is >> name;
        if ( name == "rectangle" ) {
            return std::shared_ptr<figure> ( new Rectangle(is));
        } else if ( name == "trapez") {
            return std::shared_ptr<figure> ( new Trapez(is));
        } else if ( name == "square") {
            return std::shared_ptr<figure> ( new Square(is));
        } else {
            throw std::logic_error("There is no such figure\n");
        }
    }

    std::shared_ptr<figure> FigureCreateFile(std::ifstream &is) {
        std::string name;
        is >> name;
        if ( name == "rectangle" ) {
            return std::shared_ptr<figure> ( new Rectangle(is));
        } else if ( name == "trapez") {
            return std::shared_ptr<figure> ( new Trapez(is));
        } else if ( name == "square") {
            return std::shared_ptr<figure> ( new Square(is));
        } else {
            throw std::logic_error("There is no such figure\n");
        }
    }

};


#endif //OOP_FACTORY_H
