#include "filter1.hpp"

class Control
{
    public:
        /** Default constructor */
        Control();

        /** Construct with Gain and dt */
        Control(float K, float dt);

        virtual ~Control() {};

        /** Access m_State
         * \return The current value of m_State
         */
        int GetState() { return m_State; }
        /** Set m_State
         * \param val New value to set
         */
        void SetState(int val) { m_State = val; }
        /** Access m_TelLast
         * \return The current value of m_TelLast
         */
        float GetTelLast() { return m_TelLast; }
        /** Set m_TelLast
         * \param val New value to set
         */
        void SetTelLast(float val) { m_TelLast = val; }
        /** Access m_dTeldt
         * \return The current value of m_dTeldt
         */
        float GetdTeldt() { return m_dTeldt; }
        /** Set m_dTeldt
         * \param val New value to set
         */
        void SetdTeldt(float val) { m_dTeldt = val; }
        /** Access m_dTeldt0
         * \return The current value of m_dTeldt0
         */
        float GetdTeldt0() { return m_dTeldt0; }
        /** Set m_dTeldt0
         * \param val New value to set
         */
        /** Access m_TelLast
         * \return The current value of m_TelLast
         */

        /** Set m_vxball_est
         * \param val New value to set
         */
        void Setvxball_est(float val) { m_vxball_est = val; }
        /** Access m_vxball_est
         * \return The current value of m_vxball_est
         */
        float Getvxball_est() { return m_vxball_est; }

        void SetdTeldt0(float val) { m_dTeldt0 = val; }

        float GetK() { return m_K; }
        /** Set m_K
         * \param val New value to set
         */
        void SetK(float val) { m_K = val; }

        /** Access m_dt
         * \return The current value of m_dt
         */
        float Getdt() { return m_dt; }

        /** Set m_dt
         * \param dt New value to set
         */
        void Setdt(float dt) { m_dt = dt; fdteldt.Setdt(dt); }

        void Settau(float tau) { fdteldt.Settau(tau); }

        float Gettau() { return fdteldt.Gettau(); }


        float Update(float tel);

    protected:
    private:
        int m_State; //!< Member variable "m_State"
        float m_TelLast; //!< Member variable "m_TelLast"
        float m_dTeldt; //!< Member variable "m_dTeldt"
        float m_dTeldt0; //!< Member variable "m_dTeldt0"
        float m_K; //! Feedback Gain
        float m_dt;
        float m_vxball_est; // Best initial guess for initial ball velocity
        filter1 fdteldt;

};

