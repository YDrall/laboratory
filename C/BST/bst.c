#include "bst.h"

BSTree_p createBSTree( char* name_of_tree )
{
	BSTree_p new_tree = (BSTree_p) malloc( sizeof( BSTree_t ) );
	if( new_tree == NULL )
		abort();

	new_tree->root = NULL;
	strcpy( new_tree->name, name_of_tree );

	return new_tree;
}

BSTNode_p createBSTNode(key_t key_data,BSTNode_p left_node,BSTNode_p right_node,BSTNode_p parent_node)
{
	BSTNode_p newnode = (BSTNode_p) malloc( sizeof( BSTNode_t ) );
	if(newnode == NULL )
		abort();

	newnode->key = key_data;
	newnode->link[0] = left_node;
	newnode->link[1] = right_node;
	newnode->parent = parent_node;

	return newnode;
}

BSTNode_p insert_node( BSTree_p bstree_pointer, key_t key_data)
{

	BSTNode_p position_tracker = bstree_pointer->root;
	BSTNode_p position_tracker_parent = NULL;
	int direction = -1;
	if( bstree_pointer->root != NULL )
	{
		while( position_tracker != NULL )
		{
			position_tracker_parent = position_tracker;
			direction = ( key_data > position_tracker->key );
			position_tracker = position_tracker->link[direction];
		}

		position_tracker_parent->link[direction] = createBSTNode(key_data,NULL,NULL,position_tracker_parent);
		bstree_pointer->node_counter++;

		return position_tracker_parent->link[direction];
	}
	bstree_pointer->root = createBSTNode(key_data,NULL,NULL,NULL);
	bstree_pointer->node_counter++;
	return bstree_pointer->root;

}

BSTNode_p searchBSTNode( BSTree_p bstree_pointer, key_t key_data )
{
    BSTNode_p position_tracker = bstree_pointer->root;
    int direction = -1;
    while( position tracker != NULL || position_tracker->key != key_data )
    {
		direction = key_data > position_tracker->key;
		position_tracker = position_tracker->link[direction];
    }
		return position_tracker;
}



int main()
{
	BSTree_p tree = createBSTree("tree1");
	BSTNode_p node1 = insert_node(tree,8);
	BSTNode_p node2 = insert_node(tree,4);
	BSTNode_p node3 = insert_node(tree,81);
	printf("%s have %lu nodes with key values as %d %d %d.\n",name_of(tree),count_nodes_of(tree),key_of(parent_of(node2)),key_of(parent_of(node2)),key_of(node3));
	return 0;
}
