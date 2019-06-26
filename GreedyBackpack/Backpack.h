//
// Created by ale on 6/20/19.
//

#ifndef GREEDYBACKPACK_BACKPACK_H
#define GREEDYBACKPACK_BACKPACK_H

#include <vector>
#include "Element.h"


class Backpack {
private:
    std::vector<Element> _elements;
    double _backpackSize;

public:
    Backpack(const std::vector<Element>& elements, double backpackSize){
        this->_backpackSize = backpackSize;
        double acumSize = 0;

        for (auto element : elements) {
            double elementVol = element.GetVolume();

            acumSize += elementVol;

            // If this elements adds more volume than supported, continues to the next one
            if(acumSize > this->_backpackSize){
                acumSize -= elementVol;
                continue;
            }

            this->_elements.push_back(element);
        }


    }

    void Show();
};


#endif //GREEDYBACKPACK_BACKPACK_H
