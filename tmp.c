
#include "sC.h"

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
  printf("Hello tmp.c.\n");

  int len = 1000;
  int N = 1024;

  // Create signal, write to file.
  float signal[len];
  float A = 1;
  float f = 60;
  float fs = 1000;
  for (int i = 0; i < len; i++) {
    signal[i] = sRandNormal(0, 1) + (A * sCos(2 * sPi * f * i / fs));
  }

  FILE* fout = fopen("tmp_signal.txt", "w");
  if (fout == NULL) {
    printf("ERR. No file.\n");
    return 100;
  }

  for (int i = 0; i < len; i++) {
    fprintf(fout, "%d,%3.3f,\n", i, signal[i]);
  }

  fclose(fout);
  
  // Perform FFT, write to file.
  sComplex S[N];
  sDFT(S, signal, len, N);

  fout = fopen("tmp_fft.txt", "w");
  if (fout == NULL) {
    printf("ERR. No file.\n");
    return 100;
  }

  for (int i = 0; i < len; i++) {
    float mag = 10 * sLog10(sComplexMag(&S[i]));
    fprintf(fout, "%d,%3.3f,\n", i, mag);
  }

  fclose(fout);

  return 0;
}
