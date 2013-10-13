#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>

struct node {
  pid_t name ;
  struct node * next ;
};


void list_append(pid_t  name, struct node ** head){
  struct node * newnode = (struct node * ) malloc (sizeof( struct node));
  newnode -> name = name ;
  newnode -> next = NULL;
  struct node * tmp = * head ;

  if ( tmp == NULL)
    { newnode -> next = tmp;
      * head  = newnode ;
    }
  else {
    while ( tmp -> next != NULL){
      tmp = tmp -> next ;
    }
    tmp -> next = newnode ;
    newnode -> next = NULL;
  }
}

void list_print (struct node *head){
  struct node * itr = head ;
  while ( itr != NULL){
    printf("\n name is : %d \n ", itr -> name );
    itr = itr -> next ;
    printf("\n Inside loop \n ");
  }
}
void list_delete(pid_t name,  struct node ** head ){
  struct node * tmp = * head ;
  //deleting the head node if it happens to match what we want
  if ( tmp -> name == name ){*head = tmp -> next ;}
  else {
    //loop until either you find the name or you're pointing to null
    while( ( tmp ->next -> name != name ) && (tmp !=NULL)){
      tmp = tmp -> next ;
    }
    if ( tmp == NULL){}//if you're pointing to nothing don't do anything
    else {//else make the current node point to the second node from it
      tmp -> next = tmp -> next -> next ;
    }
    
    

  }


}
  

int main( int argc, char ** argv){
  struct node * head = NULL;
  //  struct node ** head_input = & head;                                                 
  pid_t no = 23;
  pid_t no_2 =24;
  pid_t no_3 = 25;
  pid_t * my_name = & no;
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





  list_append( no, &head );
  //  struct node * wtf = * head_input ;                                                  
  printf ("\n now the head has %d \n", head -> name );
  //  const pid_t * my_name_1 = & no_2;                                                   
  list_append( no_2, &head );
  //  const pid_t * my_name_2 = & no_3;                                                   
  list_append( no_3, &head );
  //  const struct node * head_for_print = ( const struct node *) head;                   

  list_print( head);
  //    struct node * for_p = * head_input ;                                              
  //    printf ("\n no: %d\n ", for_p -> name );                                          
  //printf("\n no: %d\n ", for_p -> next -> name);                                        
  //    printf("\n no: %d\n ", for_p -> next -> next -> name);                            
  list_delete( no, & head);
  printf ("\n after deletion\n");
  list_print( head);
  
  return 0;
}

