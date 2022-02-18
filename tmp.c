
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
  printf("Hello tmp.c.\n");

  double pi = 3.1415926;
  double val = 0.5 * pi;
  double d = cos(val);

  printf("cos(%f) = %f\n", val, d);

  return 0;
}
