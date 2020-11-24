#include "element.h"
#include "position.h"

element::element(): d_positionElement{} {}

element::~element() = default;

position element::getPosition() const{
    return d_positionElement;
}
