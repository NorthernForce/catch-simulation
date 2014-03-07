class Ball
{

public:
   Ball (float x, float vx, float vz); //assume (Px,Py) = (0,0)
   float getx(float t)const;
   float getz(float t)const;
private:
   float m_vx;
   float m_vz;
   float m_x;
   float m_z;
};
