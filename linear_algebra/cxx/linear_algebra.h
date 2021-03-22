
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>

#define BOUNDS_CHECK

#include <vector>

class vector
{
public:
  vector(int n);

  int size() const;
  double operator()(int i) const;
  double& operator()(int i);

  void print() const;

private:
  std::vector<double> data_;
};

class matrix
{
public:
  matrix(int m, int n);

  void print() const;

  double operator()(int i, int j) const;
  double& operator()(int i, int j);

  int m, n;

private:
  std::vector<double> data_;
};

bool matrix_is_equal(const matrix& A, const matrix& B);
bool vector_is_equal(const vector& x, const vector& y);
double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
