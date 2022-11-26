#include <stdio.h>
#include "my_mat.h"

#define TRUE 1
#define FALSE 0
#ifndef MATRIX_SIZE
#define MATRIX_SIZE 10
#endif

#ifndef MAX_NUMBER
#define MAX_NUMBER 999999
#endif

void organizeShortestTable(int (*matrix)[MATRIX_SIZE], int (*min_dist_matrix)[MATRIX_SIZE])
{
    if (min_dist_matrix[0][0] == -10)
    {
        //  let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
        for (int l = 0; l < MATRIX_SIZE; l++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                if ((matrix[l][k] == 0))
                {
                    min_dist_matrix[l][k] = MAX_NUMBER;
                }
                else
                {
                    min_dist_matrix[l][k] = matrix[l][k];
                }
            }
        }

        for (int k = 0; k < MATRIX_SIZE; k++)
        {
            for (int l = 0; l < MATRIX_SIZE; l++)
            {
                for (int m = 0; m < MATRIX_SIZE; m++)
                {

                    int part1 = min_dist_matrix[l][k];
                    int part2 = min_dist_matrix[k][m];
                    int part = min_dist_matrix[l][m];
                    if ((l != m) && (((int)(part) > (int)(part1) + (int)(part2))))
                    {
                        min_dist_matrix[l][m] = (int)((int)(part1) + (int)(part2));
                    }
                }
            }
        }
    }
}

int existingPath(int i, int j, int (*matrix)[MATRIX_SIZE], int (*min_dist_matrix)[MATRIX_SIZE])
{
    organizeShortestTable(matrix, min_dist_matrix);

    if (min_dist_matrix[i][j] != MAX_NUMBER)
    {
        return TRUE;
    }

    return FALSE;
}

int shortestCourse(int i, int j, int (*matrix)[MATRIX_SIZE], int (*min_dist_matrix)[MATRIX_SIZE])
{
    organizeShortestTable(matrix, min_dist_matrix);
    return min_dist_matrix[i][j];
}