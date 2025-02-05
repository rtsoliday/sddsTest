/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
* National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
* Operator of Los Alamos National Laboratory.
* This file is distributed subject to a Software License Agreement found
* in the file LICENSE that is included with this distribution. 
\*************************************************************************/

/*
 $Log: not supported by cvs2svn $
 Revision 1.27  2010/12/03 02:48:33  borland
 Added isort and dsort functions.

 Revision 1.26  2010/02/24 23:50:41  borland
 Added InvFq, which returns q solving F(q)=2*(sqrt(q^2-1)-acos(1/q)).
 See Wiedemann, Particle Accelerator Physics I, 8.2.2

 Revision 1.25  2009/04/27 15:58:55  soliday
 Updated to use the gsl header files.

 Revision 1.24  2009/04/27 14:21:45  borland
 Use GSL functions for modified bessel functions.

 Revision 1.23  2009/03/09 21:27:26  shang
 added strlen function

 Revision 1.22  2006/08/17 02:25:20  borland
 BesKn and BesIn functions now accept fractional orders.

 Revision 1.21  2005/01/13 16:46:16  shang
 renamed strcmp to streq and added strmatch, strgt, strlt

 Revision 1.20  2005/01/10 21:07:56  shang
 added rpn_strcmp function

 Revision 1.19  2003/08/28 20:49:11  soliday
 Cleaned up the code.

 Revision 1.18  2003/07/22 21:02:02  soliday
 IEEE functions are always used.

 Revision 1.17  2003/06/15 17:20:38  borland
 Added modified bessel functions Kn and In.

 Revision 1.16  2003/03/17 23:26:43  borland
 Fixed bugs in previous changes.

 Revision 1.15  2003/03/17 20:10:39  borland
 Added mudf user-callable function to Make UDF from string stack.
 Added simpson user-callable function to do simpson's rule integration.
 Added rpn_internal() to allow evaluating rpn expressions from inside
 interpreter subroutines.

 Revision 1.14  2002/08/14 16:28:58  soliday
 Added Open License

 Revision 1.13  2000/05/09 14:27:12  borland
 Added grndl (gaussian RN with limit) function.

 Revision 1.12  2000/05/08 02:38:38  borland
 Added srnd function for seeding random number generators.

 Revision 1.11  2000/04/21 20:20:53  soliday
 Bessel functions have been added to fdlibm for Borland C so the warning
 messages that existed here were removed.

 Revision 1.10  2000/04/06 22:21:32  soliday
 Added warning message about missing jn and yn functions in Borland C.

 Revision 1.9  1999/12/15 19:01:56  soliday
 Added support for vxWorks.

 Revision 1.8  1999/07/12 20:41:20  soliday
 Added call to fdlibm library for erf, erfc, and lgamma functions on WIN32

 Revision 1.7  1999/07/08 22:23:37  soliday
 Added definition for isnan function. Also added error messages for erf,
 erfc, and lgamma functions on WIN32

 Revision 1.6  1998/08/11 18:27:53  borland
 New version per R. Soliday with true pcoding of UDFs for 4-8 x faster
 evaluation.

 Revision 1.5  1996/11/07 17:05:03  borland
 Changed checks on arguments to poissonSL to allow zero values.

 Revision 1.4  1996/10/30 18:20:12  borland
 Allow number of events to be 0 in poisson significance level calculation.

 Revision 1.3  1996/10/22 18:47:26  borland
 Added built-in function for poisson statistics significance level.

 * Revision 1.2  1995/09/05  21:22:15  saunders
 * First test release of the SDDS1.5 package.
 *
*/
/* prototypes for this file are in math.prot */
/* file    : math.c
 * contents: add(), subtract(), multiply(), divide(), sqrt(), square(),
 *           power(), rpn_sin(), rpn_cos(), rpn_asin(), rpn_acos(), rpn_atan(), rpn_ln(), rpn_ex()
 *           erf(), J0(), J1(), JN(), rpn_cei1(), rpn_cei2(), rpn_int(), rnd(), rpn_atan2()
 *           YN()
 *
 * purpose : user-callable math routines for RPN
 *
 * Michael Borland, 1988
 */
