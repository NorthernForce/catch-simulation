#include "../include/Parameters.hpp"
#include <iostream>

float Parameters::k_Kjv;

Parameters::Parameters()
{
    //ctor
    // compute motor joystick-to-velocity gain
   const float rpm=360; // rpm at joystick command of 1
   const float omega= 2*k_Pi*rpm/60;
   const float radius=.5*k_mpf/2; // radius = (0.5 ft diameter) * (0.3049 m/ft) /2
   k_Kjv = omega*radius;

   std::cout << "velocity/stick command =" << k_Kjv << std::endl;
}

Parameters::~Parameters()
{
    //dtor
}
