#ifndef BRIQUE_H
#define BRIQUE_H
#include "element.h"

class brique : public element{
public:
    brique();
    brique(double x, double y);
    ~brique();
    void collision() override;
};

#endif // BRIQUE_H

/*
class brique : public rectangle
{
    public:
        bool detruite() = false;
        brique(double coordX, double coordY);
};
*/
