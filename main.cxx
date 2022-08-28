#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <omp.h>
#include "src/main.hxx"

using namespace std;




// You can define datatype with -DTYPE=...
#ifndef TYPE
#define TYPE float
#endif
// You can define number of threads with -DMAX_THREADS=...
#ifndef MAX_THREADS
#define MAX_THREADS 12
#endif




void runSum(int N, int repeat) {
  using T = TYPE;
  vector<T> x(N);

  // Initialize x.
  for (int i=0; i<N; i++) {
    T n = i+1;
    x[i] = 1/(n*n);
  }

  // Find Σx using a single thread.
  do {
    T a = T();
    float t = measureDuration([&]() { a = sumValues(x); }, repeat);
    printf("[%09.3f ms] [%f] sumSeq\n", t, a);
  } while (0);

  // Find Σx accelerated using OpenMP (static schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_static, chunkSize); T a = T();
    float t = measureDuration([&]() { a = sumValuesOmp(x); }, repeat);
    printf("[%09.3f ms] [%f] sumOmp {sch_kind: static, chunk_size: %d}\n", t, a, chunkSize);
  }

  // Find Σx accelerated using OpenMP (dynamic schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_dynamic, chunkSize); T a = T();
    float t = measureDuration([&]() { a = sumValuesOmp(x); }, repeat);
    printf("[%09.3f ms] [%f] sumOmp {sch_kind: dynamic, chunk_size: %d}\n", t, a, chunkSize);
  }

  // Find Σx accelerated using OpenMP (guided schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_guided, chunkSize); T a = T();
    float t = measureDuration([&]() { a = sumValuesOmp(x); }, repeat);
    printf("[%09.3f ms] [%f] sumOmp {sch_kind: guided, chunk_size: %d}\n", t, a, chunkSize);
  }

  // Find Σx accelerated using OpenMP (auto schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_auto, chunkSize); T a = T();
    float t = measureDuration([&]() { a = sumValuesOmp(x); }, repeat);
    printf("[%09.3f ms] [%f] sumOmp {sch_kind: auto, chunk_size: %d}\n", t, a, chunkSize);
  }
}


int main(int argc, char **argv) {
  int repeat = argc>1? stoi(argv[1]) : 5;
  omp_set_num_threads(MAX_THREADS);
  printf("OMP_NUM_THREADS=%d\n", MAX_THREADS);
  for (int N=1000000; N<=1000000000; N*=10) {
    printf("# Elements %.0e\n", (double) N);
    runSum(N, repeat);
    printf("\n");
  }
  return 0;
}
