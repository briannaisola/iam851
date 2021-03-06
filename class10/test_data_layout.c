
#include <stdio.h>

#define N 3
#define M 4

// implemented in Fortran
void print_matrix_(double *A);

void
print_matrix(double A[N][M])
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf(" %02g", A[i][j]);
    }
    printf("\n");
  }
}

void
print_matrix_linear(double *A, int n)
{
  for (int i = 0; i < n; i++) {
    printf(" %02g", A[i]);
  }
  printf("\n");
}

void
print_matrix_double_pointer(double **A)
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf(" %02g", A[i][j]);
    }
    printf("\n");
  }
}

int
main(int argc, char **argv)
{
  double A[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      A[i][j] = i * 10 + j;
    }
  }

  printf("print_matrix:\n");
  print_matrix(A);
  printf("\n");

  printf("print_matrix_linear:\n");
  print_matrix_linear(&A[0][0], N*M);
  printf("\n");
  
  printf("print_matrix (fortran):\n");
  print_matrix_((double *)A);
  printf("\n");

  return 0;
}
