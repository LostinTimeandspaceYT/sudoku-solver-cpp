/**
 * @file sudoku_solver.h
 * @author Nathan Winslow (natelostintimeandspace@gmail.com)
 * @brief Implements a sudoku solver that uses recursion and bitmasking.
 * @version 0.1
 * @date 2024-09-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H
#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define N 9

static int row[N];
static int col[N];
static int box[N];
static bool is_set = false;

/**
 * @brief get the box index of an element at position [i][j] in the grid.
 * 
 * @param i row index
 * @param j col index
 * @return `int` box index
 */
int get_box_index(int i, int j);

/**
 * @brief check if a number is present in the correspondiong row/column/box
 * 
 * @param row_index row index
 * @param j col index
 * @param number number to check (1-9)
 * @return `true` if the number is not already present
 * @return `false` if the number is already present.
 */
bool is_safe(int row_index, int col_index, int number);

/**
 * @brief sets initial values of a sudoku board and maps the values in the 
 * bitmasks.
 * 
 * @param grid the sudoku grid
 */
void init_vals(int grid[N][N]); 

/**
 * @brief solves a sudoku puzzle of size [N][N]
 * 
 * @param grid the sudoku grid
 * @param row_index 0-8
 * @param col_index 0-8
 * @return `true` if a solution exists. 
 * @return `false` if no solution exists. 
 */
bool solve_sudoku(int grid[N][N], int row_index, int col_index);

/**
 * @brief prints out the solution of `solve_sudoku`
 * 
 * @param grid the sudoku grid
 */
void print_solution(int grid[N][N]);


#endif //END SUDOKU_SOLVER_H

#ifdef __cplusplus
}
#endif
/* End of File*/
