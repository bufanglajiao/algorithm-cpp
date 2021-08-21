//
// Created by 10991 on 2021/8/20.
//
#include "../include/factorial.h"

unsigned int Factorial(unsigned int n){
  if (n == 0) {
    return 1; // f(0) = 1
  } else {
    return n * Factorial(n - 1); // f(n) = nf(n-1)
  }
}
unsigned int FactorialByIteration(unsigned int n){
  unsigned int result = 1;
  for (unsigned int i = n; i > 0; --i) {
    result *= i;
  }
  return result;
}
