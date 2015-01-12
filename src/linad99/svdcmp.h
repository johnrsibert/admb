/*
 * $Id$
 *
 * Author: David Fournier
 * Copyright (c) 2008-2011 Regents of the University of California
 * 
 * ADModelbuilder and associated libraries and documentations are
 * provided under the general terms of the "BSD" license.
 * 
 * License:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2.  Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * 3.  Neither the name of the  University of California, Otter Research,
 * nor the ADMB Foundation nor the names of its contributors may be used
 * to endorse or promote products derived from this software without
 * specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 * \file
 * Description not yet available.
 */
#if !defined(_SVDCMP_)
#define _SVDCMP_ 

#include <fvar.hpp>


double pythag(double a, double b);
double fmax(double a,double b) { if (a>b) return a; else return b;}
double imin(int a,int b) { if (a>b) return b; else return a;}
double sign(double a,double b){ if (b>0) return fabs(a); else return -fabs(a);}

dvariable pythag(_CONST prevariable& a, double b);
dvariable pythag(_CONST prevariable& a, _CONST prevariable& b);
dvariable fmax(BOR_CONST prevariable& a,BOR_CONST prevariable& b) { if (a>b) return a; else return b;}
dvariable sign(BOR_CONST prevariable& a,BOR_CONST prevariable& b){ if (b>0) return fabs(a); else return -fabs(a);}

/**
 * Description not yet available.
 * \param
 */
class d_singular_value_decomposition
{
public:
  dmatrix a;
  dvector w;
  dmatrix v;
  d_singular_value_decomposition(int m,int n) :
    a(1,m,1,n), w(1,n), v(1,n,1,n) {}
};

/**
 * Description not yet available.
 * \param
 */
class dvar_singular_value_decomposition
{
public:
  dvar_matrix a;
  dvar_vector w;
  dvar_matrix v;
  dvar_singular_value_decomposition(int m,int n) :
    a(1,m,1,n), w(1,n), v(1,n,1,n) {}
};

d_singular_value_decomposition svdcmp(BOR_CONST dmatrix& a1);
dvar_singular_value_decomposition svdcmp(BOR_CONST dvar_matrix& a1);

#endif