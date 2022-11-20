// #include "my_mat.h"
#include <stdio.h>
#include <ctype.h>
// #ifndef NUM_IN_FILE
// #define NUM_IN_FILE 2
// #endif

int main(int argc, char *argv[])
{
    int info;
    // int numberArray[NUM_IN_FILE];
    // int num_in_array = 0;
    while (scanf("%lc", &info) == 1)
    {
        printf("%lc:   ", info);
        if (isalpha(info))
        {
            printf("it's a letter");
        }
        else if (isdigit(info))
        {
            printf("it's a digit");
        }
        else
        {
            printf("something else?");
        }
        printf("\n");
    }
    if (info == 'A')
    {
        printf("Get matrics from user");
    }
    else if (info == "B")
    {
        printf("Get i, j to check if there ia a path between i and j");
    }
    else if (info == "C")
    {
        printf("Get i, j to check if there ia a path between i and j");
    }
    else if (info == "D")
    {
        printf("Get i, j to recieve the sohortest course between them, else return -1");
    }
    else{
        return 0;
    }
    return 0;
}