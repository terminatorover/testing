#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include<string.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


struct node {
  pid_t name ;
  struct node * next ;
  

};


void list_append( const pid_t * name, struct node ** head){
  struct node * newnode = (struct node * ) malloc (sizeof( struct node));
  pid_t * the_name = (pid_t *) name;
  newnode -> name = * the_name ;
  struct node * tmp = * head ;

  if ( tmp == NULL)
    { newnode -> next = tmp; 
      * head  = & newnode ;
      newnode -> next = NULL;
    }
  else {
    while ( tmp -> next != NULL){
      tmp = tmp -> next ;
      }
     tmp -> next = newnode ;
     newnode -> next = NULL;

       }
     newnode -> next = NULL;
   }

void list_print ( const struct node *head){
  struct node * itr = (struct node *) head ;
  
  while ( itr != NULL){
    printf("\n name is : %d \n ", itr -> name );

    itr = itr -> next ;

    printf("\n WTFFFFF\n ");
  }
}


  int main( int argc, char ** argv){
    struct node * head = NULL;
    struct node ** head_input = & head;
    pid_t no = 23;
    pid_t no_2 =24;
    pid_t no_3 = 25; 
    const pid_t * my_name = & no;

    /*
  struct node * newnode = (struct node * ) malloc (sizeof( struct node));
  pid_t * the_name = (pid_t *) my_name;
  newnode -> name = * my_name ;
  struct node * tmp = * head_input ;

  if ( tmp == NULL)
    { newnode -> next = tmp; 
      * head_input  = &newnode ;

    }
  struct node * header = * head_input;
  printf("\n  the head no has %d\n", header -> name) ;
    */





    list_append( my_name, head_input );
    struct node * wtf = * head_input ;
    printf ("\n now the head has %d \n",wtf -> name );
    const pid_t * my_name_1 = & no_2;
    list_append( my_name_1, head_input );
    const pid_t * my_name_2 = & no_3;
    list_append( my_name_2, head_input );
    const struct node * head_for_print = ( const struct node *) head;
    
    list_print( *head_input);
    //    struct node * for_p = * head_input ;
    //    printf ("\n no: %d\n ", for_p -> name );
    //printf("\n no: %d\n ", for_p -> next -> name);
    //    printf("\n no: %d\n ", for_p -> next -> next -> name);

    return 0;
  }
