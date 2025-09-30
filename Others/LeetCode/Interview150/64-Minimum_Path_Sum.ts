/**
 * To debug:
 * deno run --watch file.ts
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */

function minPathSum(grid: number[][]): number {
  const r = grid.length;
  const c = grid[0].length;
  console.log("r: ", r, "c: ", c);
  console.log("start: ", 0, 0, "end: ", r - 1, c - 1);

  // Store sum dynamically
  let dp: number[][] = Array.from({ length: r }, () => Array(c).fill(0));
  dp[0][0] = grid[0][0];

  // Fill first row
  for (let i = 1; i < c; i++) {
    dp[0][i] = grid[0][i] + dp[0][i - 1];
  }
  // Fill first column
  for (let j = 1; j < r; j++) {
    dp[j][0] = grid[j][0] + dp[j - 1][0];
  }

  dp.forEach((element) => {
    console.log(element);
  });
  // Find min path
  for (let i = 1; i < r; i++) {
    for (let j = 1; j < c; j++) {
      dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  console.log("=".repeat(30));
  dp.forEach((element) => {
    console.log(element);
  });
  return dp[r - 1][c - 1];
}

let grid = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1],
];
// let grid2 = [[1,2,3],[4,5,6]]
let grid2 = [
  [1, 2],
  [5, 6],
  [1, 1],
];

(grid.forEach((element) => {
  console.log(element);
}),
  console.log("minPathSum", minPathSum(grid)));
console.log("=".repeat(50));
(grid2.forEach((element) => {
  console.log(element);
}),
  console.log("minPathSum", minPathSum(grid2)));
