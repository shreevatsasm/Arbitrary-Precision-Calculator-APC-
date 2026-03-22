#include "apc.h"

void multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)

{
    Dlist *temp1 = tail1;
    Dlist *temp2 = NULL;

    Dlist *res1_h = NULL, *res1_t = NULL;   
    Dlist *res2_h = NULL, *res2_t = NULL; 
    Dlist *res3_h = NULL, *res3_t = NULL;  

    int carry = 0;
    int flag = 0;

    while (temp1 != NULL)
    {
        temp2 = tail2;
        carry = 0;

        res2_h = res2_t = NULL;

        while (temp2 != NULL)
        {
            int res = (temp1->data * temp2->data) + carry;

            carry = res / 10;

            insert_at_first(&res2_h, &res2_t, res % 10);

            temp2 = temp2->prev;
        }

        if (carry)
            insert_at_first(&res2_h, &res2_t, carry);

        
        for (int i = 0; i < flag; i++)
        {
            insert_at_last(&res2_h, &res2_t, 0);
        }

    
        if (res1_h == NULL)
        {
            res1_h = res2_h;
            res1_t = res2_t;
        }
        else
        {
            

            Dlist *t1 = res1_t;
            Dlist *t2 = res2_t;

            res3_h = res3_t = NULL;

            int carry2 = 0;

            while (t1 || t2 || carry2)
            {
                int val1 = 0, val2 = 0;

                if (t1)
                {
                    val1 = t1->data;
                    t1 = t1->prev;
                }

                if (t2)
                {
                    val2 = t2->data;
                    t2 = t2->prev;
                }

                int sum = val1 + val2 + carry2;

                carry2 = sum / 10;

                insert_at_first(&res3_h, &res3_t, sum % 10);
            }

            res1_h = res3_h;
            res1_t = res3_t;
        }

        temp1 = temp1->prev;

        flag++;
    }

    printf("Result: ");
    print_list(res1_h);
}