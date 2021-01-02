#include "element.h"
#include "position.h"

element::element(): d_positionElement{} {}

element::element(double x, double y) : d_positionElement{x, y} {}

element::element(position pos): d_positionElement{pos} {}

element::~element() = default;

position element::getPosition() const{
    return d_positionElement;
}


void element::changePosition(const position& pos)
{
    d_positionElement=pos;
}
