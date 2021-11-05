#pragma once
#include "_main.hxx"




struct MultiplyOptions {
  int repeat;
  int numThreads;
  int scheduleKind;
  int chunkSize;

  MultiplyOptions(int repeat=1, int numThreads=1, int scheduleKind=omp_sched_static, int chunkSize=64) :
  repeat(repeat), numThreads(numThreads), scheduleKind(scheduleKind), chunkSize(chunkSize) {}
};
