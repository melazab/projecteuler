#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  long even_terms_sum = 0;

  int temp = 0;
  int previous = 1;
  int current = 2;

  int limit = 4000000;

  while (current < limit) {
    even_terms_sum = (current % 2) ? even_terms_sum : even_terms_sum + current;

    temp = previous;
    previous = current;
    current = current + temp;
  }

  printf("The sum of even-valued Fibonacci numbers below %d is %ld\n", limit,
         even_terms_sum);
  return EXIT_SUCCESS;
}
