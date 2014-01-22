/*
PROG: matrix2
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

typedef struct Matrix_s {
  size_t R, C;
  int *index;
} Matrix;

Matrix* allocate_matrix( size_t R, size_t C ) {
	/* Write a function returning a new matrix
	 * of size R x C.
	 */
	return NULL;
}

void destroy_matrix( Matrix *matrix ) {
	/* Write a function to properly free the memory
	 * held by 'matrix'
	 */
}

// %zu is used for reading in a size_t
Matrix* read_matrix( FILE *input ) {
	size_t R, C;
  fscanf( input, "%zu %zu", &R, &C );

  if( R > MAXN || C > MAXN ) {
    printf( "Error: tried to read in a (%zu x %zu) matrix (too large)\n", R, C );
    exit( EXIT_FAILURE );
  }

	Matrix *matrix = allocate_matrix( R, C );

  for( size_t r = 0; r < matrix->R; ++r ) {
    for( size_t c = 0; c < matrix->C; ++c ) {
      fscanf( input, "%d", &matrix->index[c + r * C] );
    }
  }

	return matrix;
}

void print_matrix( FILE *output, Matrix *matrix ) {
	fprintf( output, "%zu %zu\n", matrix->R, matrix->C );
  for( size_t r = 0; r < matrix->R; ++r ) {
    for( size_t c = 0; c < matrix->C - 1; ++c ) {
      fprintf( output, "%d ", matrix->index[c + r * matrix->C] );
    }
    fprintf( output, "%d\n", matrix->index[matrix->C - 1 + r * matrix->C] );
  }
}

Matrix* product_matrix( Matrix *a, Matrix *b ) {
  /* This is the part for you to do:
   * function product_matrix should write the product of "a" and "b"
   * into a newly allocated matrix "product".
   */
	return NULL;
}

int main(void) {
  FILE *fin = fopen( "matrix2.in", "r" );

  if( fin == NULL ) {
    printf( "Error: could not open matrix2.in\n" );
    exit( EXIT_FAILURE );
  }

  Matrix *a = read_matrix( fin );
  Matrix *b = read_matrix( fin );
  fclose( fin );

  Matrix *c = product_matrix( a, b );

  FILE *output = fopen( "matrix2.out", "w" );

  if( output == NULL ) {
    printf( "Error: could not open matrix2.out\n" );
    exit( EXIT_FAILURE );
  }

  print_matrix( output, c );
  fclose( output );

	destroy_matrix( a );
	destroy_matrix( b );
	destroy_matrix( c );

  return 0;
}
