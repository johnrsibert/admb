/**
\file
Author: David Fournier
Copyright (c) 2008-2015 Regents of the University of California
*/
#include "fvar.hpp"

/// Default constructor
d4_array::d4_array()
{
  allocate();
}
/// Does not allocate, but initializes pointers to NULL.
void d4_array::allocate()
{
  shape = NULL;
  t = NULL;
}
