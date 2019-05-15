#ifndef KRAWEDZ_H
#define KRAWEDZ_H


class krawedz
{
public:
    krawedz();
    krawedz(int dlugoscKrawedzi, int wierzcholekA, int wierzcholekB);
    int _dlugoscKrawedzi;
    int _idKrawedzi;
    int _wierzcholekA;
    int _wierzcholekB;
    static int _iloscKrawedzi;
};

#endif // KRAWEDZ_H
