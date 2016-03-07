#include"linkedlist.h"

List createlist(char *notation,size_t size_of_string)
{
    List l = (List) malloc( sizeof(List_t) );
    if (l == NULL)
        abort();
    strcpy(l->name,notation);
    l->head = NULL;
    l->tail = NULL;
    l->count = 0;
    return l;
}
Node addtohead( List lst , key_t data )
{
    Node newnode = (Node) malloc( sizeof( Node_t ) );
    if( newnode == NULL )
        abort();

    newnode->key = data;
    newnode->next = NULL;

    if( lst->tail == NULL )
        lst->tail = newnode;
    else
        newnode->next = head_of_list(lst);
    lst->head = newnode;
    lst->count++;

    return lst->head;
}

Node addtotail( List lst , key_t data )
{
    Node newnode = (Node) malloc( sizeof( Node_t ) );
    if( newnode == NULL )
        abort();

    newnode->key = data;
    newnode->next = NULL;

    if( lst->tail == NULL )
       lst->head = newnode;
    else
        lst->tail->next = newnode;

    lst->tail = newnode;
    lst->count++;


    return lst->tail;
}

Node deletefromhead( List lst )
{
    if( lst->head == NULL )
        abort();

    Node tmp = lst->head;

    if( tmp->next == NULL)
        lst->tail == NULL;

    lst->head = tmp->next;

    free(tmp);

    lst->count--;
    return lst->head;
}

Node deletefromtail( List lst )
{
    if( lst->tail == NULL )
        abort();

    Node tmp = NULL;

    if( lst->head != lst->tail )
    {
        tmp = lst->head;
        while( tmp->next != lst->tail )
        tmp = tmp->next;
    }
    else
        lst->head = NULL;

    Node freetmp=lst->tail;
    lst->tail=tmp;
    lst->tail->next = NULL;

    free(freetmp);

    lst->count--;
    return lst->tail;
}

List joinlists( List head_list , List tail_list )
{
    List newlst = createlist( "JOIN",sizeof("JOIN") );
    newlst->head=head_of_list( head_list);
    newlst->tail=tail_of_list( head_list);

    if(tail_of_list(newlst) != NULL )
        newlst->tail->next = head_of_list( tail_list );

    newlst->tail = tail_of_list(tail_list);
    newlst->count= count_nodes_of_list(head_list) + count_nodes_of_list(tail_list);

    droplist(head_list);
    droplist(tail_list);

    return newlst;
}



int indexof(List list_pointer,Node node_pointer)
{
	if(node_pointer != NULL)
	{
		Node tmp = head_of_list( list_pointer );
		int indx = 0;
		while( tmp != NULL )
		{
            if(tmp == node_pointer )
                return indx;
			tmp = tmp->next;
			indx++;
		}
    }

    return -1;
}

Node Node_at(List list_pointer, int index)
{
    int looper = index;
    Node position_tracker = list_pointer->head;
    while(position_tracker != NULL && looper--)
        position_tracker = position_tracker->next;
    if(looper == -1 && looper != index)
        return position_tracker;
    return NULL;
}


void deletelist(List list_pointer)
{
    Node temp = list_pointer->head;
    while( temp != NULL)
    {
        Node freetemp = temp;
        temp = temp->next;
        list_pointer->count --;
        free(freetemp);
    }

}
void droplist(List list_pointer)
{
    deletelist(list_pointer);
    free(list_pointer);

}
int main()
{
    List list1 = createlist("list1",sizeof("list1"));
    addtotail(list1,4);
    addtotail(list1,3);
    addtohead(list1,5);
    addtohead(list1,58);
    droplist(list1);
}


