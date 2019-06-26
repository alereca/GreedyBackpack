#include <iostream>
#include <time.h>
#include "Element.h"
#include "Backpack.h"
#include "RandomNumberGenerator.h"

void SortElements(std::vector<Element>&, int, int);
void ShowElements(std::vector<Element>&);

template <typename T1, typename T2>
void Exchange(T1&, T2&);

int main() {
    const int Nelements = 2000000;
    const double backpackVolume = 8000;
    const double maxPrice = 2000;

    std::vector<Element> elements;

    struct  timespec start, finish;
    double elapsed_time;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 1; i <= Nelements; ++i) {
        Element element(i,
                        RandomNumberGenerator::GetRandomReal(1, backpackVolume),
                        RandomNumberGenerator::GetRandomReal(1, maxPrice)
                );

        elements.push_back(element);
    }

    std::cout<<"Elements:"<<std::endl;

    ShowElements(elements);

    std::cout<<"\nElements ordered by its price/volume relation in descending order:"<<std::endl;

    SortElements(elements, 0, elements.size()-1);
    ShowElements(elements);

    std::cout<<"\nA generally good solution that fits into backpack:"<<std::endl;

    Backpack backpack(elements, backpackVolume);
    backpack.Show();

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed_time = (finish.tv_sec - start.tv_sec);
    elapsed_time += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    std::cout<<elapsed_time<<std::endl;
    // https://stackoverflow.com/questions/2962785/c-using-clock-to-measure-time-in-multi-threaded-programs/2962914#2962914

    return 0;
}


void ShowElements(std::vector<Element>& elements){
    for (auto &element : elements) {
        element.Show();
    }
}


void SortElements(std::vector<Element>& elements, int start, int end){
    int med = (start + end) / 2;
    double pivot = elements[med].GetPriceVolRelation();
    int i = start, j = end;

    do{
        while(elements[i].GetPriceVolRelation() > pivot) { i++; } // While values are sorted properly
        while(elements[j].GetPriceVolRelation() < pivot) { j--; } // i and j moves

        if(i <= j){
            Exchange(elements[i], elements[j]);
            i++;
            j--;
        }
    } while(i <= j);

    if(j > start) { SortElements(elements, start, j); }
    if(i < end) { SortElements(elements, i, end); }
}


template <typename T1, typename T2>
void Exchange(T1& e1, T2& e2){
    T1 eTemp = e1;
    e1 = e2;
    e2 = eTemp;
}


