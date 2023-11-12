#include<stdio.h>
#define size 10

int main()
{
    int deg1, deg2, i, x;
    int p1[size], p2[size], p3[size];

    printf("Enter degree of polynomial1:\n");
    scanf("%d", &deg1);
    for(i = 0; i <= deg1; i++)
    {
        printf("Enter the coefficient of x^%d:\n", i);
        scanf("%d", &p1[i]);
    }

    printf("Enter degree of polynomial2:\n");
    scanf("%d", &deg2);
    for(i = 0; i <= deg2; i++)
    {
        printf("Enter coefficient of x^%d:\n", i);
        scanf("%d", &p2[i]);
    }
   // Subtract polynomials
    if(deg2 > deg1)
    {
       x = deg2;
       for(i = 0; i <= deg1; i++)
       {
           p3[i] = p1[i] - p2[i];
       }
       for(i = deg1 + 1; i <= deg2; i++)
       {
           p3[i] = -p2[i];
       }

    }
    else
    {
        x = deg1;
        for(i = 0; i <= deg2; i++)
        {
            p3[i] = p1[i] - p2[i];
         }
         for(i = deg2 + 1; i <= deg1; i++)
         {
             p3[i] = p1[i];
         }
    }

    // Display the input polynomials
    printf("Polynomial 1 is :\n");
    for(i = deg1; i > 0; i--)
    {
        printf("%dx^%d + ", p1[i], i);
    }
    printf("%dx^%d\n", p1[i], i);

    printf("Polynomial 2 is :\n");
    for(i = deg2; i > 0; i--)
    {
        printf("%dx^%d + ", p2[i], i);
    }
    printf("%dx^%d\n", p2[i], i);

    // Display the resultant polynomial
    printf("The result of subtraction is :\n");
    for(i = x; i > 0; i--)
    {
        printf("%dx^%d + ", p3[i], i);
    }
    printf("%dx^%d\n", p3[i], i);

    return 0;
}












// Structure to represent a polynomial

// Function to initialize a polynomial

// Function to input coefficients of a polynomial

// Function to display a polynomial

// Function to subtract two polynomials

// Function to free memory allocated for coefficients

    // Input degree of the first polynomial

    // Initialize and input the first polynomial

    // Input degree of the second polynomial

    // Initialize and input the second polynomial

    // Display the input polynomials

    // Subtract the polynomials

    // Display the result

    // Free memory allocated for coefficients
 

