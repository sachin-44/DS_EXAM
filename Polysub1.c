#include <stdio.h>
#include <stdlib.h>
struct Polynomial {
    int degree;
    int* coefficients;
};

void initializePolynomial(struct Polynomial* poly, int degree) {
    poly->degree = degree;
    poly->coefficients = (int*)malloc((degree + 1) * sizeof(int));

    for (int i = 0; i <= degree; i++) {
        poly->coefficients[i] = 0;
    }
}

void inputPolynomial(struct Polynomial* poly) {
    for (int i = poly->degree; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &poly->coefficients[i]);
    }
}

void displayPolynomial(struct Polynomial poly) {
    for (int i = poly.degree; i > 0; i--) {
        printf("%dx^%d + ", poly.coefficients[i], i);
    }
    printf("%d\n", poly.coefficients[0]);
}

struct Polynomial subtractPolynomials(struct Polynomial poly1, struct Polynomial poly2) {
    struct Polynomial result;
    int maxDegree = (poly1.degree > poly2.degree) ? poly1.degree : poly2.degree;

    initializePolynomial(&result, maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        int coef1 = (i <= poly1.degree) ? poly1.coefficients[i] : 0;
        int coef2 = (i <= poly2.degree) ? poly2.coefficients[i] : 0;

        result.coefficients[i] = coef1 - coef2;
    }

    return result;
}

int main() {
    struct Polynomial poly1, poly2, result;
    printf("Enter the degree of the first polynomial: ");
    int deg1;
    scanf("%d", &deg1);
    initializePolynomial(&poly1, deg1);
    printf("Enter coefficients for the first polynomial\n");
    inputPolynomial(&poly1);

    printf("Enter the degree of the second polynomial: ");
    int deg2;
    scanf("%d", &deg2);

    initializePolynomial(&poly2, deg2);
    printf("Enter coefficients for the second polynomial\n");
    inputPolynomial(&poly2);

    printf("First polynomial: ");
    displayPolynomial(poly1);
    printf("Second polynomial: ");
    displayPolynomial(poly2);

    result = subtractPolynomials(poly1, poly2);

    printf("Result of subtraction: ");
    displayPolynomial(result);

    free(poly1.coefficients);
    free(poly2.coefficients);
    free(result.coefficients);

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
 
