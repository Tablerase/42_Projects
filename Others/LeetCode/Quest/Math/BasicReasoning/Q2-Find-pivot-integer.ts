/**
 * To debug:
 * deno run --watch file.ts
 */

/**
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

Example 1:
 Input: n = 8
  Output: 6
  Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:
  Input: n = 1
  Output: 1
  Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:
  Input: n = 4
  Output: -1
  Explanation: It can be proved that no such integer exist.
 */

function pivotInteger(n: number): number {
  // Math formula
  /**
   * x (x + 1) / 2 = n (n + 1) / 2 - x ( x - 1) / 2
   * x (x + 1) = n (n + 1 ) - x ( x - 1)
   * x^2 + x = n^2 + n - x^2 + x
   * x^2 = n^2 + n - x^2
   * 2 x^2 = n^2 + n
   *         _____________
   * x^2 = \/ (n^2 + n) / 2
   */
  const x = Math.sqrt((Math.pow(n, 2) + n) / 2);
  return Number.isInteger(x) ? x : -1;
};

console.log('Pivot finding');
console.log('Interger: 8, Pivot: ', pivotInteger(8));
console.log('Interger: 1, Pivot: ', pivotInteger(1));
console.log('Interger: 4, Pivot: ', pivotInteger(4));
