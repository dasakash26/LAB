#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void addSparseMatrices(Element matrix1[], int size1, Element matrix2[], int size2, Element result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (matrix1[i].row == matrix2[j].row && matrix1[i].col == matrix2[j].col) {
            result[k].row = matrix1[i].row;
            result[k].col = matrix1[i].col;
            result[k].value = matrix1[i].value + matrix2[j].value;
            i++; j++; k++;
        } else if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k++] = matrix1[i++];
        } else {
            result[k++] = matrix2[j++];
        }
    }

    while (i < size1) {
        result[k++] = matrix1[i++];
    }

    while (j < size2) {
        result[k++] = matrix2[j++];
    }

    *sizeResult = k;
}
int i;
void printSparseMatrix(Element matrix[], int size) {
    for (i = 0; i < size; i++) {
        printf("Element at (%d, %d) = %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    Element matrix1[] = {{0, 0, 3}, {1, 2, 5}};
    Element matrix2[] = {{0, 0, 2}, {2, 1, 4}};
    Element result[10];
    int sizeResult;

    addSparseMatrices(matrix1, 2, matrix2, 2, result, &sizeResult);

    printf("Resultant Sparse Matrix: \n");
    printSparseMatrix(result, sizeResult);

    return 0;
}
