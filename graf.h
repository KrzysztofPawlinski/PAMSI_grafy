#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <windows.h>
#include "macierzsasiedztwa.h"
#include "krawedz.h"
#include "tablicakrawedzi.h"
#include "kopiec.h"

class graf
{
public:
    graf();
    int  _wierzcholekPoczatkowy;
    int  _iloscWierzcholkow;
    void inicjuj(int iloscWierzcholkow);
    void wypiszMacierzSasiedztwa();
    void wypiszTabliceKrawedzi();
    void dodajWierzcholek();
    void dodajKrawedz(int wartosc, int wierzcholekA, int wierzcholekB);
    void usunWierzcholek(int wierzcholek);
    void usunKrawedz(int wierzcholekA, int wierzcholekB);
    bool czySasiednie(int wierzcholekA, int wierzcholekB);

    std::vector<int> krawedzieWierzcholka(int idWierzcholka);
    std::vector<int> wszystkieWierzcholki();
    std::vector<int> wszystkieKrawedzie();

    std::vector<int> wierzcholkiKrawedzi(int idKrawedzi);
    int przeciwnyWierzcholek(int wierzcholek, int idKrawedzi);
    void zmienWartoscKrawedzi(int nowaWartosc);

    void dijkstra(int wierzcholekPoczatkowy);
    std::vector<wierzcholek> bellmanFord(int wierzcholekPoczatkowy);

    void zapiszDoPliku(std::ofstream& uchwyt, std::vector<wierzcholek> lista);
    void wczytajGrafZPliku(std::string nazwaPliku);

    std::vector<krawedz> wszystkieMozliweKrawedzie(unsigned int maksymalnaKrawedz);
    void generujGraf(double procentGestosci, int maksymalnaKrawedz);
    float zliczCzasAlgorytmu(int iloscWierzcholkow, double procentGestosci, int maksymalnaKrawedz, int wierzcholekPoczatkowy, std::ofstream &plik);

private:
    macierzsasiedztwa _macierzSasiedztwa;
    tablicakrawedzi   _tablicaKrawedzi;
};

#endif // GRAF_H
