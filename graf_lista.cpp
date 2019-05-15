#include "graf_lista.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#define INFTY 999999

graf_lista::graf_lista(){
}

void graf_lista::inicjuj(int iloscWierzcholkow){
    for(int i=0;i<iloscWierzcholkow;++i){
        wierzcholek w(i,INFTY,-1);
        _listaWierzcholkow.push_back(w);
    }
}

void graf_lista::dodajKrawedz(int wierzcholekA, int wierzcholekB, int waga){
    if(wierzcholekA<wierzcholekB){
        krawedz k(waga, wierzcholekA, wierzcholekB);
        _listaKrawedzi.push_back(k);
    }
    else{
        int wierzcholekAfxd=wierzcholekB;
        int wierzcholekBfxd=wierzcholekA;
        krawedz k(waga, wierzcholekAfxd, wierzcholekBfxd);
        _listaKrawedzi.push_back(k);
    }
}

void graf_lista::wyswietl(){
    for(krawedz k : _listaKrawedzi){
        std::cout<<std::setw(4)<<", "<<k._wierzcholekA<<k._wierzcholekB<<", "<<k._dlugoscKrawedzi<<std::endl;
    }
}

void graf_lista::dodajWierzcholek(){
    int i=_listaWierzcholkow.size()-1;
    wierzcholek w(i,INFTY,-1);
    _listaWierzcholkow.push_back(w);
}

std::vector<wierzcholek> graf_lista::bellmanFord(int wierzcholekPoczatkowy){
    std::vector<wierzcholek> lista;
    for(unsigned int i=0;i<_listaWierzcholkow.size();++i){
        wierzcholek w(i,INFTY,-1);
        lista.push_back(w);
    }
    lista[wierzcholekPoczatkowy]._kosztDojscia=0;
    for(unsigned int i=1;i<_listaWierzcholkow.size();i++){
        for(unsigned int j=0;j<_listaKrawedzi.size()-1;j++){
            int u = _listaKrawedzi[j]._wierzcholekA;
            int v = _listaKrawedzi[j]._wierzcholekB;
            int waga = _listaKrawedzi[j]._dlugoscKrawedzi;
            if(lista[v]._kosztDojscia!=INFTY&&lista[v]._kosztDojscia+waga<lista[u]._kosztDojscia){
                lista[u]._kosztDojscia=lista[v]._kosztDojscia+waga;
                lista[u]._numerPoprzednika=v;
            }
            if(lista[u]._kosztDojscia!=INFTY&&lista[u]._kosztDojscia+waga<lista[v]._kosztDojscia){
                lista[v]._kosztDojscia=lista[u]._kosztDojscia+waga;
                lista[v]._numerPoprzednika=u;
            }
        }
    }
    return lista;
}

void graf_lista::zapiszDoPliku(std::ofstream &uchwyt, std::vector<wierzcholek> lista){
    uchwyt<<"GRAF W REPREZENTACJI LISTY SASIEDZTWA"<<std::endl;
    //_macierzSasiedztwa.wypiszMacierzDoPliku(uchwyt);
    uchwyt<<"Wynik dzialania algorytmu Bellmana-Forda dla wierzcholka poczatkowego "<<_wierzcholekPoczatkowy<<":"<<std::endl;
    for(wierzcholek w : lista){
        if(w._numerWierzcholka!=_wierzcholekPoczatkowy){
            //std::cout<<"Wierzcholek "<<w._numerWierzcholka<<": "<<"koszt - "<<w._kosztDojscia<<", poprzednik - "<<w._numerPoprzednika<<std::endl;
            uchwyt<<"Wierzcholek "<<w._numerWierzcholka<<": "<<"koszt - "<<w._kosztDojscia<<", poprzednik - "<<w._numerPoprzednika<<std::endl;
        }
    }
}

