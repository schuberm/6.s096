/*
PROG: matrix
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN 300

typedef struct Matrix_s {
  size_t R, C;
  int index[MAXN][MAXN];
} Matrix;

// %zu is used for reading in a size_t
void read_matrix( FILE *input, Matrix *matrix ) {
  fscanf( input, "%zu %zu", &matrix->R, &matrix->C );

  if( matrix->R > MAXN || matrix->C > MAXN ) {
    printf( "Error: tried to read in a (%zu x %zu) matrix (too large)\n", matrix->R, matrix->C );
    exit( EXIT_FAILURE );
  }

  for( size_t r = 0; r < matrix->R; ++r ) {
    for( size_t c = 0; c < matrix->C; ++c ) {
      fscanf( input, "%d", &matrix->index[r][c] );
    }
  }
}

void print_matrix( FILE *output, Matrix *matrix ) {
	fprintf( output, "%zu %zu\n", matrix->R, matrix->C );
  for( size_t r = 0; r < matrix->R; ++r ) {
    for( size_t c = 0; c < matrix->C - 1; ++c ) {
      fprintf( output, "%d ", matrix->index[r][c] );
    }
    fprintf( output, "%d\n", matrix->index[r][matrix->C - 1] );
  }
}

void product_matrix( Matrix *a, Matrix *b, Matrix *product ) {
  /* This is the part for you to do:
   * function product_matrix should write the product of "a" and "b"
   * into the provided matrix "product".
   */
  for( size_t r = 0; r < a->R; ++r ) {
    for( size_t c = 0; c < b->C; ++c ) {
      for( size_t i = 0; i < a->C; ++i ) {
          product->index[r][c]+=a->index[r][i]*b->index[i][c];
      }
    }
  }
}

int main(void) {
  FILE *fin = fopen( "matrix.in", "r" );

  if( fin == NULL ) {
    printf( "Error: could not open matrix.in\n" );
    exit( EXIT_FAILURE );
  }

  Matrix a, b, c;
  read_matrix( fin, &a );
  read_matrix( fin, &b );
  fclose( fin );

  product_matrix( &a, &b, &c );

  FILE *output = fopen( "matrix.out", "w" );

  if( output == NULL ) {
    printf( "Error: could not open matrix.out\n" );
    exit( EXIT_FAILURE );
  }

  print_matrix( output, &c );
  fclose( output );

  return 0;
}
