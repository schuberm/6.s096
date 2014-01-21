#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct List_node_s {
  List_node *next;
  int value;
};

List empty_list( void ) {
  return (List) { .length = 0, .front = NULL };
}

// Allocate memory for a single List_node
List_node* create_node( int value ) {
  List_node *new_node = malloc( sizeof( List_node ) );
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

// Implement this
void list_append( List *list, int value ) {
  /* Function to append a new node containing 'value'
   * to the end of List *list. For example,
   * applied to { 5 -> 10 } as
   * list_append( list, 9 ); results in
   * { 5 -> 10 -> 9 }
   */

  List_node *p = list->front;
  size_t length = list->length;
  if( list->front == NULL ) {

    list->front=create_node(value);
    list->length=length+1;
  }
  else{
  while( p->next != NULL && length > 0) {
      //printf( "%d -> ", p->value );
      p = p->next;
  }
  
  p->next=create_node(value);
  list->length=length+1;
  }
}

// Implement this
void list_insert_before( List *list, int insert, int before ) {
  /* This function should take a pointer to a List *list,
   * a value to insert 'insert', and a value to insert before 'before'.
   * A new node should be inserted directly before the first
   * occurrence of "before" in the current list, like so:
   *
   * Starting with { 0 -> 5 -> 4 -> 5 }, call list_insert_before( list, -1, 5 ):
   * results in { 0 -> -1 -> 5 -> 4 -> 5 }
   *
   * NOTE: if the value 'before' does not exist in 'list', this
   * function should not modify the list or append anywhere.
   */

  List_node *p = list->front;
  List_node *new_node = create_node(insert);
  size_t length = list->length;

  if( list->front == NULL ) {
      exit(0);
  }
  else{
  while( p->next != NULL && length > 0) {
      if (p->next->value==before){
        new_node->next=p->next;
        list->length=length+1;
        p->next=new_node;
        break;
      }
      else{
      p = p->next;
      }
  }

  }
}

// Implement this
void list_delete( List *list, int value ) {
  /* Delete all occurrences of the value 'value' in list.
   * For example, starting with { 0 -> 5 -> 4 -> 5 }
   * call list_delete( list, 5 ):
   * results in { 0 -> 4 }
   * If there are no values to delete, the function should
   * do nothing.
   */
  List_node *p = list->front;
  size_t length = list->length;

  if( list->front == NULL ) {
      exit(0);
  }
  else{
  while( p->next != NULL && length > 0) {
      if (p->next->value==value){
        //printf( "%d -> ", p->next->next->value );
        List_node *tmp = (p->next)->next;
        free(p->next);
        p->next=tmp;
        list->length=length-1;
      }
      else{
      p = p->next;
      }
  }

  }
}

// Implement this
void list_apply( List *list, int (*function_ptr)(int) ) {
  /* Applies the function pointed to by function_ptr
   * to every value at nodes in list 'list'.
   * For example, starting with { 1 -> 2 -> 3 } and
   * a function 
   *
   *     int sq(int x) { return x * x; }
   * 
   * call to list_apply( list, sq );
   * results in { 1 -> 4 -> 9 }
   */
  List_node *p = list->front;
  size_t length = list->length;

  if( list->front == NULL ) {
      exit(0);
  }
  else{
  while( p->next != NULL && length > 0) {
      p->value=(*function_ptr)(p->value);
      p = p->next;
      }
  }

}

int list_reduce( List *list, int (*function_ptr)(int, int) ) {
  /* Takes an associative function pointed to by function_ptr
   * and returns the result of reducing the list with it.
   * For example, starting with { 1 -> 2 -> 3 } and
   * a function
   *
   *    int plus( int x, int y ) { return x + y; }
   * 
   * list_reduce( list, plus );
   * will return 1 + 2 + 3 = 6.
   */
  int result=0;
  List_node *p = list->front;
  size_t length = list->length;

  if( list->front == NULL ) {
      exit(0);
  }
  else{
  while( p!= NULL && length > 0) {
      result=(*function_ptr)(result,p->value);
      p = p->next;
      }
  }
  return result;
}

// Print out a linked list in human-readable form
void list_print( List list ) {
  if( list.front == NULL ) {
    printf( "{}\n" );
  } else {
    printf( "{ " );

    List_node *p = list.front;
    size_t length = list.length;

    while( p->next != NULL && length > 0 ) {
      printf( "%d -> ", p->value );
      p = p->next; --length;
    }
    printf( "%d }\n", p->value );

    if( length != 1 ) {
      printf( "Error: badly formed list.\n" );
      exit( EXIT_FAILURE );
    }
  }
}

// Frees the memory in List *list
void list_clear( List *list ) {
  List_node *front = list->front;
  size_t length = list->length;

  while( front != NULL && length > 0 ) {
    List_node *next = front->next;
    free( front );
    front = next;
    --length;
  }

  if( length != 0 ) {
    printf( "Error: failed to clean up list properly.\n" );
    exit( EXIT_FAILURE );
  }
}
