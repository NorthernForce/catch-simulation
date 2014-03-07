#include "../include/Ball.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include "../include/Parameters.hpp"

using namespace std;

Ball::Ball(float x, float vx, float vz) :
    m_vx(vx),m_vz(vz),m_x(x),m_z(0.0)
{
   cout <<"creating ball vx,vz="<<m_vx<<", "<<m_vz<<endl;

}
float Ball::getx(float t) const
{
   float x=m_x+m_vx*t;
   return x;
}
float Ball::getz(float t)const
{
   float z=(m_vz*t)-(0.5*std::pow(t,2)*Parameters::k_g);
   return z;
}
