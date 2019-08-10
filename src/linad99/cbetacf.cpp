/**
 * Author: David Fournier
 * Copyright (c) 2009, 2010 ADMB Foundation
 */
#include <fvar.hpp>
#include "betacf_val.hpp"

double betacf(const double a, const double b, const double x, int MAXIT){
  typedef double Float;
  return betacf<Float>(a,b,x,MAXIT);
}
