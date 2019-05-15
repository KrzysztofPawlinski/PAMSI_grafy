#ifndef KOPIEC_H
#define KOPIEC_H

#include "macierzsasiedztwa.h"
#include "wierzcholek.h"
#include <vector>
#include <algorithm>

struct greater1{
  bool operator()(const wierzcholek& a,const wierzcholek& b) const{
    return a._kosztDojscia>b._kosztDojscia;
  }
};

class kopiec
{
public:
    kopiec();
    int _rozmiar;
    void wgore(int index);
    void sortuj();
    bool czyPusty();
    void tworzKopiec(macierzsasiedztwa macierz, int wierzcholekPoczatkowy);
    void dodaj(wierzcholek element);
    void usunNajwiekszyPriorytet();
    std::vector<wierzcholek> _tablica;
    std::vector<int> _pozycje;
};


#endif // KOPIEC_H
