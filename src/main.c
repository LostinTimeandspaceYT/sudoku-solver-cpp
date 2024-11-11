#include "../sudoku_solver.h"

/* Entry point */
int main() {
  // 0 means unassigned cells
  int grid[N][N] = { 
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
  };
  printf("Sudoku to solve:");
  print_solution(grid);

  if (solve_sudoku(grid, 0, 0)) {
    printf("\n");
    printf("Sudoku solution:");
    print_solution(grid);
  } else {
    printf("No solution exists\n");
  }
  return 0;
}
