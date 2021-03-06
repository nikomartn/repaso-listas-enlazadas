
//Information contained on each node
typedef struct type_info{
  int data;
}Type_info;


//Struct of a node
typedef struct type_node{
  Type_info info;
  struct type_node * next;
}Type_node;

//Reference to a node
typedef Type_node * Type_node_ref;

//Reference to a linked list
typedef Type_node * Linked_list;

//Error on some process (0 = fine)
typedef int Linked_list_err;
/*  -2 = not an empty pointer
 *  -1 = problem when reserving memory
 *   1 = library not initiated
 *   2 = this not exist
 * */

/************************************************************************
 * Linked_list -> Type_node -> Type_node -> ... -> Type_node -> NULL
 *    ref ->      data | ref-> data | ref-> ... -> data | ref-> NULL
 * 
 * Linked_list is a reference to the first node of the list, each node
 * contains a reference to the location of the next node. The list is over 
 * when the reference to a node is NULL, or the list is empty if the
 * Linked_list pointers at NULL.
 * ********************************************************************/

int 
list_empty (Linked_list ref);

Linked_list
init_linked_list (Linked_list       ref);

Type_node_ref
last_node_reference (Linked_list  ref);

Type_node_ref
add_new_close_node  (Linked_list      ref,
                     Type_info        info);

Type_node_ref
add_new_mid_node  (Type_node_ref    ref,
                   Type_info        info);

Type_node_ref
add_new_node_on (Linked_list  list,
                 Type_info    info,
                 int          position);
  
Type_node_ref
rm_next_node (Type_node_ref ref);

void
rm_list (Linked_list  list);
