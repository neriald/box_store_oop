#ifndef BOX_H
#define BOX_H
#include <iostream>

using namespace std;

class Box
{
    string label,color;
    static int counter;

public:

    Box(string _label, string _color): label(_label), color(_color) {counter++;}
    virtual ~Box() {counter--;}

    string getLabel() const {return label;}
    static int count() {return counter;}
    virtual double getVolume() const =0;
};

class BrickBox: public Box
{
    double len,wid,hei;

public:

    BrickBox(string _label, string _color, double _len, double _wid, double _hei): Box(_label,_color), len(_len), wid(_wid), hei(_hei) {}
    virtual ~BrickBox() {}
    virtual double getVolume() const;
};

class TubeBox: public Box
{
    double r,h;

public:

    TubeBox(string _label, string _color, double radi, double heigh): Box(_label,_color), r(radi), h(heigh) {}
    virtual ~TubeBox() {}
    virtual double getVolume() const;
};

class BubbleBox: public Box
{
    double r;

public:

    BubbleBox(string _label, string _color, double radi): Box(_label,_color), r(radi) {}
    virtual ~BubbleBox() {}
    virtual double getVolume() const;
};
#endif // BOX_H
