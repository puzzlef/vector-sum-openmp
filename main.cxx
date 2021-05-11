#include <vector>
#include <cstdlib>
#include <cstdio>
#include "src/main.hxx"

using namespace std;




void runMultiply(int N) {
  int repeat = 5;
  vector<float> a1(N), a2(N);
  vector<float> x(N), y(N);
  for (int i=0; i<N; i++) {
    x[i] = float(rand())/RAND_MAX;
    y[i] = float(rand())/RAND_MAX;
  }

  // Find x*y using a single thread.
  float t1 = measureDuration([&]() { multiply(a1, x, y); }, repeat);
  printf("[%09.3f ms; %.0e elems.] multiply\n", t1, (float) N);

  // Find x*y accelerated using OpenMP.
  float t2 = measureDuration([&]() { multiplyOmp(a2, x, y); }, repeat);
  printf("[%09.3f ms; %.0e elems.] multiplyOmp\n", t1, (float) N);
}


int main(int argc, char **argv) {
  for (int n=10000; n<=1000000000; n*=10) {
    runMultiply(n);
    printf("\n");
  }
  return 0;
}
