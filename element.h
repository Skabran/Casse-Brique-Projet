#ifndef ELEMENT_H
#define ELEMENT_H
#include "position.h"

class element{
public:
    element();
    virtual ~element();
    position getPosition() const;


private:
    position d_positionElement;
};

#endif // ELEMENT_H
