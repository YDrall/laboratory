#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/*  Created: 23,march,2015
 *  Last edited: 23,march,2015
 ******************************************************************************************************************************************************************
 *  This class contain following operation
 *  #create a linked list.(List createlist(char*,size_t))
 *  #Add an item to head.(Node addtohead(List,key_t))
 *  #Add an item to tail.(Node addtotail(List,key_t))
 *  #Delete an item from head.(Node deletefromhead(List))
 *  #Delete an item from tail.(Node deletefromtail(List))
 *  #Joining two list.(List joinlists(List,List))
 *  #Get an item from head.(without deleting it).(Node headof(List))
 *  #Get an item from tail.(Node tailof(List))
 *  #Get number of items in a list.(int countnodes(List))
 *  #Get inedex of a specific element.#if we consider list as a array where head is considered to be first index i.e. 0 and tail is the last index(int index(List,Node) )
 *  #Get elements in a range.(here head is indexed as zero postion an tail is the last index)(int *getinrange(List,int,int))
 *  #Delete elements in a range.(int *delinrange(List,int,int))
 *  #Get an element on a specific index.(Node Node_at(int))
 *  #Empty a list.(void del(List))
 *  #Destroy a list.(void drop(List))
 *  #Add an element after a specific element(Node addafter(Node,int)
 ******************************************************************************************************************************************************************
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef int key_t;

#define head_of_list(list) list->head
#define tail_of_list(list) list->tail
#define count_nodes_of_list(list) list->count
#define key_of_list_node(node) node->key

typedef struct node
{
    key_t key;
    struct node *next;

    // thinking of adding a list of pointers pointing toward it, but it will increase space allocation so looking for  a better solution....

}Node_t,*Node;

typedef struct list
{
    char name[50];
    long unsigned int count;
    Node head;
    Node tail;
}List_t,*List;

List createlist(char*,size_t);
Node addtohead(List,key_t);
Node addtotail(List,key_t);
Node deletefromhead(List);
Node deletefromtail(List);
List joinlists(List,List);

int indexof(List,Node);
//Node* getinrange(List,int,int);
//int delinrange(List,int,int);
Node Node_at(List ,int);
void deletelist(List);
void droplist(List);
Node addafter(Node,int);

#endif //LINKEDLIST_H
