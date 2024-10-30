// take 2 matrices
// confirm they have the same number of columns
// perform matrix multplication
// give user output
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Doing some matrix shit boy\n");

    int leftMatrix[3][3] = {
        {4, 2, 0}, 
        {0, 8, 1},
        {0, 1, 0},
    };

    int rightMatrix[3][3] = {
        {4, 2, 1},
        {2, 0, 4},
        {9, 4, 2},
    }; 

    int leftMatrixHeight = sizeof(leftMatrix) / sizeof(leftMatrix[0]);
    int rightMatrixWidth = sizeof(rightMatrix[0]) / sizeof(rightMatrix[0][0]);

    // dynamically alloc ram for the result matrix
    int** resultMatrix = (int**)malloc(leftMatrixHeight * sizeof(int*));

    for (int i = 0; i < rightMatrixWidth; i++) {
        resultMatrix[i] = (int*)malloc(sizeof(int));
    }

    if (leftMatrixHeight != rightMatrixWidth) {
        printf("Error:\n");
        printf("Left matrix height and right matrix width don't match.\n");

        return -1;
    }

    for (int col = 0; col < rightMatrixWidth; col++) {
        for (int colIteration = 0; colIteration < leftMatrixHeight; colIteration++) {
            int resultMatrixValue = 0;

            for (int row = 0; row < leftMatrixHeight; row++) {
                int valueInRightMatrix = rightMatrix[row][col];
                int valueInLeftMatrix = leftMatrix[colIteration][row];

                resultMatrixValue = resultMatrixValue + valueInLeftMatrix * valueInRightMatrix;
            }

            resultMatrix[colIteration][col] = resultMatrixValue;
        }
    }

    printf("Result Matrix:\n");
    for (int i = 0; i < leftMatrixHeight; i++) {
        for (int j = 0; j < rightMatrixWidth; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < leftMatrixHeight; i++) {
        free(resultMatrix[i]);
    }

    free(resultMatrix);

    return 0;
}
