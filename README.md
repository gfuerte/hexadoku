# Hexadoku
Hexadoku is an extension of the logic puzzle Sudoku. The objective in Hexadoku is to fill a 16x16 gride of cells with each
cell containing a hexadecimal digit (a number in the set 0-F) while satisfying the following constraints:
• Each number is unique in its row and column.
• Each number is unique in its subgrid where a subgrid is defined by cutting the 16x16 grid into 16 non-overlapping 4x4 grids.
• Each row, column, and subgrid have all numbers from a hexadecimal digit(0-F) present.
A Hexadoku is defined as solved when all of its cells in the 16x16 grid are filled with numbers
with each cell satisfying the constraints above. A Hexadoku is defined as unsolvable when there is no
configuration where all the cells can be filled without breaking the constraints. A Hexadoku will start
partially completed with some numbers placed in the 16x16 grid. This will allow the solver to determine
where to place new numbers in order to find the solution for the given Hexadoku. For this part, we will
only be looking at Hexadoku grids with one unique solution.
