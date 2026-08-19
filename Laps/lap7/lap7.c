#include <stdio.h>
#include <stdlib.h>

/* Node Structure */
typedef struct Node
{
    int Data;
    struct Node *Next;

} Node_t;


/* Linked List Structure */
typedef struct
{
    Node_t *Head;

} List_t;


/* Initialize Linked List */
void List_Init(List_t *List);
/* Insert Functions */
void InsertAtFirst(List_t *List, int Value);
void InsertAtEnd(List_t *List, int Value);
void PrintList(List_t *List);

int main()
{
	/* Initialize the list */
    List_t list;

    List_Init(&list);

    printf("========== Linked List Test ==========\n\n");
	
	

    InsertAtFirst(&list, 10);
    InsertAtFirst(&list, 20);

    InsertAtEnd(&list, 30);
    InsertAtEnd(&list, 40);

    PrintList(&list);


	return 0 ;
}



/************** Function Definition ***************/

/* =========================================================
   Initialize Linked List
   ========================================================= */
void List_Init(List_t *List)
{
    List->Head = NULL;
}


/* =========================================================
   Insert At First
   ========================================================= */
void InsertAtFirst(List_t *List, int Value)
{
    Node_t *NewNode;		// int *ptr;

    /* Allocate memory for new node */
    NewNode = (Node_t *)malloc(sizeof(Node_t));		// ptr = &x;

    if (NewNode != NULL)
    {
        /* Put data inside node */
        NewNode->Data = Value;

        /* New node points to current first node */
        NewNode->Next = List->Head;

        /* Make new node the first node */
        List->Head = NewNode;
    }
}


/* =========================================================
   Insert At End
   ========================================================= */
void InsertAtEnd(List_t *List, int Value)
{
    Node_t *NewNode;
    Node_t *Temp;

    /* Allocate memory for new node */
    NewNode = (Node_t *)malloc(sizeof(Node_t));

    if (NewNode != NULL)
    {
        NewNode->Data = Value;
        NewNode->Next = NULL;

        /* If list is empty */
        if (List->Head == NULL)
        {
            List->Head = NewNode;
        }
        else
        {
            /* Start from Head */
            Temp = List->Head;

            /* Move until last node */
            while (Temp->Next != NULL)
            {
                Temp = Temp->Next;
            }

            /* Connect last node with new node */
            Temp->Next = NewNode;
        }
    }
}


/* =========================================================
   Print List
   ========================================================= */
void PrintList(List_t *List)
{
    Node_t *Temp;

    Temp = List->Head;

    if (Temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (Temp != NULL)
    {
        printf("%d", Temp->Data);

        if (Temp->Next != NULL)
        {
            printf(" -> ");
        }

        Temp = Temp->Next;
    }

    printf(" -> NULL\n");
}