void graf_lista::wczytajGrafZPliku(std::string nazwaPliku){
    std::ifstream uchwyt;
    std::string linia;
    int wierzcholekA=0;
    int wierzcholekB=0;
    int wagaKrawedzi=0;
    int ilWierzcholkow=0;
    //int iloscKrawedzi;
    uchwyt.open(nazwaPliku);
    int i=0;
    while(!uchwyt.eof()){
           getline(uchwyt, linia);
           std::stringstream ss(linia);
           while(ss){
                   std::string subs;
                   ss >> subs;
                   if(!subs.empty()){
                       int j=i%3;
                       //if(i==0){
                           //iloscKrawedzi=std::stoi(subs);
                       //}
                       if(i==1){
                           ilWierzcholkow=std::stoi(subs);
                       }
                       if(i==2){
                           _wierzcholekPoczatkowy=std::stoi(subs);
                           inicjuj(ilWierzcholkow);
                       }
                       if(i!=0&&j==0){
                           wierzcholekA=std::stoi(subs);
                       }
                       if(i!=1&&j==1){
                           wierzcholekB=std::stoi(subs);
                       }
                       if(i!=2&&j==2){
                           wagaKrawedzi=std::stoi(subs);
                           dodajKrawedz(wierzcholekA,wierzcholekB,wagaKrawedzi);
                       }
                       //std::cout << i<<"Substring: " << subs << std::endl;
                       i++;
                   }
           }
           //std::cout<<std::endl;
    }
    uchwyt.close();

}

std::vector<krawedz> graf_lista::wszystkieMozliweKrawedzie(unsigned int maksymalnaKrawedz){
    std::vector<krawedz> result;
    for(unsigned int i=0;i<_listaWierzcholkow.size();i++){
        for(unsigned int j=i;j<_listaWierzcholkow.size();j++){
            if(i!=j){
                int dlugoscKrawedzi=abs(rand()%maksymalnaKrawedz);
                krawedz k(dlugoscKrawedzi,i,j);
                result.push_back(k);
            }
        }
    }
    return result;
}

void graf_lista::generujGraf(double procentGestosci, int maksymalnaKrawedz){
    if(procentGestosci>100){
        std::cerr<<"Blad: zadanie zbyt duzej gestosci grafu"<<std::endl;
        return;
    }
    std::vector<krawedz> krawedzie = wszystkieMozliweKrawedzie(maksymalnaKrawedz);
    int ilosc=floor(procentGestosci/100*krawedzie.size());
    int i=0;
    bool czyUzyte;
    std::vector<int> wykorzystane;
    if(procentGestosci==100){
        for(krawedz k : krawedzie){
            dodajKrawedz(k._wierzcholekA,k._wierzcholekB,k._dlugoscKrawedzi);
        }
        return;
    }
    while(i!=ilosc){
        int losowaKrawedz=abs(rand()%(krawedzie.size()));
        for(int j : wykorzystane){
            if(j==losowaKrawedz){
                czyUzyte=true;
            }
        }
        if(czyUzyte==false){
            dodajKrawedz(krawedzie[losowaKrawedz]._wierzcholekA,krawedzie[losowaKrawedz]._wierzcholekB,krawedzie[losowaKrawedz]._dlugoscKrawedzi);
            wykorzystane.push_back(losowaKrawedz);
            i++;
        }
        czyUzyte=false;
    }
}

float graf_lista::zliczCzasAlgorytmu(int iloscWierzcholkow, double procentGestosci, int maksymalnaKrawedz, int wierzcholekPoczatkowy, std::ofstream& plik){
    double czas_ms;
    _wierzcholekPoczatkowy=wierzcholekPoczatkowy;
    inicjuj(iloscWierzcholkow);
    generujGraf(procentGestosci,maksymalnaKrawedz);
    DWORD start = GetTickCount();
    std::vector<wierzcholek> wynikAlgorytmu = bellmanFord(wierzcholekPoczatkowy);
    DWORD koniec = GetTickCount();
    czas_ms=koniec-start;
    zapiszDoPliku(plik,wynikAlgorytmu);
    plik<<"Czas wykonania algorytmu: "<<czas_ms<<std::endl;
    std::cout<<"Czas wykonania algorytmu: "<<czas_ms<<std::endl;
    return czas_ms;
}
