/**
 * @file solution.c
 * @author Nathan Winslow (natelostintimeandspace@gmail.com)
 * @brief A Sudoku solver using recursion and bitmasking.
 * @version 0.1
 * @date 2024-09-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../sudoku_solver.h"

int get_box_index(int i, int j) { 
  return i / 3 * 3 + j / 3; 
}

bool is_safe(int row_index, int col_index, int number) {
  return !((row[row_index] >> number) & 1) 
    && !((col[col_index] >> number) & 1) 
    && !((box[get_box_index(row_index, col_index)] >> number) & 1);
}

void init_vals(int grid[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      row[i] |= 1 << grid[i][j],
      col[j] |= 1 << grid[i][j],
      box[get_box_index(i, j)] |= 1 << grid[i][j];
    }
  }
}

bool solve_sudoku(int grid[N][N], int row_index, int col_index) {
  if (!is_set) {
    is_set = true;
    init_vals(grid);
  }

  if (row_index == N - 1 && col_index == N) {
    return true;
  } 
  if (col_index == N) {
    col_index = 0;
    row_index++;
  }

  if (grid[row_index][col_index]) {
    return solve_sudoku(grid, row_index, col_index + 1);
  } 

  for (int nr = 1; nr <= N; ++nr) {
    if (is_safe(row_index, col_index, nr)) {
      grid[row_index][col_index] = nr;
      row[row_index] |= 1 << nr;
      col[col_index] |= 1 << nr;
      box[get_box_index(row_index, col_index)] |= 1 << nr;

      if (solve_sudoku(grid, row_index, col_index + 1)) {
        return true;
      }

      // Remove nr from each bitmask
      // and search for another possibility
      row[row_index] &= ~(1 << nr);
      col[col_index] &= ~(1 << nr);
      box[get_box_index(row_index, col_index)] &= ~(1 << nr);
    }
    grid[row_index][col_index] = 0;
  }
  return false;
}

void print_solution(int grid[N][N]) {
  for (int i = 0; i < N; ++i){
    printf("\n");
    for (int j = 0; j < N; ++j) {
      printf("%i ", grid[i][j]);
    }
  } 
  printf("\n");
}
/* End of file */
