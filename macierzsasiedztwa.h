#ifndef MACIERZSASIEDZTWA_H
#define MACIERZSASIEDZTWA_H
#include <vector>
#include <tablicakrawedzi.h>
#include <fstream>

class macierzsasiedztwa
{
public:
    macierzsasiedztwa();
    macierzsasiedztwa(int iloscWierzcholkow);
    void dodajWierzcholek();
    void usunWierzcholek(int wierzcholek);
    void inicjuj(int iloscWierzcholkow);
    void wypiszMacierzSasiedztwa();
    void wypiszMacierzDoPliku(std::ofstream& plik);
    tablicakrawedzi aktualizujTabliceKrawedzi();
    std::vector<int> getWierzcholki();

    std::vector<int> & operator[] (int indeks){
        return _macierzSasiedztwa[indeks];
    }

    std::vector<int> operator[] (int indeks) const {
        return _macierzSasiedztwa[indeks];
    }

    std::vector<std::vector<int>> _macierzSasiedztwa;
    int rozmiar();
};

#endif // MACIERZSASIEDZTWA_H
