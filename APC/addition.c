#include "apc.h"

void addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)

{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    Dlist *result_head = NULL;
    Dlist *result_tail = NULL;

    int carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        int val1 = 0, val2 = 0;

        if (temp1 != NULL)
        {
            val1 = temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2 != NULL)
        {
            val2 = temp2->data;
            temp2 = temp2->prev;
        }

        int res = val1 + val2 + carry;

        carry = res / 10;

        insert_at_first(&result_head, &result_tail, res % 10);
    }

    if (carry)
        insert_at_first(&result_head, &result_tail, carry);

    printf("Result: ");
    print_list(result_head);
}