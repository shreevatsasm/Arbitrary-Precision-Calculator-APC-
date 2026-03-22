#include "apc.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./a.out number operator number\n");
        return 0;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;

    Dlist *res_h = NULL, *res_t = NULL;

    char *num1 = argv[1];
    char operator = argv[2][0];
    char *num2 = argv[3];

    /* store number1 into DLL */
    for (int i = 0; num1[i] != '\0'; i++)
    {
        insert_at_last(&head1, &tail1, num1[i] - '0');
    }

    /* store number2 into DLL */
    for (int i = 0; num2[i] != '\0'; i++)
    {
        insert_at_last(&head2, &tail2, num2[i] - '0');
    }

    switch (operator)
    {
        case '+':
            addition(head1, tail1, head2, tail2, &res_h, &res_t);
            print_list(res_h);
            break;

        case '-':
            subtraction(head1, tail1, head2, tail2, &res_h, &res_t);
            print_list(res_h);
            break;

        case 'x':  
            multiplication(head1, tail1, head2, tail2, &res_h, &res_t);
            print_list(res_h);
            break;

        case '/':
            division(head1, tail1, head2, tail2,&res_h, &res_t);
            break;

        default:
            printf("Invalid operator\n");
    }

    return 0;
}