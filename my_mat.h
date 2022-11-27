#ifndef MATRIX_SIZE
#define MATRIX_SIZE 10
#endif

int existingPath(int i, int j, int (* matrix)[MATRIX_SIZE], int (* min_dist_matrix)[MATRIX_SIZE], int min_dist_matrix_not_full);

int shortestCourse(int i, int j, int (* matrix)[MATRIX_SIZE], int (* min_dist_matrix)[MATRIX_SIZE], int min_dist_matrix_not_full);