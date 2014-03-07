#ifndef FILTER1_H
#define FILTER1_H


class filter1
{
    public:
        /** Default constructor */
        filter1();
        filter1(float tau, float dt);
        void init(float tau, float dt);
        /** Default destructor */
        virtual ~filter1();
        /** Access m_dt
         * \return The current value of m_dt
         */
        float Getdt() { return m_dt; }
        /** Set m_dt
         * \param val New value to set
         */
        void Setdt(float val) { m_dt = val; }
        /** Access m_tau
         * \return The current value of m_tau
         */
        float Gettau() { return m_tau; }
        /** Set m_tau
         * \param val New value to set
         */
        void Settau(float val) { m_tau = val; }
        /** Access m_alpha
         * \return The current value of m_alpha
         */
        float Getalpha() { return m_alpha; }
        /** Set m_alpha
         * \param val New value to set
         */
        void Setalpha(float val) { m_alpha = val; }
        /** Access m_1mapha
         * \return The current value of m_1mapha
         */
         float Get1malpha() { return m_1malpha; }

         /** Set m_1mapha
         * \param val New value to set
         */
        void Setstate(float val) { m_x = val; }
                /** Access m_1mapha
         * \return The current value of m_1mapha
         */
        float Getstate() { return m_x; }

        /** Update filter
        * \return The updated filter state
        * \param u Filter input
        */
        float update(float u);

    protected:
    private:
        float m_dt; //!< Member variable "m_dt"
        float m_tau; //!< Member variable "m_tau"
        float m_alpha; //!< Member variable "m_alpha"
        float m_1malpha; //!< Member variable "m_1mapha"
        float m_x;
};

#endif // FILTER1_H
