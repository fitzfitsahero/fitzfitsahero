#include <stdio.h>
#include <stdint.h>

inline uint64_t rdtsc()
{
  uint64_t lo,hi;
  __asm__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ((uint64_t)lo) | (((uint64_t)hi) << 32);
}

void main()
{
  uint64_t start, stop;

  start = rdtsc();
  stop = rdtsc();

  printf("Time: %llu\n", stop - start);
}
