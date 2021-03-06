/**
 * \file      rigid-body-kinematics.hpp
 * \author    Mehdi Benallegue
 * \date       2013
 * \brief      Implements integrators for the kinematics, in terms or rotations
 *             and translations.
 *
 * \details
 *
 *
 */


#ifndef StATEOBSERVATIONRIGIDBODYKINEMATICS_H
#define StATEOBSERVATIONRIGIDBODYKINEMATICS_H

#include <state-observation/tools/definitions.hpp>
#include <state-observation/tools/miscellaneous-algorithms.hpp>

namespace stateObservation
{
    namespace algorithm
    {

        /**
        * \class  RigidBodyKinematics
        * \brief  Implements the integrator of the linear acceleration and the
        *         rotation acceleration of any rigid body. The class is to be
        *         privately derived to use the algorithm. The class does not store
        *         any object.
        *
        *
        */

        class RigidBodyKinematics
        {
        public:
            RigidBodyKinematics()
            {
#ifdef STATEOBSERVATION_VERBOUS_CONSTRUCTORS
        std::cout<<std::endl<<"DynamicalSystemFunctorBase Constructor"<<std::endl;
#endif //STATEOBSERVATION_VERBOUS_CONSTRUCTORS
            }

            ///integrates the position/orientation and their time derivatives, given the
            ///accelerations, and initial velocities and positions.
            void integrateKinematics
            (Vector3 & position, Vector3 & velocity, const Vector3 & acceleration,
             Matrix3 & orientation, Vector3 & rotationVelocity,
             const Vector3 & rotationAcceleration, double dt);

            ///integrates the position/orientation and their time derivatives, given the
            ///accelerations, and initial velocities and positions.
            void integrateKinematics
            (Vector3 & position, Vector3 & velocity, const Vector3 & acceleration,
             Quaternion & orientation, Vector3 & rotationVelocity,
             const Vector3 & rotationAcceleration, double dt);

             ///integrates the postition/orientation given the velocities
             void integrateConfiguration(Vector3 & position, const Vector3 & velocity,
             Matrix3 & orientation, const Vector3 & rotationVelocity, double dt);



        protected:
        private:
        };
    }
}

#include <state-observation/dynamical-system/algorithm/rigid-body-kinematics.hxx>

#endif // StATEOBSERVATIONRIGIDBODYKINEMATICS_H
