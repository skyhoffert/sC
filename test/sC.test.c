// Filename: sC.test.c
// Description: Test file for sC library implementation.
// Revision: RevA
// Release Date: 2022-02-17
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Those testing the s library c implementation.

#define ENABLE_S_FAST_TRIG

#include "sC.h"

#include <stdio.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Test Functions

void Test_sBool() {
  printf("==== %s ====\n", __func__);

  int true_is = sTrue;
  int false_is = sFalse;

  printf("1|True: %d\n", true_is);
  printf("0|False: %d\n", false_is);
}

void Test_sRandom() {
  printf("==== %s ====\n", __func__);

  printf("?|float, [0, 1]: %f\n", sRand());
  printf("?|float, [0, 10]: %f\n", sRand()*10);

  printf("0|int  , [0, -1]: %d\n", sRandInt(0, -1));
  printf("0|int  , [0, 0]: %d\n", sRandInt(0, 0));
  printf("?|int  , [0, 1]: %d\n", sRandInt(0, 1));
  printf("?|int  , [0, 9]: %d\n", sRandInt(0, 9));

  printf("?|float, [-1,1] ish: %f\n", sRandNormal(0, 1));
}

void Test_sArithmetic() {
  printf("==== %s ====\n", __func__);

  double a = 0;
  double b = 0;

  a = 2.2;
  b = a * (-1);

  printf("1|Self: %d\n", sAbs(a) == a);
  printf("1|Negated: %d\n", sAbs(b) == a);
  
  a = 3.1415926;
  b = 3.14;

  printf("1|Self: %d\n", sFuzzyEquals(a, a, 0.0000000001));
  printf("0|6 sigs: %d\n", sFuzzyEquals(a, b, 0.000001));
  printf("0|5 sigs: %d\n", sFuzzyEquals(a, b, 0.00001));
  printf("0|4 sigs: %d\n", sFuzzyEquals(a, b, 0.0001));
  printf("0|3 sigs: %d\n", sFuzzyEquals(a, b, 0.001));
  printf("1|2 sigs: %d\n", sFuzzyEquals(a, b, 0.01));
  printf("1|1 sigs: %d\n", sFuzzyEquals(a, b, 0.1));
  printf("1|0 sigs: %d\n", sFuzzyEquals(a, b, 1));

  a = 10;

  double self = sClamp(a, a, a);
  printf("1|Self Clamp: %d\n", self == a);

  double low = sClamp(a, 12, 14);
  printf("1|Low Clamp: %d\n", low > a);

  double high = sClamp(a, 6, 8);
  printf("1|High Clamp: %d\n", high < a);

  double no = sClamp(a, 8, 12);
  printf("1|No Clamp: %d\n", no == a);

  double edge = sClamp(a, 8, 9.999999);
  printf("1|Edge Clamp: %d\n", edge < a);
}

void Test_sDateAndTime() {
  printf("==== %s ====\n", __func__);

  int N = 10;
  char buf[N];
  int retval = -1;

  memset(buf, 0, N);
  retval = sDate(buf);

  printf("Today's Date|Date: %s\n", buf);
  printf("0|Return value: %d\n", retval);
  
  memset(buf, 0, N);
  retval = sDateUTC(buf);

  printf("Today's Date UTC|Date: %s\n", buf);
  printf("0|Return value: %d\n", retval);
  
  memset(buf, 0, N);
  retval = sTime(buf);

  printf("Local Time|Time: %s\n", buf);
  printf("0|Return value: %d\n", retval);

  memset(buf, 0, N);
  retval = sTimeUTC(buf);

  printf("UTC Time|Time: %s\n", buf);
  printf("0|Return value: %d\n", retval);
}

void Test_sFastTrig() {
  printf("==== %s ====\n", __func__);

  // sFastTrigType value = 255;
  // value += 1;

  // printf("?|Value = %d\n", value);

  // // sFastTrigType zero = 0;
  // // uint64_t max = ((uint64_t) zero - 1);
  // int len = pow(2,8);
  // sFastTrigType table[len];
  // sDefineFastCosTable(table);

  // for (int i = 0; i < len; i++) {
  //   printf("%d,", table[i]);
  // }
  // printf("\n");
}

// Test Functions
///////////////////////////////////////////////////////////////////////////////
// Main

int main(int argc, char* argv[]) {
  srand(time(0));

  Test_sBool();
  Test_sRandom();
  Test_sArithmetic();
  Test_sDateAndTime();
  Test_sFastTrig();

  return 0;
}

// Main
///////////////////////////////////////////////////////////////////////////////
