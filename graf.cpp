#include "graf.h"
#include <vector>
#include <iostream>
#define INFTY 999999

graf::graf(){}

void graf::inicjuj(int iloscWierzcholkow) {
    _iloscWierzcholkow=iloscWierzcholkow;
    _macierzSasiedztwa.inicjuj(iloscWierzcholkow);
    _tablicaKrawedzi=_macierzSasiedztwa.aktualizujTabliceKrawedzi();
}

void graf::wypiszMacierzSasiedztwa(){
    _macierzSasiedztwa.wypiszMacierzSasiedztwa();
}

void graf::wypiszTabliceKrawedzi(){
    _tablicaKrawedzi.wypiszTabliceKrawedzi();
}

void graf::dodajKrawedz(int wartosc, int wierzcholekA, int wierzcholekB){
    if(wierzcholekA>_iloscWierzcholkow-1 || wierzcholekB>_iloscWierzcholkow-1){
        std::cerr<<"Blad: proba dodania krawedzi do nieistniejacego wierzcholka"<<std::endl;
        return;
    }
    if(wierzcholekA!=wierzcholekB){
        _macierzSasiedztwa[wierzcholekA][wierzcholekB]=wartosc;
        _macierzSasiedztwa[wierzcholekB][wierzcholekA]=wartosc;
        _tablicaKrawedzi.dodajKrawedz(wartosc,wierzcholekA,wierzcholekB);
    }
    else{
        std::cerr<<"Blad: proba dodania krawedzi do tego samego wierzcholka"<<std::endl;
    }
}

void graf::dodajWierzcholek(){
    _iloscWierzcholkow++;
    _macierzSasiedztwa.dodajWierzcholek();
}

void graf::usunKrawedz(int wierzcholekA, int wierzcholekB){
    if(wierzcholekA>_iloscWierzcholkow-1 || wierzcholekB>_iloscWierzcholkow-1){
        std::cerr<<"Blad: proba usuniecia krawedzi miedzy nieistniejacymi wierzcholkami"<<std::endl;
        return;
    }
    _macierzSasiedztwa[wierzcholekA][wierzcholekB]=0;
    _macierzSasiedztwa[wierzcholekB][wierzcholekA]=0;
    _tablicaKrawedzi.usunKrawedz(wierzcholekA,wierzcholekB);
}

void graf::usunWierzcholek(int wierzcholek){
    if(wierzcholek>_iloscWierzcholkow-1){
        std::cerr<<"Blad: proba usuniecia nieistniejacego wierzcholka"<<std::endl;
        return;
    }
    _macierzSasiedztwa.usunWierzcholek(wierzcholek);
    _tablicaKrawedzi.usunKrawedzieWierzcholka(wierzcholek);
    _iloscWierzcholkow--;
    _tablicaKrawedzi=_macierzSasiedztwa.aktualizujTabliceKrawedzi();
}

bool graf::czySasiednie(int wierzcholekA, int wierzcholekB){
    if(wierzcholekA>_iloscWierzcholkow-1 || wierzcholekB>_iloscWierzcholkow-1){
        std::cerr<<"Blad: proba odwolania sie do nieistniejacych wierzcholkow"<<std::endl;
        return false;
    }
    if(_macierzSasiedztwa[wierzcholekA][wierzcholekB]!=0)
        return true;
    else
        return false;
}

std::vector<int> graf::krawedzieWierzcholka(int idWierzcholka){
    return _tablicaKrawedzi.krawedzieWierzcholka(idWierzcholka);
}

std::vector<int> graf::wszystkieKrawedzie(){
    return _tablicaKrawedzi.getKrawedzieID();
}

std::vector<int> graf::wszystkieWierzcholki(){
    return _macierzSasiedztwa.getWierzcholki();
}

/*
void graf::dijkstra(int wierzcholekPoczatkowy){
    kopiec k;
    std::vector<wierzcholek> pozycje;//(_macierzSasiedztwa.rozmiar());
    k.tworzKopiec(_macierzSasiedztwa,wierzcholekPoczatkowy);
    int i=0;

    //std::cout<<"Kopiec: "<<std::endl;
    //for(wierzcholek w : k._tablica){
    //    std::cout<<w._numerWierzcholka<<" "<<w._numerPoprzednika<<" "<<w._kosztDojscia<<std::endl;
    //}



    while(k._rozmiar!=0){
        pozycje.push_back(k._tablica[0]);
        k.usunNajwiekszyPriorytet();



        std::cout<<i<<k._rozmiar<<pozycje[i]._numerWierzcholka<<std::endl;

        for(wierzcholek& w : k._tablica){
            std::cout<<w._numerWierzcholka<<": "<<_macierzSasiedztwa[w._numerWierzcholka][pozycje[i]._numerWierzcholka]<<std::endl;
            if(_macierzSasiedztwa[w._numerWierzcholka][pozycje[i]._numerWierzcholka]!=0 &&
                    w._kosztDojscia>(pozycje[i]._kosztDojscia+_macierzSasiedztwa[w._numerWierzcholka][pozycje[i]._numerWierzcholka])){
                w._kosztDojscia=pozycje[i]._kosztDojscia+_macierzSasiedztwa[w._numerWierzcholka][pozycje[i]._numerWierzcholka];
                w._numerPoprzednika=pozycje[i]._numerWierzcholka;
                std::cout<<"TEST: "<<pozycje[i]._kosztDojscia+_macierzSasiedztwa[w._numerWierzcholka][pozycje[i]._numerWierzcholka]<<std::endl;
            }
        }
        for(wierzcholek w : k._tablica){
            std::cout<<w._numerWierzcholka<<" "<<w._numerPoprzednika<<" "<<w._kosztDojscia<<std::endl;
        }
        k.sortuj();
        std::cout<<"Kopiec: "<<std::endl;
        for(wierzcholek w : k._tablica){
            std::cout<<w._numerWierzcholka<<" "<<w._numerPoprzednika<<" "<<w._kosztDojscia<<std::endl;
        }
        i++;
    }

    std::cout<<"Wynik: "<<std::endl;
    for(wierzcholek w : pozycje){
        std::cout<<w._numerWierzcholka<<" "<<w._numerPoprzednika<<" "<<w._kosztDojscia<<std::endl;
    }

    std::cout<<"Sciezka od wierzcholka "<<wierzcholekPoczatkowy<<" do:"<<std::endl;
    for(int j=1;j<i+1;j++){
        std::cout<<pozycje[i]._numerWierzcholka<<": "<<pozycje[i]._kosztDojscia<<std::endl;
    }
}*/

