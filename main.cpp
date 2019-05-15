#include <iostream>
#include <cmath>
#include "graf.h"
#include "graf_lista.h"

using namespace std;

void testujAlgorytm(int iloscWierzcholkow, std::ofstream& plik, std::ofstream& czasy, std::ofstream& czas_debug){
    czasy<<"Test algorytmu Bellmana-Forda - reprezentacja grafu za pomocą macierzy sąsiedztwa"<<std::endl;
    float suma=0;
    for(int i=0;i<100;i++){
        graf g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,25,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 25 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 25 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 25 procent: "<<suma/100<<std::endl;
    suma=0;

    for(int i=0;i<100;i++){
        graf g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,50,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 50 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 50 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 50 procent: "<<suma/100<<std::endl;
    suma=0;

    for(int i=0;i<100;i++){
        graf g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,75,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 75 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 75 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 75 procent: "<<suma/100<<std::endl;
    suma=0;

    for(int i=0;i<100;i++){
        graf g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,100,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 100 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 100 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 100 procent: "<<suma/100<<std::endl;
    suma=0;


    czasy<<"Test algorytmu Bellmana-Forda - reprezentacja grafu za pomocą listy sąsiedztwa"<<std::endl;
    for(int i=0;i<100;i++){
        graf_lista g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,25,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 25 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 25 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 25 procent: "<<suma/100<<std::endl;
    suma=0;

    for(int i=0;i<100;i++){
        graf_lista g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,50,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 50 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 50 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 50 procent: "<<suma/100<<std::endl;
    suma=0;

    for(int i=0;i<100;i++){
        graf_lista g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,75,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 75 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 75 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 75 procent: "<<suma/100<<std::endl;
    suma=0;

    for(int i=0;i<100;i++){
        graf_lista g;
        float t=g.zliczCzasAlgorytmu(iloscWierzcholkow,100,1000,1,plik);
        czas_debug<<i+1<<". "<<"Ilosc wierzcholkow: "<<iloscWierzcholkow<<", gestosc: 100 procent - "<<t<<" ms"<<std::endl;
        suma+=t;
    }
    std::cout<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 100 procent: "<<suma/100<<std::endl;
    czasy<<"Sredni czas wykonania algorytmu dla grafu o "<<iloscWierzcholkow<<" wierzcholkow, gestosci 100 procent: "<<suma/100<<std::endl;
    suma=0;

}

int main()
{
    srand(time(NULL));
    ofstream plik;
    ofstream czasy;
    ofstream czas_debug;
    plik.open("logi.txt");
    czasy.open("Wynik dzialania.txt");
    czas_debug.open("Czas kazdego wykonania.txt");
    testujAlgorytm(30,plik,czasy,czas_debug);
    testujAlgorytm(50,plik,czasy,czas_debug);
    testujAlgorytm(100,plik,czasy,czas_debug);
    testujAlgorytm(180,plik,czasy,czas_debug);
    czasy.close();
    czas_debug.close();
    plik.close();
}
