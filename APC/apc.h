#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;
void insert_at_first(Dlist **head, Dlist **tail, int data);
void insert_at_last(Dlist **head, Dlist **tail, int data);
void convert_to_list(char str[], Dlist **head, Dlist **tail);
void print_list(Dlist *head);
int compare_two_list(Dlist *head1, Dlist *head2);

void addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
void subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
void multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
void division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
#endif