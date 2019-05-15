#include "tablicakrawedzi.h"

tablicakrawedzi::tablicakrawedzi()
{}

void tablicakrawedzi::dodajKrawedz(int dlugoscKrawedzi, int wierzcholekA, int wierzcholekB){
    krawedz k(dlugoscKrawedzi,wierzcholekA,wierzcholekB);
    _tablicaKrawedzi.push_back(k);
}

void tablicakrawedzi::usunKrawedz(int wierzcholekA, int wierzcholekB){
    for(auto it = _tablicaKrawedzi.begin(); it != _tablicaKrawedzi.end();){
        if(
                (wierzcholekA == (*it)._wierzcholekA && wierzcholekB == (*it)._wierzcholekB) ||
                (wierzcholekA == (*it)._wierzcholekB && wierzcholekB == (*it)._wierzcholekA)  )
        {
            it=_tablicaKrawedzi.erase(it);
            krawedz::_iloscKrawedzi--;
            break;
        }
        else{
            ++it;
        }
    }
}

void tablicakrawedzi::usunKrawedzieWierzcholka(int wierzcholek){
    for(auto it = _tablicaKrawedzi.begin(); it != _tablicaKrawedzi.end();){
        if(wierzcholek==(*it)._wierzcholekA||wierzcholek==(*it)._wierzcholekB) {
            it=_tablicaKrawedzi.erase(it);
            krawedz::_iloscKrawedzi--;
        }
        else{
            ++it;
        }
    }
}

std::vector<int> tablicakrawedzi::getKrawedzieID(){
    std::vector<int> result;
    for(krawedz k : _tablicaKrawedzi){
        result.push_back(k._idKrawedzi);
    }
    return result;
}

std::vector<int> tablicakrawedzi::krawedzieWierzcholka(int idWierzcholka){
    std::vector<int> result;
    for(krawedz k : _tablicaKrawedzi){
        if(k._wierzcholekA==idWierzcholka || k._wierzcholekB==idWierzcholka){
            result.push_back(k._idKrawedzi);
        }
    }
    return result;
}

void tablicakrawedzi::wypiszTabliceKrawedzi(){
    std::cout<<"Tablica krawedzi:"<<std::endl;
    for(krawedz k : _tablicaKrawedzi){
        std::cout<<std::setw(3)<<std::left<<k._idKrawedzi<<" "<<std::setw(3)<<std::left<<k._wierzcholekA<<" "<<std::setw(3)<<std::left<<k._wierzcholekB<<" "<<std::setw(3)<<std::left<<k._dlugoscKrawedzi<<std::endl;
    }
    std::cout<<std::endl;
}
