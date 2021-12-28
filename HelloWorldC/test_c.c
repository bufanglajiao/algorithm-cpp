#include <stdio.h>
#include <math.h>

void main() {
  double number;
  scanf("%lf", &number);
  int i = 1;
  double s = 0, t = 1.0;
  while(fabs(t)>=1e-5){
    s+=t;
    t*=(-1)*number*number/(number*(number+1));
    i+=2;
  }
}