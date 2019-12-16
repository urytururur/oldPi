#include "lights.h"

int Light::getOn()
{
    return m_on;
}
void Light::setOn(int val)
{
    m_on = val;
}

int Light::getBri()
{
    return m_bri;
}
void Light::setBri(int val)
{
    m_bri = val;
}

int Light::getHue()
{
    return m_hue;
}
void Light::setHue(int val)
{
    m_hue = val;
}

int Light::getSat()
{
    return m_sat;
}
void Light::setSat(int val)
{
    m_sat = val;
}