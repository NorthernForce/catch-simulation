#include "../include/filter1.hpp"

filter1::filter1()
{
    //ctor
    init(0.0,1.0);
}

filter1::filter1(float tau, float dt)
{
    init(tau,dt);
}

filter1::~filter1()
{
    //dtor
}

void filter1::init(float tau, float dt)
{
    m_tau = tau;
    m_dt = dt;
    m_alpha = 1.0 - dt/tau;
    m_1malpha = dt/tau;

}

float filter1::update(float u)
{
    m_alpha = 1.0 - m_dt/m_tau;
    m_1malpha = m_dt/m_tau;
    float val = m_alpha*m_x + m_1malpha*u;
    m_x = val;
    return val;
}
