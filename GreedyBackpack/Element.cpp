//
// Created by ale on 6/20/19.
//
#include <iostream>
#include "Element.h"

double Element::GetPriceVolRelation(){
    return this->_price / this->_volume;
}

double Element::GetVolume() {
    return this->_volume;
}

double Element::GetPrice() {
    return this->_price;
}

int Element::GetNum() {
    return this->_num;
}

void Element::Show() {
    std::cout<<this->GetNum()
             <<" - "<<this->GetVolume()
             <<" / "<<this->GetPrice()
             <<" = "<<this->GetPriceVolRelation()
             <<"\n";
}
