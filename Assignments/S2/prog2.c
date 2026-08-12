#include<stdio.h>

int main()
{	
 float  num1, num2;
 float  res;
 int   operator;

    printf("num1 = ");
    scanf("%f", &num1);

    printf("num2 = ");
    scanf("%f", &num2);

    printf("Select your operator:\n"
           "1. Addition\n"
           "2. Subtraction\n"
           "3. Multiplication\n"
           "4. Division\n"
           ": ");

    scanf("%d", &operator);

    switch(operator)
    {
        case 1:
            res = num1 + num2;
            printf("res = %.2f\n", res);
            break;

        case 2:
            res = num1 - num2;
            printf("res = %.2f\n", res);
            break;

        case 3:
            res = num1 * num2;
            printf("res = %.2f\n", res);
            break;

        case 4:
            if (num2 != 0)
            {
                res = num1 / num2;
                printf("res = %.2f\n", res);
            }
            else
            {
                printf("Error: division by zero\n");
            }
            break;

        default:
            printf("Error: invalid operator\n");
    }
	

	return 0 ;
}
