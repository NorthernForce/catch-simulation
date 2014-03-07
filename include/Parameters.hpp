#ifndef PARAMETERS_H
#define PARAMETERS_H


class Parameters
{
    public:
        /** Default constructor */
        Parameters();
        /** Default destructor */
        virtual ~Parameters();

        static float const k_g=9.8; //!< Member variable "k_g=9.8"

        static float const k_Pi=3.1415926;
        static float const k_mpf=.3048;

        static float k_Kjv;

    protected:
    private:
};

#endif // PARAMETERS_H
