#include "kopiec.h"
#define INFTY 999999

kopiec::kopiec(){
    _rozmiar=0;
}

void kopiec::sortuj(){
    std::make_heap(_tablica.begin(),_tablica.end(),greater1());

//    wierzcholek pierwszy=_tablica[0];
  //  unsigned int j=0;
  //  while( j<=_tablica.size()){
    //    if(j<_tablica.size() && _tablica[j+1]._kosztDojscia > _tablica[j]._kosztDojscia)
      //      j++;
//        if(pierwszy._kosztDojscia>=_tablica[j]._kosztDojscia)
  //          break;
    //    _tablica[j/2]._kosztDojscia=_tablica[j]._kosztDojscia;
   //     j=2*j;
    //}
    //_tablica[j/2]=pierwszy;

}

void kopiec::tworzKopiec(macierzsasiedztwa macierz, int wierzcholekPoczatkowy){
    for(int i=0;i<macierz.rozmiar();++i){
        if(i==wierzcholekPoczatkowy){
            wierzcholek w(i,0,-1);
            _tablica.push_back(w);
            _rozmiar++;
        }
    }
    for(int i=0;i<macierz.rozmiar();++i){
        if(i!=wierzcholekPoczatkowy){
            wierzcholek w(i,INFTY,-1);
            _tablica.push_back(w);
            _rozmiar++;
        }
    }

}

bool kopiec::czyPusty(){
    if(_tablica.size()==0){
        return true;
    }
    return false;
}

void kopiec::dodaj(wierzcholek element){
    /*
    _tablica.push_back(element);
    int i = _rozmiar-1;
    while(i!=0) {
        if(_tablica[i/2]._kosztDojscia < _tablica[i]._kosztDojscia) {
            wierzcholek tmp = _tablica[i];
            _tablica[i] = _tablica[i/2];
            _tablica[i/2] = tmp;
            i/=2;
        }
        else
            break;
    }
    _rozmiar++;*/
    int rozmiar=_tablica.size();
    _tablica[rozmiar]=element;
    wgore(rozmiar);




}

void kopiec::wgore(int index){
    if(index==0)
        return;
    int prntindx=(index-1)/2;
    if(_tablica[prntindx]._kosztDojscia>_tablica[index]._kosztDojscia){
        wierzcholek tmp=_tablica[prntindx];
        _tablica[prntindx]=_tablica[index];
        _tablica[index]=tmp;
        wgore(prntindx);
    }
}

void kopiec::usunNajwiekszyPriorytet(){
    _tablica[0] = _tablica[_rozmiar-1];

    /*std::cout<<"Kopiec: "<<std::endl;
    for(wierzcholek w : _tablica){
        std::cout<<w._numerWierzcholka<<" "<<w._numerPoprzednika<<" "<<w._kosztDojscia<<std::endl;
    }*/

    _tablica.erase(_tablica.end()-1);
    _rozmiar--;
    int i = 1;
    while(i*2 <= _rozmiar){
    if(_tablica[i]._kosztDojscia < _tablica[i*2]._kosztDojscia || _tablica[i]._kosztDojscia < _tablica[i*2+1]._kosztDojscia) {
        if(_tablica[i*2]._kosztDojscia > _tablica[i*2+1]._kosztDojscia || i*2+1 > _rozmiar) {
            wierzcholek tmp = _tablica[i];
            _tablica[i] = _tablica[i*2];
            _tablica[i*2] = tmp;
            i=i*2;
        }
        else {
            wierzcholek tmp = _tablica[i];
            _tablica[i] = _tablica[i*2+1];
            _tablica[i*2+1] = tmp;
            i=i*2+1;
        }
    }
    else
        break;
    }
}
