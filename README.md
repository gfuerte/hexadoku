# Hexadoku
Hexadoku is an extension of the logic puzzle Sudoku. The objective in Hexadoku is to fill a 16x16 gride of cells with each cell containing a hexadecimal digit (a number in the set 0-F) while satisfying the following constraints:

• Each number is unique in its row and column.

• Each number is unique in its subgrid where a subgrid is defined by cutting the 16x16 grid into 16 non-overlapping 4x4 grids.

• Each row, column, and subgrid have all numbers from a hexadecimal digit(0-F) present.

A Hexadoku is defined as solved when all of its cells in the 16x16 grid are filled with numbers with each cell satisfying the constraints above. A Hexadoku is defined as unsolvable when there is no configuration where all the cells can be filled without breaking the constraints. A Hexadoku will start partially completed with some numbers placed in the 16x16 grid. This will allow the solver to determine where to place new numbers in order to find the solution for the given Hexadoku. For this part, we will only be looking at Hexadoku grids with one unique solution.

Though, it is not always possible to fill at least one element with 100% certainity in each step for many Hexadoku grids. Sometimes the next step to be taken cannot be known and instead, a guess must be taken in order to move forward, such as perhaps filling in a cell randomly. 

Once no more nodes can be filled with 100% certainty, this program will continue by taking the first unsolved cell (let’s call this cell A) and filling it with a number that satisfies the constraints and continue solving as usual from there. If a solution is found, then it is done. Otherwise, if no moves can be taken and the board has not yet been filled, then it will backtrack to the state where it guessed the value of cell A and either guess a new value for cell A or perhaps choose a new cell altogether.
