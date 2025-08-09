#include <stdio.h>

float function(float x) {
  return x * x * x - x - 1; // Example function f(x) = x^3 - x - 1
}

int main() {
  float a, b, mid;
  float tol = 0.0001;

  printf("Enter interval [a,b]: ");
  scanf("%f %f", &a, &b);

  while ((b - a) >= tol) {
    mid = (a + b) / 2;

    if (function(mid) == 0.0)
      break;

    else if (function(mid) * function(a) < 0)
      b = mid;

    else
      a = mid;
  }

  printf("Root is: %f\n", mid);

  return 0;
}
