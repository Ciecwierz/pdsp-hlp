/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.9 and Signal Processing Toolbox 8.5.
 * Generated on: 20-Jun-2023 12:34:10
 */

/*
 * Discrete-Time IIR Filter (real)
 * -------------------------------
 * Filter Structure    : Direct-Form II, Second-Order Sections
 * Number of Sections  : 2
 * Stable              : Yes
 * Linear Phase        : No
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2020b\extern\include\tmwtypes.h 
 */
#define MWSPT_NSEC 5
const int NL[MWSPT_NSEC] = { 1,3,1,3,1 };
const real64_T NUM[MWSPT_NSEC][3] = {
  {
     0.3060895130029,                 0,                 0 
  },
  {
                   1,                 2,                 1 
  },
  {
     0.2205394276796,                 0,                 0 
  },
  {
                   1,                 2,                 1 
  },
  {
                   1,                 0,                 0 
  }
};
const int DL[MWSPT_NSEC] = { 1,3,1,3,1 };
const real64_T DEN[MWSPT_NSEC][3] = {
  {
                   1,                 0,                 0 
  },
  {
                   1,  -0.2270502870808,   0.4514083390923 
  },
  {
                   1,                 0,                 0 
  },
  {
                   1,  -0.1635911661136,  0.04574887683194 
  },
  {
                   1,                 0,                 0 
  }
};
