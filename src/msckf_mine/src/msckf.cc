#include "msckf.h"

namespace MSCKF_MINE
{

MSCKF::MSCKF()
{
    cout << "allll" << endl;
}

MSCKF::MSCKF(const VectorXd &state, const MatrixXd &P, const Vector3d &Acc, const Vector3d &Gyro, double &dt)
{
    /*initializing all the variables*/
    /*actually we need to check the num of the variaables*/
    this->mState = state;
    this->mConvariance = P;
    this->mAccMeasurement = Acc;
    this->mGyroMeasurement = Gyro;
    this->mdt = dt;


}

MSCKF::~MSCKF()
{

}



Matrix4d MSCKF::BigOmega( const Vector3d &w){
    //constructing big omega matrix
     Matrix4d W= Matrix4d::Zero();
     W.block<3,3>(0,0)  = -1*skewMatrix(w) ;
     W.block<1,3>(3,0)  =  -w.transpose();
     W.block<3,1>(0,3)  =  w;
    // W(3,3) = 0.0;

     return W;

}

Matrix3d MSCKF::skewMatrix( const Vector3d &v){

    Matrix3d skewV;
    skewV << 0, -v(2) , v(1),
            v(2), 0 , -v(0),
            -v(1), v(0),  0;

    return skewV;

}



}