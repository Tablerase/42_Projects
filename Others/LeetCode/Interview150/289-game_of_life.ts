/**
 * deno run --watch file.ts
 *
 Do not return anything, modify board in-place instead.

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article)

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

*/

interface Point {
  x: number,
  y: number,
}

function getNeightbors(board: number[][], position: Point): number {
  let result = 0;
  for (let yi = Math.max(position.y - 1, 0); yi <= Math.min(position.y + 1, board.length - 1); yi++) {
    for (let xi = Math.max(position.x - 1, 0); xi <= Math.min(position.x + 1, board[yi].length - 1); xi++) {
      if (position.y === yi && position.x === xi) {
        continue;
      }
      if (board[yi][xi] === 1) {
        result++;
      }
    }
  }

  return result;
}

function life(board: number[][], position: Point, neightbors: number) {
  const alive = board[position.y][position.x];
  if (alive) {
    // under-population
    if (neightbors < 2) {
      board[position.y][position.x] = 0;
      return;
    }
    // over-population
    if (neightbors > 3) {
      board[position.y][position.x] = 0;
      return;
    }
    // next generation
  } else {
    // reproduction
    if (neightbors === 3) {
      board[position.y][position.x] = 1;
    }
  }
}

function gameOfLife(board: number[][]): void {
  // Create future board
  let tempBoard = structuredClone(board);
  // Applying Life to tempBoard
  tempBoard.forEach((row, rowId) => {
    row.forEach((cell, cellId) => {
      const currentPos: Point = { y: rowId, x: cellId }
      let neightbors = getNeightbors(tempBoard, currentPos)
      // console.log("Position:", currentPos, "Neightbors:", neightbors)
      life(board, currentPos, neightbors);
      // console.log("tempBoard")
      // printBoard(tempBoard);
      // console.log("Board")
      // printBoard(board);
    })
  })
};

function printBoard(board: number[][]) {
  const line = "=".repeat(50);
  board.forEach((row) => {
    console.log(row)
  })
  console.log(line)
}

console.log("=".repeat(20), "[GameOfLife]", "=".repeat(20));

function test(board: number[][]) {
  console.log("~".repeat(50))
  printBoard(board);
  gameOfLife(board);
  printBoard(board);
}

test([[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]);
test([[1, 1], [1, 0]])


