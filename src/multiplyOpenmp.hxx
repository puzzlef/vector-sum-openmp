#pragma once
#include "_main.hxx"
#include "multiply.hxx"




template <class T>
void multiplyOmp(T *a, const T *x, const T *y, int N) {
  #pragma omp parallel for
  for (int i=0; i<N; i++)
    a[i] = x[i] * y[i];
}

template <class T>
void multiplyOmp(vector<T>& a, const vector<T>& x, const vector<T>& y) {
  multiplyOmp(a.data(), x.data(), y.data(), x.size());
}


template <class T>
float multiplyOpenmp(T *a, const T *x, const T *y, int N, const MultiplyOptions& o={}) {
  int NT = o.numThreads;
  int SK = o.scheduleKind;
  int SC = o.chunkSize;
  omp_set_num_threads(NT);
  omp_set_schedule((omp_sched_t) SK, SC);
  return measureDuration([&] { multiplyOmp(a, x, y, N); }, o.repeat);
}

template <class T>
float multiplyOpenmp(vector<T>& a, const vector<T>& x, const vector<T>& y, const MultiplyOptions& o={}) {
  return multiplyOpenmp(a.data(), x.data(), y.data(), x.size(), o);
}
