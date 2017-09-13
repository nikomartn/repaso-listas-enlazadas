#include "listaenlazada.h"
#include <stdlib.h>

Linked_list_err err;

int 
list_empty (Linked_list ref)
{ //If the list isn't empty, returns 0
  return(ref == NULL);
}

Linked_list
init_linked_list (Linked_list       ref,
				  Linked_list_err   err)
{ /*Checks if the Linked_list is already being used, if empty, initialice        
  it*/
  if (list_empty (ref))
    {
      if ( (ref = malloc (sizeof(Type_node))) == NULL)
        {
          *err = -1;
        }
      else
        {
          return 0;
        }
    }
  
  else
    {
      *err = -2; 
    }
}

Type_node_ref
last_node_reference (Linked_list  ref)
{ /*Returns the direction of the last node from the list*/ 
  while((ref -> next) != NULL)
    {
      ref = ref -> next;
    }
    
    return (ref);
}

Type_node_ref
add_new_close_node  (Linked_list      ref,
                     Linked_list_err  err,
                     Type_info        info)
{/*Checks if the Linked_list is already being used, if empty, starts new 
  * node on pointer, if not, looks for the final node and adds to it a
  *new node, on any case, the new node will contain the Type_info that
  *it's given and the reference to the new made node will be returned or
  *NULL if fails*/
  if (list_empty(ref))
    {
      init_linked_list (ref, err);
      if (err != 0)
        {
          return NULL;
        }
      else
        {
          ref -> info = info;
          return ref;
        }
    }
  else
    {
      ref = last_node_reference (ref);
      if((ref -> next = malloc (sizeof(Type_node))) == NULL)
        {
          *err = -2;
          return NULL;
        }
      else
        {
          ref = ref -> next;
          ref -> info = info;
          ref -> next = NULL;
          return ref;
        }
    }
}

