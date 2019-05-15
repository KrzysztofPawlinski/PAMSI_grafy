#include "macierzsasiedztwa.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

macierzsasiedztwa::macierzsasiedztwa()
{}
/*
macierzsasiedztwa::macierzsasiedztwa(int iloscWierzcholkow){
    //std::vector<int> wierszidentyfikatorow;
    //for(int i=0;i<iloscWierzcholkow;++i){
    //    wierszidentyfikatorow.push_back(i);//dodatkowy wiersz z id wiercholkow, tak zeby nie zmienialo sie ono przy usuwaniu
    //}
    _rozmiar=0;
    for(int i=0;i<iloscWierzcholkow;++i){
        std::vector<int> wiersz;
        for(int i=0;i<iloscWierzcholkow;++i){
            wiersz.push_back(0);
        }
        _macierzSasiedztwa.push_back(wiersz);
        _rozmiar++;
    }
}*/

void macierzsasiedztwa::inicjuj(int iloscWierzcholkow){
    for(int i=0;i<iloscWierzcholkow;++i){
        std::vector<int> wiersz;
        for(int i=0;i<iloscWierzcholkow;++i){
            wiersz.push_back(0);
        }
        _macierzSasiedztwa.push_back(wiersz);
    }
}

void macierzsasiedztwa::wypiszMacierzDoPliku(std::ofstream &plik){
    for(std::vector<int> w : _macierzSasiedztwa){
        for(int i : w){
            plik<<std::setw(3)<<std::left<<i<<" ";
        }
        plik<<std::endl<<std::endl;
    }
}

void macierzsasiedztwa::wypiszMacierzSasiedztwa(){
    std::cout<<std::endl<<"Macierz sasiedztwa:"<<std::endl<<std::endl;
    for(std::vector<int> w : _macierzSasiedztwa){
        for(int i : w){
            std::cout<<std::setw(3)<<std::left<<i<<" ";
        }
        std::cout<<std::endl<<std::endl;
    }
}

void macierzsasiedztwa::dodajWierzcholek(){
    std::vector<int> nowyWiersz(_macierzSasiedztwa.size()+1);
    for(std::vector<int>& w : _macierzSasiedztwa){
        w.push_back(0);
    }
    _macierzSasiedztwa.push_back(nowyWiersz);
}

void macierzsasiedztwa::usunWierzcholek(int wierzcholek){
    for(std::vector<int>& w : _macierzSasiedztwa){
        w.erase(w.begin()+wierzcholek);
    }
    _macierzSasiedztwa.erase(_macierzSasiedztwa.begin()+wierzcholek);
}

tablicakrawedzi macierzsasiedztwa::aktualizujTabliceKrawedzi(){
    tablicakrawedzi result;
    for(unsigned int i=0;i<_macierzSasiedztwa.size();++i){
        for(unsigned int j=i;j<_macierzSasiedztwa.size();++j){
            if(_macierzSasiedztwa[i][j]!=0){
                result.dodajKrawedz(_macierzSasiedztwa[i][j],i,j);
            }
        }
    }
    return result;
}

std::vector<int> macierzsasiedztwa::getWierzcholki(){
    std::vector<int> result;
    for(unsigned int i=0;i<_macierzSasiedztwa.size();++i){
        result.push_back(i);
    }
    return result;
}

int macierzsasiedztwa::rozmiar(){
    return _macierzSasiedztwa.size();
}
