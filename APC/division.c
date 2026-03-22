#include "apc.h"

void division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)

{
    int flag;
    int count = 0;

    while (1)
    {
        flag = compare_two_list(head1, head2);

        if (flag == 0)
            break;

        /* head1 = head1 - head2 */

        Dlist *res_h = NULL;
        Dlist *res_t = NULL;

        subtraction(head1, tail1, head2, tail2, &res_h, &res_t);

        head1 = res_h;
        tail1 = res_t;

        count++;
    }

    printf("Quotient: %d\n", count);
}