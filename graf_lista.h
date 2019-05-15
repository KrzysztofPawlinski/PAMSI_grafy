#ifndef GRAF_LISTA_H
#define GRAF_LISTA_H

#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "wierzcholek.h"
#include "krawedz.h"

class graf_lista
{
public:
    graf_lista();
    void inicjuj(int iloscWierzcholkow);
    int _wierzcholekPoczatkowy;
    std::vector<wierzcholek> _listaWierzcholkow;
    std::vector<krawedz> _listaKrawedzi;
    std::vector<wierzcholek> bellmanFord(int wierzcholekPoczatkowy);
    void wyswietl();
    void wczytajGrafZPliku(std::string nazwaPliku);
    void zapiszDoPliku(std::ofstream &uchwyt, std::vector<wierzcholek> lista);
    void dodajWierzcholek();
    void dodajKrawedz(int wierzcholekA, int wierzcholekB, int waga);
    std::vector<krawedz> wszystkieMozliweKrawedzie(unsigned int maksymalnaKrawedz);
    void generujGraf(double procentGestosci, int maksymalnaKrawedz);
    float zliczCzasAlgorytmu(int iloscWierzcholkow, double procentGestosci, int maksymalnaKrawedz, int wierzcholekPoczatkowy, std::ofstream& plik);
};

#endif // GRAF_LISTA_H
