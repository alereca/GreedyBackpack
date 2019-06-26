//
// Created by ale on 6/20/19.
//

#ifndef GREEDYBACKPACK_ELEMENT_H
#define GREEDYBACKPACK_ELEMENT_H


class Element {
private:
    int _num;
    double _volume;
    double _price;

public:
    Element(int num, double volume, double price){
        this->_num = num;
        this->_volume = volume;
        this->_price = price;
    };

    int GetNum();
    double GetVolume();
    double GetPrice();
    double GetPriceVolRelation();
    void Show();
};


#endif //GREEDYBACKPACK_ELEMENT_H
