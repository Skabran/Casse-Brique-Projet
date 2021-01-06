#include "enveloppe.h"

enveloppe::enveloppe() : d_pointHG{0,0}, d_pointHD{0,0}, d_pointBG{0,0}, d_pointBD{0,0} {}

enveloppe::enveloppe(const position& coinHG, const position& coinHD, const position& coinBG, const position& coinBD) :
    d_pointHG{coinHG}, d_pointHD{coinHD}, d_pointBG{coinBG}, d_pointBD{coinBD} {}

enveloppe::~enveloppe() {}


position enveloppe::getPointHG() const
{
    return d_pointHG;
}

position enveloppe::getPointHD() const
{
    return d_pointHD;
}

position enveloppe::getPointBG() const
{
    return d_pointBG;
}

position enveloppe::getPointBD() const
{
    return d_pointBD;
}
