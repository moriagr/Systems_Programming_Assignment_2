#include "my_mat.h"
#include "my_mat.c"
#include <stdio.h>
#include <ctype.h>
#ifndef MATRIX_SIZE
#define MATRIX_SIZE 10
#endif
#ifndef MAX_NUMBER
#define MAX_NUMBER 999999
#endif
#ifndef PATH_SIZE
#define PATH_SIZE 2
#endif

int main()
{
    char info;
    char current_letter;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int min_dist_matrix[MATRIX_SIZE][MATRIX_SIZE];
    int exist_path[PATH_SIZE];
    int current_i = 0;
    int current_j = 0;
    int min_dist_matrix_not_full = 0;
    int number = -1;
    int bool;
    while (scanf("%c", &info) == 1)
    {
        if (isalpha(info))
        {
            if (info == 'A')
            {
                min_dist_matrix_not_full = 0;
            }
            current_letter = info;
            current_i = 0;
            current_j = 0;
        }
        else if (isdigit(info))
        {
            if (number == -1)
            {
                number = (info - '0');
            }
            else
            {
                number = number * 10 + (info - '0');
            }
        }

        else if (isspace(info))
        {
            if (current_letter == 'A')
            {
                if (number != -1)

                // Get matrics from user
                {
                    matrix[current_i][current_j] = number;
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
            }
            else if (current_letter == 'B')
            {
                if (number != -1)
                {
                    // Get i, j to check if there ia a path between i and j
                    if (current_i < 2)
                    {
                        exist_path[current_i] = number;
                        current_i++;
                    }
                    if (current_i == 2)
                    {
                        bool = existingPath(exist_path[0], exist_path[1], matrix, min_dist_matrix, min_dist_matrix_not_full);
                        min_dist_matrix_not_full = 1;
                        if (bool == 0)
                        {
                            printf("False\n");
                        }
                        else if (bool == 1)
                        {
                            printf("True\n");
                        }
                    }
                }
            }

            else if (current_letter == 'C')
            {
                if (number != -1)
                {
                    // Get i, j to recieve the sohortest course between them, else return -1
                    if (current_i < 2)
                    {
                        exist_path[current_i] = (int)(number);
                        current_i++;
                    }
                    if (current_i == 2)
                    {
                        int num = shortestCourse(exist_path[0], exist_path[1], matrix, min_dist_matrix, min_dist_matrix_not_full);
                        min_dist_matrix_not_full = 1;
                        if (num == MAX_NUMBER)
                        {
                            printf("-1\n");
                        }
                        else
                        {
                            printf("%d\n", num);
                        }
                    }
                }
            }
            else if (current_letter == 'D')
            {
                return 0;
            }
            number = -1;
        }
    }

    // int row, columns;
    // printf("\n");
    // for (row = 0; row < MATRIX_SIZE; row++)
    // {
    //     for (columns = 0; columns < MATRIX_SIZE; columns++)
    //     {
    //         printf("%d     ", min_dist_matrix[row][columns]);
    //     }
    //     printf("\n\n");
    // }
    return 0;
}