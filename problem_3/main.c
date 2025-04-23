#include <stdio.h>
#include <stdlib.h>

#define LONG_ASS_NUMBER 600851475143

int largest_prime_factor(long n);

int main(void) {
    printf("The largest prime factor of %ld is %d\n", LONG_ASS_NUMBER, largest_prime_factor(LONG_ASS_NUMBER));
    return EXIT_SUCCESS;
}

int largest_prime_factor(long n) {
  int divisor = 2;
  while (n >= divisor * divisor) {
    if (n % divisor != 0) {
      divisor++;
    } else {
      n = n / divisor;
    }
  }
  return n;
}
