#include <stdio.h>
#include <stdlib.h>

struct Multiples {
  int *elements;
  int num;
  long sum;
};

struct Multiples *get_multiples(int x, int upper_lim);
void free_multiples(struct Multiples *mul);

int main(int argc, char *argv[]) {

  int target = 1000;
  struct Multiples *mul_of_three_below_target = get_multiples(3, target);
  struct Multiples *mul_of_five_below_target = get_multiples(5, target);
  struct Multiples *mul_of_fifteen_below_target = get_multiples(15, target);
  long sum_of_both_muls = (mul_of_five_below_target->sum) +
                          (mul_of_three_below_target->sum) -
                          (mul_of_fifteen_below_target->sum);
  printf("The sum of multiples of 3 or 5 below %d is %ld\n", target,
         sum_of_both_muls);

  free_multiples(mul_of_three_below_target);
  free_multiples(mul_of_five_below_target);
  free_multiples(mul_of_fifteen_below_target);

  return EXIT_SUCCESS;
}

struct Multiples *get_multiples(int x, int upper_lim) {

  if (x <= 0 || x > upper_lim) {
    fprintf(stderr, "Error: invalid parameter.\n");
    return NULL;
  }

  int num_of_elements = (upper_lim - 1) / x;

  struct Multiples *mul = malloc(sizeof(struct Multiples));

  if (mul == NULL) {
    fprintf(stderr, "Error: malloc failed!\n");
    return NULL;
  }

  mul->elements = malloc(num_of_elements * sizeof(int));

  if (mul->elements == NULL) {
    fprintf(stderr, "Error: malloc failed!\n");
    free(mul);
    return NULL;
  }

  mul->num = num_of_elements;
  mul->sum = 0;

  int i;
  for (i = 0; i < mul->num; i++) {
    (mul->elements)[i] = (i + 1) * x;
    mul->sum = (mul->sum) + (mul->elements)[i];
  }

  return mul;
}

void free_multiples(struct Multiples *mul) {
  if (mul != NULL) {
    if (mul->elements != NULL) {
      free(mul->elements);
    }
    free(mul);
  }
}
