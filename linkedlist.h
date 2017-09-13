
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
typedef int *	Linked_list_err;
/*	-2 = not an empty pointer
 * 	-1 = problem when reserving memory
 * 	 1 = library not initiated
 * */

/************************************************************************
 * Linked_list -> Type_node -> Type_node -> ... -> Type_node -> NULL
 * 		ref -> 	  data | ref-> data | ref-> ... -> data | ref-> NULL
 * 
 * Linked_list is a reference to the first node of the list, each node
 * contains a reference to the location of the next node. The list is over 
 * when the reference to a node is NULL, or the list is empty if the
 * Linked_list pointers at NULL.
 * ********************************************************************/

int
list_empty (Linked_list);

Linked_list
init_linked_list (Linked_list		ref,
				  Linked_list_err	err);

	
