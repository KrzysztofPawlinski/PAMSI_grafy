#ifndef WIERZCHOLEK_H
#define WIERZCHOLEK_H


class wierzcholek
{
public:
    wierzcholek();
    wierzcholek(int numerWierzcholka, int kosztDojscia, int numerPoprzednika);
    int _numerWierzcholka;
    int _kosztDojscia;
    int _numerPoprzednika;
    bool operator < (wierzcholek &arg) {
            return (_kosztDojscia<arg._kosztDojscia);

    }
};

#endif // WIERZCHOLEK_H
