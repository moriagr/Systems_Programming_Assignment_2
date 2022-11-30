#include <stdio.h>
#include "my_mat.h"

#define TRUE 1
#define FALSE 0
#ifndef MATRIX_SIZE
#define MATRIX_SIZE 10
#endif

void organizeShortestTable(int (*matrix)[MATRIX_SIZE], int (*min_dist_matrix)[MATRIX_SIZE], int min_dist_matrix_not_full)
{
    if (min_dist_matrix_not_full == 0)
    {
        //  let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
        for (int l = 0; l < MATRIX_SIZE; l++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                min_dist_matrix[l][k] = matrix[l][k];
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
                    if ((l != m) && (part1 != 0) && (part2 != 0) && ((part > part1 + part2) || part == 0))
                    {
                        min_dist_matrix[l][m] = part1 + part2;
                    }
                }
            }
        }
    }
}

int existingPath(int i, int j, int (*matrix)[MATRIX_SIZE], int (*min_dist_matrix)[MATRIX_SIZE], int min_dist_matrix_not_full)
{
    organizeShortestTable(matrix, min_dist_matrix, min_dist_matrix_not_full);

    if (min_dist_matrix[i][j] != 0)
    {
        return TRUE;
    }

    return FALSE;
}

int shortestCourse(int i, int j, int (*matrix)[MATRIX_SIZE], int (*min_dist_matrix)[MATRIX_SIZE], int min_dist_matrix_not_full)
{
    organizeShortestTable(matrix, min_dist_matrix, min_dist_matrix_not_full);
    return min_dist_matrix[i][j];
}