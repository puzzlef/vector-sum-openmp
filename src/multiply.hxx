#pragma once
#include <vector>
#include <omp.h>

using std::vector;




template <class T>
void multiply(T *a, const T *x, const T *y, int N) {
  for (int i=0; i<N; i++)
    a[i] = x[i] * y[i];
}

template <class T>
void multiply(vector<T>& a, const vector<T>& x, const vector<T>& y) {
  multiply(a.data(), x.data(), y.data(), x.size());
}


template <class T>
void multiplyOmp(T *a, const T *x, const T *y, int N) {
  #pragma omp parallel for schedule(static,4096)
  for (int i=0; i<N; i++)
    a[i] = x[i] * y[i];
}

template <class T>
void multiplyOmp(vector<T>& a, const vector<T>& x, const vector<T>& y) {
  multiplyOmp(a.data(), x.data(), y.data(), x.size());
}
