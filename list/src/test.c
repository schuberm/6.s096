#include "list.h"
#include <stdio.h>

int sq( int x ) {
  return x * x;
}

int plus( int x, int y ) {
  return x + y;
}

int main(void) {
  int N = 5;
  int result=0;
  List list = empty_list();

  for( int i = 0; i < N; ++i ) {
    list_append( &list, i );
  }

  list_insert_before(&list, -1, 4);
  list_delete(&list, 4);

  int (*function_ptr)(int);
  function_ptr = &sq;
  //list_apply(&list,*function_ptr);

  int (*function_ptr2)(int,int);
  function_ptr2 = &plus;
  //result=list_reduce(&list,*function_ptr2);
  //printf("%i\n",result);

  list_print( list );
  list_clear( &list );
  return 0;
}
