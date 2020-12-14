#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

class element{
public:
    element();
    element(double x, double y);
    virtual ~element();
    position getPosition() const;
    virtual void collision() = 0;


private:
    position d_positionElement;
};

#endif // ELEMENT_H
