#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int key_t;

#define left_of_bst(node) node->link[0]
#define right_of_bst(node) node->link[1]
#define key_of_bst_node(node) node->key
#define parent_of_bst(node) node->parent

#define root_of_bst(tree) tree->root
#define name_of_bst(tree) tree->name
#define count_nodes_of_bst(tree) tree->node_counter

typedef struct bstnode
{
	key_t key;
	struct bstnode *parent;
	struct bstnode *link[2]; // SOURCE: eternallyconfuzzled.com
}BSTNode_t,*BSTNode_p;

typedef struct bstree
{
	char name[40];
	long unsigned int node_counter;
	BSTNode_p root;
}BSTree_t,*BSTree_p;

BSTNode_p createBSTNode(key_t key_data,BSTNode_p left_node,BSTNode_p right_node,BSTNode_p parent_node);
BSTree_p createBSTree(char* name_of_tree);
BSTNode_p searchBSTNode( BSTree_p bstree_pointer, key_t key_data ); // find only first element encountered with key_data value.
BSTNode_p searchBSTNode_all( BSTree_p bstree_pointer, key_t key_data ); // find duplicates too.
BSTNode_p insert_node(BSTree_p bstree_pointer, key_t key_data);
void BST_Inorder(BSTNode_p bstnode_pointer);
BSTNode_p successor(BSTNode_p bstnode_pointer);
BSTNode_p descendent(BSTNode_p bstnode_pointer);
void right_rotate_BSTree( BSTree_p bstree_pointer );
void left_rotate_BSTree( BSTree_p bstree_pointer );
int delete_bstnode(BSTree_p bstree_pointer, BSTNode_p bstnode_pointer);
int clear_bstree(BSTree_p bstree_pointer);
int drop_bstree(BSTNode_p bstree_pointer);

#endif // BST_H
