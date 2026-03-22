#include "apc.h"

/* Insert at first */
void insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
        *head = *tail = new;
    else
    {
        (*head)->prev = new;
        *head = new;
    }
}

/* Insert at last */
void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail == NULL)
        *head = *tail = new;
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
}

/* Convert string to DLL */
void convert_to_list(char str[], Dlist **head, Dlist **tail)
{
    int i = 0;

    while (str[i] != '\0')
    {
        insert_at_last(head, tail, str[i] - '0');
        i++;
    }
}

/* Print list */
void print_list(Dlist *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}