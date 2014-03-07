#include "../include/Control.hpp"
#include "../include/Parameters.hpp"

Control::Control() : fdteldt(0.0,1.0)
{
    // Set state machine to start state
    m_State = 0;
    m_K=1.0;
    m_dt=1.0;
    m_dTeldt=0.0;
    m_dTeldt0=0.0;
    m_vxball_est=0.0;
}

Control::Control(float K, float dt) : fdteldt(0.3,dt)
{
    // Set state to start, K and dt
    m_State = 0;
    m_K = K;
    m_dt=dt;
    m_dTeldt=0.0;
    m_dTeldt0=0.0;
    m_vxball_est=0.0;
}

float Control::Update(float tel) {
    float y; // joystick command
    float diff; //
    switch(m_State) {
    case 0:
        m_TelLast = tel;
        y = 0;
        m_State=1;
        break;
    case 1:
        m_dTeldt0 = (tel - m_TelLast)/m_dt;
        m_TelLast = tel;
        y=0.0;
        m_State=2;
        break;
    case 2:
        m_dTeldt = (tel - m_TelLast)/m_dt;
        m_TelLast = tel;
        diff = m_dTeldt - m_dTeldt0;
        fdteldt.Setstate(diff);
        y = m_K*diff;
        m_State=3;
        break;
    case 3:
        m_dTeldt = (tel - m_TelLast)/m_dt;
        m_TelLast = tel;
        diff = m_dTeldt - m_dTeldt0;
        y = m_K*fdteldt.update(diff);
        break;
        m_State=3;
    default:
        m_State=0;
        y = 0;
    }
    return y;
}
