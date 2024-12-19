#include <stdio.h>
#include <stdlib.h>
int i,j,k;
typedef struct {
    int coefficient;
    int exponent;
} Term;

void addSparsePolynomials(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *sizeResult) {
    i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++; j++; k++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else {
            result[k++] = poly2[j++];
        }
    }

    while (i < size1) {
        result[k++] = poly1[i++];
    }

    while (j < size2) {
        result[k++] = poly2[j++];
    }

    *sizeResult = k;
}

void printPolynomial(Term poly[], int size) {
    for (i = 0; i < size; i++) {
        if (i > 0 && poly[i].coefficient > 0) printf(" + ");
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
    }
    printf("\n");
}

int main() {
    Term poly1[] = {{3, 0}, {2, 1}, {4, 3}};
    Term poly2[] = {{1, 0}, {1, 1}, {3, 2}};
    Term result[10];
    int sizeResult;

    addSparsePolynomials(poly1, 3, poly2, 3, result, &sizeResult);

    printf("Resultant polynomial: ");
    printPolynomial(result, sizeResult);

    return 0;
}
