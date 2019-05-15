#include "krawedz.h"

krawedz::krawedz(int dlugoscKrawedzi, int wierzcholekA, int wierzcholekB) :
    _dlugoscKrawedzi(dlugoscKrawedzi), _wierzcholekA(wierzcholekA), _wierzcholekB(wierzcholekB)
{
    _iloscKrawedzi++;
    _idKrawedzi=_iloscKrawedzi;
}

int krawedz::_iloscKrawedzi=0;
