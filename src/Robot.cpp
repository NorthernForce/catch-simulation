#include "../include/Robot.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Robot::Robot (float x, float y) :
   m_vx(0.0), m_vy(0.0), m_x(x), m_y(y), m_t(0.0)
{
    cout<<"creating robot x,vx="<<m_x<<", "<<m_vx<<endl;
}


float Robot::getx(float t)
{
    m_x=m_x+m_vx*(t-m_t);
    m_t=t;
    return m_x;
}

float Robot::gety(float t)
{
    m_y=m_y+m_vy*(t-m_t);
    m_t=t;
    return m_y;
}

void Robot::setvx (float vx)
{
    m_vx=vx;
}

void Robot::setvy (float vy)
{
    m_vy=vy;
}

float Robot::camera_tel(float bx, float bz)
{
    return bz/(bx-m_x);

}