#include "rpn_internal.h"
#include "mdb.h"
#include <time.h>
#ifdef USE_GSL
#include "gsl/gsl_sf_bessel.h"
#include "gsl/gsl_sf_lambert.h"
#ifdef USE_GSL_FRESNEL
#include "gsl/fresnel.h"
#endif
#endif

#if defined(_WIN32) && !defined(__MINGW32__)
#if _MSC_VER <= 1600
#include "fdlibm.h"
#define isnan(x) _isnan(x)
#endif
#endif

#if defined(NAN)
 #define NaN NAN
#elif defined(__GNUC__) && !defined(__INTEL_COMPILER)
 static const double NaN = 0.0 / 0.0;
#elif defined(_WIN32)
 static unsigned _int64 lNaN = ((unsigned _int64) 1 << 63) - 1;
 #define NaN (*(double*)&lNaN)
#else
 static const long long lNaN = ((unsigned long long) 1 << 63) - 1;
 #define NaN (*(double*)&lNaN)
#endif




void rpn_sumn(void)
{
    double sum;
    long count;

    if (stackptr<1) {
        fputs("too few items on stack (sumn)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    count = pop_num();
    if (stackptr<count) {
        fputs("too few items on stack (sumn)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    sum = 0;
    while (count-- > 0)
        sum += pop_num();
    push_num(sum);
}

void rpn_strlen(void)
{
  double len=0;
  if (sstackptr<1) {
    fputs("too few items on string stack (strlen)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  len = strlen(sstack[sstackptr-1]);
  push_num(len);
}

void rpn_streq(void)
{
  if (sstackptr<2) {
    fputs("too few items on string stack (streq)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (!(strcmp(sstack[sstackptr-2],sstack[sstackptr-1])))
    logicstack[lstackptr++] = 1;
  else
    logicstack[lstackptr++] = 0;
}

void rpn_strmatch(void)
{
  if (sstackptr<2) {
    fputs("too few items on string stack (strmatch)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (wild_match(sstack[sstackptr-2],sstack[sstackptr-1]))
    logicstack[lstackptr++] = 1;
  else
    logicstack[lstackptr++] = 0;
}

void rpn_strgt(void)
{
  if (sstackptr<2) {
    fputs("too few items on string stack (strgt)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (strcmp(sstack[sstackptr-2],sstack[sstackptr-1])>0)
    logicstack[lstackptr++] = 1;
  else
    logicstack[lstackptr++] = 0;
}

void rpn_strlt(void)
{
  if (sstackptr<2) {
    fputs("too few items on string stack (strlt)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (strcmp(sstack[sstackptr-2],sstack[sstackptr-1])<0)
    logicstack[lstackptr++] = 1;
  else
    logicstack[lstackptr++] = 0;
}

void rpn_add(void)
{
    if (stackptr<2) {
        fputs("too few items on stack (add)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(pop_num()+pop_num());
    }

void rpn_subtract(void)
{
    double s1;
    if (stackptr<2) {
        fputs("too few items on stack (subtract)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    push_num(pop_num()-s1);
    }

void rpn_multiply(void)
{
  double f1, f2;
  if (stackptr<2) {
    fputs("too few items on stack (multiply)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  f1 = pop_num();
  f2 = pop_num();
#ifdef DEBUG
  fprintf(stderr, "Multiplying %e by %e\n", f1, f2);
#endif
  push_num(f1*f2);
}

void rpn_divide(void)
{
    double s1;
    if (stackptr<2) {
        fputs("too few items on stack (divide)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    if (s1==0) {
        fputs("error: division by zero\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(pop_num()/s1);
    }

void rpn_mod(void)
{
    double s1;
    if (stackptr<2) {
        fputs("too few items on stack (fmod)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    if (s1==0) {
        fputs("error: division by zero\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(fmod(pop_num(), s1));
    }

void rpn_sqrt(void)
{
    double s1;
    if (stackptr<1) {
        fputs("too few items on stack (square_root)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    if (s1<0) {
        fputs("error: square root of negative number\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(sqrt(s1));
    }

void rpn_square(void)
{
    double s1;
    if (stackptr<1) {
        fputs("too few items on stack (square)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    push_num(s1*s1);
    }

void rpn_power(void)
{
    double s1, s2;
    if (stackptr<2) {
        fputs("too few items on stack (power)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    s2 = pop_num();
    if (s2<0) {
        if (s1-((int)s1)!=0) {
            fputs("error: non-integer power of negative number\n", stderr);
            exit(1);
            }
        push_num(ipow(s2, s1));
        }
    else
        push_num(pow(s2, s1));
    }

void rpn_sin(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (sin)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(sin(pop_num()));
    }

void rpn_cos(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (cos)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(cos(pop_num()));
    }

void rpn_atan(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (atan)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(atan(pop_num()));
    }

void rpn_asin(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (asin)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(asin(pop_num()));
    }

void rpn_acos(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (acos)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(acos(pop_num()));
    }

void rpn_ex(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (ex)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(exp(pop_num()));
    }

void rpn_ln(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (ln)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(log(pop_num()));
    }

void rpn_erf(void)
{
#if !defined(vxWorks)
    double x;
#endif

    if (stackptr<1) {
        fputs("too few items on stack (erf)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
#if defined(vxWorks)
    fputs("erf function is not supported on vxWorks (erf)\n", stderr);
    stop();
    rpn_set_error();
    return;
#else
    x = pop_num();
    push_num(erf(x));
#endif
    }

void rpn_erfc(void)
{
#if !defined(vxWorks)
    double x;
#endif

    if (stackptr<1) {
        fputs("too few items on stack (erfc)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
#if defined(vxWorks)
    fputs("erfc function is not supported on vxWorks (erfc)\n", stderr);
    stop();
    rpn_set_error();
    return;
#else
    x = pop_num();
    push_num(erfc(x));
#endif
    }


void rpn_int(void)
{
  double s1;
  if (stackptr<1) {
    fputs("too few items on stack (rpn_int)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  s1 = pop_num();
  if (s1>0)
    push_num((double)((uint64_t)s1));
  else {
    s1 = -s1;
    push_num(-1*((double)((uint64_t)s1)));
  }
}

static long rn_seeded=0;

#define MAXRAND 2147483647

void rpn_srnd(void) 
{
  long seed;
  
  if (stackptr<1) {
    fputs("too few items on stack (srnd)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  seed = (long)pop_num();
  if (seed<=0 || seed>MAXRAND) {
    fputs("seed value must be a positive integer less than 2^31 (srnd)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  random_1(-(2*(seed/2)+1));
  rn_seeded = 1;
}

void rpn_rnd(void)
{
    if (!rn_seeded) {
        random_1(2*(time((time_t)0)/2) + 1);
        random_2(2*(time((time_t)0)/2) + 1);
        rn_seeded = 1;
        }
    push_num(random_1(0));
    }

void rpn_grnd(void)
{
    if (!rn_seeded) {
        random_1(2*(time((time_t)0)/2) + 1);
        random_2(2*(time((time_t)0)/2) + 1);
        rn_seeded = 1;
        }
    push_num(gauss_rn(0, random_2));
    }

void rpn_grndlim(void)
{
  if (stackptr<1) {
    fputs("too few items on stack (grndl)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (!rn_seeded) {
    random_1(2*(time((time_t)0)/2) + 1);
    random_2(2*(time((time_t)0)/2) + 1);
    rn_seeded = 1;
  }
  
  push_num(gauss_rn_lim(0.0, 1.0, pop_num(), random_2));
}

void rpn_JN(void)
{
#if !defined(vxWorks)
     long iorder;
     double x;
#endif

     if (stackptr<2) {
         fputs("too few items on stack (JN)\n", stderr);
         stop();
         rpn_set_error();
         return;
         }
#if defined(vxWorks)
     fputs("jn function is not supported on vxWorks (jn)\n", stderr);
     stop();
     rpn_set_error();
     return;
#else
     iorder = pop_num();
     x = pop_num();
     if (x==23001) {
       push_num(jn(iorder,x));
     }
     else {
       push_num(jn(iorder,x));
     }
#endif
}

void rpn_YN(void)
{
#if !defined(vxWorks)
     long iorder;
     double x;
#endif

     if (stackptr<2) {
         fputs("too few items on stack (YN)\n", stderr);
         stop();
         rpn_set_error();
         return;
         }
#if defined(vxWorks)
     fputs("Yn function is not supported on vxWorks (yn)\n", stderr);
     stop();
     rpn_set_error();
     return;
#else
     iorder = pop_num();
     x = pop_num();
     push_num(yn(iorder, x));
#endif
}

void rpn_KN(void)
{
#if !defined(vxWorks)
  double order;
  double x, result;
#endif
  
  if (stackptr<2) {
    fputs("too few items on stack (Kn)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
#if defined(vxWorks)
  fputs("Kn function is not supported on vxWorks (Kn)\n", stderr);
  stop();
  rpn_set_error();
  return;
#else
  order = pop_num();
  x = pop_num();
  if (order==0) {
    result = dbesk0(x);
  } else if (order==1) {
    result = dbesk1(x);
  } else {
#ifdef USE_GSL
    if (order<0)
      order = -order;
    result = gsl_sf_bessel_Knu(order, x);
#else
  fputs("Kn function was not built with GSL support\n", stderr);
  stop();
  rpn_set_error();
  return;
#endif
  }
  push_num(result);
#endif
}


void rpn_IN(void)
{
#if !defined(vxWorks)
  double order;
  double x, result;
#endif
  
  if (stackptr<2) {
    fputs("too few items on stack (In)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }

#if defined(vxWorks)
  fputs("In function is not supported on vxWorks (In)\n", stderr);
  stop();
  rpn_set_error();
  return;
#else
  order = pop_num();
  x = pop_num();
  if (order==0) {
    result = dbesi0(x);
  } else if (order==1) {
    result = dbesi1(x);
  } else {
#ifdef USE_GSL
    if (order<0)
      order = -order;
    /* Need this code to compensate for issues with gsl_sf_bessel_Inu() domain */
    if (x>0)
      result = gsl_sf_bessel_Inu(order, x);
    else {
      if (((long)fabs(order))%2)
        result = -gsl_sf_bessel_Inu(order, -x);
      else
        result = gsl_sf_bessel_Inu(order, -x);
    }
#else
  fputs("In function was not built with GSL support\n", stderr);
  stop();
  rpn_set_error();
  return;
#endif
  }
  push_num(result);
#endif
}

#ifdef USE_GSL_FRESNEL
void rpn_FresS(void)
{
#if !defined(vxWorks)
  double x, result;
#endif
  
  if (stackptr<1) {
    fputs("too few items on stack (In)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }

#if defined(vxWorks)
  fputs("In function is not supported on vxWorks (In)\n", stderr);
  stop();
  rpn_set_error();
  return;
#else
  x = pop_num();
  result = fresnel_s(x);
  push_num(result);
#endif
}

void rpn_FresC(void)
{
#if !defined(vxWorks)
  double x, result;
#endif
  
  if (stackptr<1) {
    fputs("too few items on stack (In)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }

#if defined(vxWorks)
  fputs("In function is not supported on vxWorks (In)\n", stderr);
  stop();
  rpn_set_error();
  return;
#else
  x = pop_num();
  result = fresnel_c(x);
  push_num(result);
#endif
}
#endif

void rpn_atan2(void)
{
    double x, y;

    if (stackptr<2) {
        fputs("too few items on stack (atan2)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    y = pop_num();
    x = pop_num();
    push_num(atan2(y, x));
    }

void rpn_push_nan(void) {
  push_num(NaN);
}

void rpn_isnan(void)
{
    if (stackptr<1) {
        fputs("too few items on numeric stack (rpn_isnan)\n", stderr);
        rpn_set_error();
        return;
        }
    if (isnan(stack[stackptr-1]))
        push_log(1);
    else
        push_log(0);
    }

void rpn_isinf(void)
{
    if (stackptr<1) {
        fputs("too few items on numeric stack (rpn_isinf)\n", stderr);
        rpn_set_error();
        return;
        }
    if (isinf(stack[stackptr-1]))
        push_log(1);
    else
        push_log(0);
    }

    
void rpn_cei1(void)
{
    double x;

    if (stackptr<1) {
        fputs("too few items on stack (cei1)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    x = pop_num();
    push_num(K_cei(x));
    }

void rpn_cei2(void)
{
    double x;

    if (stackptr<1) {
        fputs("too few items on stack (cei2)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    x = pop_num();
    push_num(E_cei(x));
    }

void rpn_lngam(void)
{
#if !defined(vxWorks)
    double x;
#endif
    
    if (stackptr<1) {
        fputs("too few items on stack (lngam)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
#if defined(vxWorks)
    fputs("lgamma function is not supported on vxWorks (lgamma)\n", stderr);
    stop();
    rpn_set_error();
    return;
#else
    x = pop_num();
    push_num(lgamma(x));
#endif
}

void rpn_betai(void)
{
    double x, a, b;
    
    if (stackptr<3) {
        fputs("too few items on stack (betai)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    b = pop_num();
    a = pop_num();
    x = pop_num();
    if (x<0 || x>1) {
        fputs("x must be on [0, 1] (betai)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(betaInc(a, b, x));
    }

void rpn_gammaP(void)
{
    double x, a;
    
    if (stackptr<2) {
        fputs("too few items on stack (gammaP)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    a = pop_num();
    x = pop_num();
    if (a<=0 || x<0) {
        fputs("Must have a>0 && x>=0 (gammaP)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(gammaP(a, x));
    }

void rpn_gammaQ(void)
{
    double x, a;
    
    if (stackptr<2) {
        fputs("too few items on stack (gammaQ)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    a = pop_num();
    x = pop_num();
    if (a<=0 || x<0) {
        fputs("Must have a>0 && x>=0 (gammaQ)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(gammaQ(a, x));
    }

void rpn_poissonSL(void)
{
  double x0, x;
  
  if (stackptr<2) {
    fputs("too few items on stack (poissonSL)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  x0 = pop_num();
  x = pop_num();
  if (x0<0 || x<0) {
    fputs("Must have x0>=0 && x>=0 (poissonSL)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  push_num(x0=poissonSigLevel((long)x, x0));
}

void rpn_simpson(void)
{
  double xl, xh, dx, n, sum, value;
  char *udfName;
  long i;
  
  if ((udfName=pop_string())==NULL) {
    fputs("Must have UDF name for simpson integration\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (stackptr<3) {
    fputs("too few items on stack (simpson)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  n  = 2*(((long)pop_num())/2);
  if (n<2)
    n = 4;
  xh = pop_num();
  xl = pop_num();
  dx = (xh-xl)/n;
  push_num(xl);
  sum  = (value=rpn_internal(udfName));
#ifdef DEBUG
  fprintf(stderr, "%s(%e) = %e\n", udfName, xl, value);
#endif
  push_num(xh);
  sum += (value=rpn_internal(udfName));
#ifdef DEBUG
  fprintf(stderr, "%s(%e) = %e\n", udfName, xh, value);
#endif
  for (i=1; i<n; i+=2) {
    push_num(xl+i*dx);
    sum += 4*(value=rpn_internal(udfName));
#ifdef DEBUG
    fprintf(stderr, "%s(%e) = %e\n", udfName, xl+i*dx, value);
#endif
    if (i!=n-1) {
      push_num(xl+(i+1)*dx);
      sum += 2*(value=rpn_internal(udfName));
#ifdef DEBUG
      fprintf(stderr, "%s(%e) = %e\n", udfName, xl+(i+1)*dx, value);
#endif
    }
  }
  push_num(sum*dx/3);
}


/* See H. Wiedemann, Particle Accelerator Physics I, 8.2.2 */
double rpn_forwardFq(double q) 
{
  return 2*(sqrt(q*q-1)-acos(1/q));
}


void rpn_inverseFq(void)
{
  double q, F;
  
  if (stackptr<1) {
    fputs("too few items on stack (rpn_inverseFq)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  F = pop_num();
  if (F<=0) {
    fputs("error: F<=0 in rpn_inverseFq\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  q = (F + 2)/2;
  q = zeroNewton(rpn_forwardFq, F, q, 1e-6, 1000, 1e-12);
  push_num(q);
}


/* Sort top <n> items on stack into increasing order */
void rpn_isort_stack(void) 
{
  long i, n;
  double *data;
  
  if (stackptr<1 || (n = pop_num())<=0) {
    fputs("error: isort requires number of items to sort as top item on stack\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (stackptr<n) {
    fprintf(stderr, "error: isort invoked for %ld items, but only %ld items on stack\n",
            n, stackptr);
    stop();
    rpn_set_error();
    return;
  }
  if (!(data=malloc(sizeof(double)*n))) {
    fputs("error: memory allocation failure (isort)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  for (i=0; i<n; i++)
    data[i] = pop_num();
  qsort((void*)data, n, sizeof(*data), double_cmpdes);
  for (i=0; i<n; i++)
    push_num(data[i]);
  free(data);
}

/* Sort top <n> items on stack into decreasing order */
void rpn_dsort_stack(void) 
{
  long i, n;
  double *data;
  
  if (stackptr<1 || (n = pop_num())<=0) {
    fputs("error: isort requires number of items to sort as top item on stack\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if (stackptr<n) {
    fprintf(stderr, "error: isort invoked for %ld items, but only %ld items on stack\n",
            n, stackptr);
    stop();
    rpn_set_error();
    return;
  }
  if (!(data=malloc(sizeof(double)*n))) {
    fputs("error: memory allocation failure (isort)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  for (i=0; i<n; i++)
    data[i] = pop_num();
  qsort((void*)data, n, sizeof(*data), double_cmpasc);
  for (i=0; i<n; i++)
    push_num(data[i]);
  free(data);
}

void rpn_G1y(void)
{
    if (stackptr<1) {
        fputs("too few items on stack (G1y)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    push_num(gy(1, pop_num()));
    }

#ifdef USE_GSL
void rpn_Lambert_W0(void)
{
  double x;
    if (stackptr<1) {
        fputs("too few items on stack (LambertW0)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    if ((x = pop_num())<=-1) {
      fputs("argument out of range (<= -1) for LambertW0\n", stderr);
      stop();
      rpn_set_error();
      return;
    }
    push_num(gsl_sf_lambert_W0(x));
}

void rpn_Lambert_Wm1(void)
{
  double x;
    if (stackptr<1) {
        fputs("too few items on stack (LambertWm1)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    if ((x = pop_num())<=-1) {
      fputs("argument out of range (<= -1) for LambertWm1\n", stderr);
      stop();
      rpn_set_error();
      return;
    }
    push_num(gsl_sf_lambert_Wm1(x));
}
#endif

void rpn_quantumLifetimeSum(void) 
{
  double x, sum, term, k;
  if (stackptr<1) {
    fputs("too few items on stack (quantumLifetimeSum)\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  if ((x = pop_num())<0) {
    fputs("argument out of range (< 0) for quantumLifetimeSum\n", stderr);
    stop();
    rpn_set_error();
    return;
  }
  
  sum = 0;
  if (x>0) {
    k = 1;
    term = 1;
    do {
      term *= x/k;
      sum += term/k;
      k++;
    } while (term/k/sum>1e-16);
  }
  
  push_num(sum);
}

void rpn_floor(void)
{
    double s1;
    if (stackptr<1) {
        fputs("too few items on stack (floor)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    push_num(floor(s1));
    }

void rpn_ceil(void)
{
    double s1;
    if (stackptr<1) {
        fputs("too few items on stack (ceil)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    push_num(ceil(s1));
    }

void rpn_round(void)
{
    double s1;
    if (stackptr<1) {
        fputs("too few items on stack (round)\n", stderr);
        stop();
        rpn_set_error();
        return;
        }
    s1 = pop_num();
    push_num(round(s1));
    }

void rpn_bitand(void)
{
  unsigned long n1, n2;
  if (stackptr<2) {
     fputs("too few items on stack (bit&)\n", stderr);
     stop();
     rpn_set_error();
     return;
  }
  n1 = pop_num();
  n2 = pop_num();
  push_num((double)(n1&n2));
}

void rpn_bitor(void)
{
  unsigned long n1, n2;
  if (stackptr<2) {
     fputs("too few items on stack (bit|)\n", stderr);
     stop();
     rpn_set_error();
     return;
  }
  n1 = pop_num();
  n2 = pop_num();
  push_num((double)(n1&n2));
}

