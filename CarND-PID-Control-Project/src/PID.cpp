#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

     Kp = Kp;
     Ki = Ki;
     Kd = Kd;

     initialized_ = false;

}

void PID::UpdateError(double cte) {

     if(!initialized_){
	     d_error = 0;
	     p_error = -cte;
	     i_error = -cte;

	     initialized_ = true;
     }else{
	     d_error = -cte - p_error;
	     p_error = -cte;
	     i_error += -cte;
     }
     total_error = Kp * p_error + Kd * d_error + Ki * i_error;
}



double PID::TotalError() {
	return Kp * p_error + Kd * d_error + Ki * i_error;
}

