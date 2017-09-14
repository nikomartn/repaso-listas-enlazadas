#include "linkedlist.h"
#include <stdlib.h>

Linked_list_err err;

int 
list_empty (Linked_list ref)
{ //If the list isn't empty, returns 0
  return(ref == NULL);
}

Linked_list
init_linked_list (Linked_list       ref)
{ /*Checks if the Linked_list is already being used, if empty, initialice        
  it*/
  if (list_empty (ref))
    {
      if ( (ref = malloc (sizeof(Type_node))) == NULL)
        {
          err = -1;
        }
      else
        {
          return 0;
        }
    }
  
  else
    {
      err = -2; 
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
                     Type_info        info)
{/*Checks if the Linked_list is already being used, if empty, starts new 
  * node on pointer, if not, looks for the final node and adds to it a
  *new node, on any case, the new node will contain the Type_info that
  *it's given and the reference to the new made node will be returned or
  *NULL if fails*/
  if (list_empty(ref))
    {
      init_linked_list (ref);
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
          err = -2;
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

Type_node_ref
add_new_mid_node  (Type_node_ref    ref,
                   Type_info        info)
{/*Adds a new node near the referenced one*/
  
  Type_node_ref temporal_reference;
  
    
temporal_reference = ref -> next;
  if ((ref -> next = malloc (sizeof(Type_node))) == NULL)
    {
      ref -> next = temporal_reference;
      err = -1;
      return NULL;
    }
  else
    {
      ref = ref -> next;
      ref -> next = temporal_reference;
      ref -> info = info;
      return (ref);
    }
}
 
Type_node_ref
add_new_node_on (Linked_list  list,
                 Type_info    info,
                 int          position)
{/*Adds a new node, on the list, on the determined position*/
  Type_node_ref next_node = NULL, ref = NULL;
  int i;
  
  if (list_empty(list))
    {
      err = 2;
      return NULL;
    }
    
  else
    {
      next_node = list -> next;
      ref = list;
      
      for (i = 0; i < position; i++)
        {
          if (ref -> next == NULL)
            {
              err = 2;
              return NULL;
            }
          ref = ref -> next; 
          next_node = ref -> next;
        }
        
      if ((ref -> next = malloc (sizeof(Type_node))) == NULL)
        {
          err = -2;
          ref -> next = next_node;
          return NULL;
        }
      else
        {
          ref = ref -> next;
          ref -> next = next_node;
          ref -> info = info;
          return (ref);
        }  
      
    }
}

Type_node_ref
rm_next_node (Type_node_ref ref)
{/*Removes the next node, returns the reference to the new next one or
  *NULL*/
  Type_node_ref to_remove = ref -> next;
  Type_node_ref next = to_remove -> next;
  
  free (to_remove);
  
  ref -> next = next;
  
  return (next);
}

void
rm_list (Linked_list  list)
{
  while (list -> next != NULL)
    {
      list -> next = rm_next_node (list);
    }
  free (list);
  list = NULL;
}
