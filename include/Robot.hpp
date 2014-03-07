class Robot
{

public:
   Robot (float x, float y);
   float getx (float t);
   float gety (float t);
   void setvx (float vx);
   void setvy (float vy);
   float camera_tel(float bx, float bz);
private:
   float m_vx;
   float m_vy;
   float m_x;
   float m_y;
   float m_t;
};
