#include <stdio.h>
int i,j,k;
int main() {
    int m = 3; 
    int n = 4;

    int array_2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int array_1d[m * n];

    for ( i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int index_1d = i * n + j;
            array_1d[index_1d] = array_2d[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int index_1d = i * n + j;
            printf("Element at (%d, %d) in 2D array is %d in 1D array\n", i, j, array_1d[index_1d]);
        }
    }
    
    return 0;
}
