#include<stdio.h>
#define size 10
int main()
{
    int deg1,deg2,i,x;
    int p1[size],p2[size],p3[size];
    
    printf("Enter degree of polynomial1:\n");
    scanf("%d",&deg1);
    for(i=0;i<=deg1;i++)
    {
        printf("Enter the coff of x^%d:\n",i);
        scanf("%d",&p1[i]);
    }
    
    printf("Enter degree of polynomial2:\n");
    scanf("%d",&deg2);
    for(i=0;i<=deg2;i++)
    {
        printf("Enter coff of x^%d:\n",i);
        scanf("%d",&p2[i]);
    }
    
    if(deg2>deg1)
    {
       x=deg2;
       for(i=0;i<=deg1;i++)
       {
           p3[i]=p2[i]+p1[i];
       }
       for(i=deg1+1;i<=deg2;i++)
       {p3[i]=p2[i];}
       
    }
    else
    {
    
        x=deg1;
        for(i=0;i<=deg2;i++)
        {
            p3[i]=p2[i]+p1[i];
         }
         for(i=deg2+1;i<=deg1;i++)
         {p3[i]=p1[i];}
         
    }
       printf("The polynomial is :\n");
       for(i=x;i>0;i--)
       {
           printf("%dx^%d+",p3[i],i);
       }
       
       printf("%dx^%d+",p3[i],i);
  }













// Structure to represent a polynomial

// Function to initialize a polynomial

    // Initialize coefficients to zero

// Function to input coefficients of a polynomial


// Function to display a polynomial

// Function to add two polynomials

    // Input degree of the first polynomial

    // Initialize and input the first polynomial

    // Input degree of the second polynomial

    // Initialize and input the second polynomial

    // Display the input polynomials

    // Add the polynomials

    // Display the result

    // Free memory allocated for coefficients
    
