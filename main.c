#include "my_mat.h"
#include "my_mat.c"
#include <stdio.h>
#include <ctype.h>
#ifndef MATRIX_SIZE
#define MATRIX_SIZE 10
#endif
#ifndef PATH_SIZE
#define PATH_SIZE 2
#endif

int main()
{
    char info;
    char current_letter;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int exist_path[PATH_SIZE];
    int current_i = 0;
    int current_j = 0;
    while (scanf("%c", &info) == 1)
    {
        if (isalpha(info))
        {
            current_letter = info;
            current_i = 0;
            current_j = 0;
        }
        else if (isdigit(info))
        {
            printf("%c\n", current_letter);
            if (current_letter == 'A')
            {
                // Get matrics from user
                matrix[current_i][current_j] = (int)info;
                if (current_j >= 9)
                {
                    current_j = 0;
                    current_i++;
                }
                else
                {
                    current_j++;
                }
            }
            else if (current_letter == 'B')
            {
                // Get i, j to check if there ia a path between i and j
                if (current_i < 2)
                {
                    exist_path[current_i] = (int)info;
                    current_i++;
                }
                if (current_i == 2)
                {
                    existingPath(exist_path[0], exist_path[1]);
                }
            }

            else if (current_letter == 'C')
            {
                // Get i, j to recieve the sohortest course between them, else return -1
                if (current_i < 2)
                {
                    exist_path[current_i] = (int)info;
                    current_i++;
                }
                if (current_i == 2)
                {
                    shortestCourse(exist_path[0], exist_path[1]);
                }
            }
            else if (current_letter == 'D')
            {
                return 0;
            }
        }
    }
    int row, columns;
    for (row = 0; row < MATRIX_SIZE; row++)
    {
        for (columns = 0; columns < MATRIX_SIZE; columns++)
        {
            printf("%c     ", matrix[row][columns]);
        }
        printf("\n\n");
    }
    return 0;
}