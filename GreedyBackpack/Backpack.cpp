//
// Created by ale on 6/20/19.
//
#include <iostream>
#include "Backpack.h"

void Backpack::Show() {
    double acumPrice = 0;
    double acumVolume = 0;

    if (this->_elements.empty()){
        std::cout<<"No elements could fit"<<"\n";
    }

    if(!this->_elements.empty()){
        for (auto &element : _elements) {
            acumPrice += element.GetPrice();
            acumVolume += element.GetVolume();

            element.Show();
        }
        std::cout<<"Accumulated Price: "<<acumPrice<<"\n"
                 <<"Accumulated Volume: "<<acumVolume<<"\n"
                 <<"Backpack Size: "<<this->_backpackSize<<"\n";
    }
}

