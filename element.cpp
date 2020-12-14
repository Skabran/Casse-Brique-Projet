#include "element.h"
#include "position.h"

element::element(): d_positionElement{} {}

element::element(double x, double y) : d_positionElement{x, y} {}

element::~element() = default;

position element::getPosition() const{
    return d_positionElement;
}
