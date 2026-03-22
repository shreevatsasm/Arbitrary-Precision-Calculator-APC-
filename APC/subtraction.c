#include "apc.h"
int compare_two_list(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *t1 = head1;
    Dlist *t2 = head2;

    while (t1)
    {
        len1++;
        t1 = t1->next;
    }

    while (t2)
    {
        len2++;
        t2 = t2->next;
    }

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return 0;

    t1 = head1;
    t2 = head2;

    while (t1 && t2)
    {
        if (t1->data > t2->data)
            return 1;
        else if (t1->data < t2->data)
            return 0;

        t1 = t1->next;
        t2 = t2->next;
    }

    return 2;   
}
void subtraction(Dlist *head1, Dlist *tail1,
                 Dlist *head2, Dlist *tail2,
                 Dlist **res_h, Dlist **res_t)
{
    int flag = compare_two_list(head1, head2);

    int borrow = 0;

    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    if (flag == 0)
    {
        Dlist *temp;

        temp = head1;
        head1 = head2;
        head2 = temp;

        temp = tail1;
        tail1 = tail2;
        tail2 = temp;

        temp1 = tail1;
        temp2 = tail2;
    }

    while (temp1 != NULL)
    {
        int res;

        if (temp2 != NULL)
        {
            if (temp1->data - borrow >= temp2->data)
            {
                res = temp1->data - temp2->data - borrow;
                borrow = 0;
            }
            else
            {
                res = 10 + temp1->data - temp2->data - borrow;
                borrow = 1;
            }

            temp2 = temp2->prev;
        }
        else
        {
            if (temp1->data - borrow >= 0)
            {
                res = temp1->data - borrow;
                borrow = 0;
            }
            else
            {
                res = 10 + temp1->data - borrow;
                borrow = 1;
            }
        }

        insert_at_first(res_h, res_t, res);

        temp1 = temp1->prev;
    }

    /* remove leading zeros */
    while (*res_h && (*res_h)->data == 0 && (*res_h)->next)
    {
        *res_h = (*res_h)->next;
        (*res_h)->prev = NULL;
    }
}