std::vector<wierzcholek> graf::bellmanFord(int wierzcholekPoczatkowy){
    std::vector<wierzcholek> lista;
    for(int i=0;i<_macierzSasiedztwa.rozmiar();i++){
        wierzcholek w(i,INFTY,-1);
        lista.push_back(w);
    }
    lista[wierzcholekPoczatkowy]._kosztDojscia=0;
    for(int i=1;i<_macierzSasiedztwa.rozmiar();i++){
        for(int j=0;j<_macierzSasiedztwa.rozmiar();j++){
            for(int k=0;k<_macierzSasiedztwa.rozmiar();k++){
                if((_macierzSasiedztwa[j][k]!=0 && (lista[k]._kosztDojscia)>=(lista[j]._kosztDojscia)+_macierzSasiedztwa[j][k])){
                    lista[k]._kosztDojscia=lista[j]._kosztDojscia+_macierzSasiedztwa[j][k];
                    lista[k]._numerPoprzednika=j;
                }
            }
        }
    }
    return lista;
}

void graf::zapiszDoPliku(std::ofstream &uchwyt, std::vector<wierzcholek> lista){
    uchwyt<<"GRAF W REPREZENTACJI MACIERZY SASIEDZTWA"<<std::endl;
    _macierzSasiedztwa.wypiszMacierzDoPliku(uchwyt);
    uchwyt<<"Wynik dzialania algorytmu Bellmana-Forda dla wierzcholka poczatkowego "<<_wierzcholekPoczatkowy<<":"<<std::endl;
    for(wierzcholek w : lista){
        if(w._numerWierzcholka!=_wierzcholekPoczatkowy){
            //std::cout<<"Wierzcholek "<<w._numerWierzcholka<<": "<<"koszt - "<<w._kosztDojscia<<", poprzednik - "<<w._numerPoprzednika<<std::endl;
            uchwyt<<"Wierzcholek "<<w._numerWierzcholka<<": "<<"koszt - "<<w._kosztDojscia<<", poprzednik - "<<w._numerPoprzednika<<std::endl;
        }
    }
}

void graf::wczytajGrafZPliku(std::string nazwaPliku){
    std::ifstream uchwyt;
    std::string linia;
    int wierzcholekA;
    int wierzcholekB;
    int wagaKrawedzi;
    int ilWierzcholkow;
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
                       //    iloscKrawedzi=std::stoi(subs);
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
                           dodajKrawedz(wagaKrawedzi,wierzcholekA,wierzcholekB);
                       }
                       //std::cout << i<<"Substring: " << subs << std::endl;
                       i++;
                   }
           }
           //std::cout<<std::endl;
    }
    uchwyt.close();

}

std::vector<krawedz> graf::wszystkieMozliweKrawedzie(unsigned int maksymalnaKrawedz){
    std::vector<krawedz> result;
    for(int i=0;i<_iloscWierzcholkow;i++){
        for(int j=i;j<_iloscWierzcholkow;j++){
            if(i!=j){
                int dlugoscKrawedzi=abs(rand()%maksymalnaKrawedz);
                krawedz k(dlugoscKrawedzi,i,j);
                result.push_back(k);
                //dodajKrawedz(dlugoscKrawedzi,i,j);

            }
        }
    }
    //wypiszMacierzSasiedztwa();
    return result;
}

void graf::generujGraf(double procentGestosci, int maksymalnaKrawedz){
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
            dodajKrawedz(k._dlugoscKrawedzi,k._wierzcholekA,k._wierzcholekB);
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
            dodajKrawedz(krawedzie[losowaKrawedz]._dlugoscKrawedzi,krawedzie[losowaKrawedz]._wierzcholekA,krawedzie[losowaKrawedz]._wierzcholekB);
            wykorzystane.push_back(losowaKrawedz);
            i++;
        }
        czyUzyte=false;
    }
}

float graf::zliczCzasAlgorytmu(int iloscWierzcholkow, double procentGestosci, int maksymalnaKrawedz, int wierzcholekPoczatkowy, std::ofstream& plik){
    double czas_ms;
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
