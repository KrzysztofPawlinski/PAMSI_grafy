#ifndef TABLICAKRAWEDZI_H
#define TABLICAKRAWEDZI_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "krawedz.h"

class tablicakrawedzi
{
public:
    tablicakrawedzi();
    std::vector<krawedz> _tablicaKrawedzi;
    void dodajKrawedz(int dlugoscKrawedzi, int wierzcholekA, int wierzcholekB);
    void usunKrawedz(int wierzcholekA, int wierzcholekB);
    void usunKrawedzieWierzcholka(int wierzcholek);
    std::vector<int> getKrawedzieID();
    std::vector<int> krawedzieWierzcholka(int idWierzcholka);
    void wypiszTabliceKrawedzi();

};

#endif // TABLICAKRAWEDZI_H
