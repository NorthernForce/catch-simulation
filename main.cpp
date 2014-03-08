#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "include/Parameters.hpp"
#include "include/Ball.hpp"
#include "include/Robot.hpp"
#include "include/Control.hpp"
#include "include/Parameters.hpp"

using namespace std;


int main()
{

   Parameters p;

   float t;
   float tend = 1.7;
   float dt = 0.0333;
   float x;
   float ry;
   float z;
   float rx;
   float tel,tel_last;
   float dtel;
   float camera_angle = 0*0.0175; // 0 degree up
   // float const ns = 0.006; // 1/120 of 40 degree fov
   // float const ns = .0175; // 1 degree noise
   // float const ns = 5*.0175;  // 5 degree noise
   float const ns = 0;


   Ball b (10.36,-7.12488,7.12488);
   Robot r (1.0,0);
   Control c;
   c.SetK(2.0);
   c.Setdt(dt);
   c.Settau(0.3);
   c.Setvxball_est(-7.124880);

   ofstream test("dataPoints.csv");


   test << "\"time\",\"ball x\",\"ball z\",\"robot x\",\"robot y\",\"tan-el\","
           << "\"dtan-el\",\"feedback\"" << endl;

   srand(12354);

   dtel=0.0;
   tel_last=0.0;

   float tca = tan(camera_angle);

   cout << "K=" << c.GetK()<< endl;
   cout << "dt=" << c.Getdt() << endl;
   cout << "RAND_MAX" << RAND_MAX << endl;

   for (t=0.0; t<tend; t=t+dt)
   {
       x=b.getx(t);
       z=b.getz(t);
       rx=r.getx(t);
       ry=r.gety(t);
       tel=r.camera_tel(x,z);
       // simulate camera pointing angle error
       //  using tangent-of-sum trig identity
       tel = (tel + tca)/(1.0-tca*tel);

       dtel=(tel-tel_last)/dt;
       tel_last=tel;

       float randu = (float)rand()/RAND_MAX - 0.5;
       float noise = (1.0 + tel*tel)*ns*randu;

       float feedback = c.Update(tel + noise);

       // need a +/- limit fucntion

       feedback = (feedback>  1.0) ? 1.0 : feedback;
       feedback = (feedback< -1.0) ? -1.0 : feedback;

       r.setvx(-feedback*Parameters::k_Kjv);

       test << t << ", " << x << ", " << z << ", " << rx << ", " << ry << ", " << tel
                 << ", " << dtel << ", " << feedback << endl;

       if ((pow((rx-x),2)+pow(z,2))< 0.3048*0.3048) { break; } // at .1 m robot-to-ball
   }

   return 0;

}
