#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID()
: p_error_(0.0)
, i_error_(0.0)
, d_error_(0.0)
, last_cte_(0.0)
{}

PID::~PID() {}

void PID::Init(double aKp, double aKi, double aKd)
{
  Kp_ = aKp;
  Ki_ = aKi;
  Kd_ = aKd;
}

void PID::UpdateError(double cte)
{
  p_error_ = cte;
  d_error_ = (cte - last_cte_);
  i_error_ += cte;
  last_cte_ = cte;
}

double PID::TotalError()
{
  return Kp_ * p_error_ + Kd_ * d_error_ + Ki_ * i_error_;
}

