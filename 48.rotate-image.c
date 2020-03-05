/*
 * @lc app=leetcode id=48 lang=c
 *
 * [48] Rotate Image
 */

int abc(int** matrix, int width, int length, int* x, int* y, int val) {
    int x1 = (width - length) / 2 + *y;
    int y1 = (width + length) / 2 - *x;
    if (x1 == *x && y1 == *y)
    {
        return val;
    }
    int temp = matrix[x1][y1];
    matrix[x1][y1] = val;
    *x = x1;
    *y = y1;
    return temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize / 2; i++)
    {
        for (int j = i; j < matrixColSize[i] - i - 1; j++)
        {
            int x = j;
            int y = i;
            int val = abc(matrix, matrixSize - 1, matrixColSize[i] - 1, &x, &y, matrix[x][y]);
            val = abc(matrix, matrixSize - 1, matrixColSize[i] - 1, &x, &y, val);
            val = abc(matrix, matrixSize - 1, matrixColSize[i] - 1, &x, &y, val);
            abc(matrix, matrixSize - 1, matrixColSize[i] - 1, &x, &y, val);
        }
    }
}



