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
  // rm edge case
  if (n == 1) return n;

  let sum = 0;
  // store value from end so iteration is done in from both array start and end
  let endMap = new Map<number, number>;
  endMap.set(n, n);
  // Iterate in both direction at the same time
  for (let index = 1; index < n; index++) {
    sum = sum + index;
    const indexEnd = n - index + 1;
    const endSum = endMap.get(indexEnd)! + (n - index);
    endMap.set(n - index, endSum);

    // console.debug(n - index, endMap.get(indexEnd));
    // console.debug('sum', sum, 'endSum', endSum, 'endMap', endMap);
    if (sum == endMap.get(index)) {
      return index;
    }
  }
  return -1;
};

console.log('Pivot finding');
console.log('Interger: 8, Pivot: ', pivotInteger(8));
console.log('Interger: 1, Pivot: ', pivotInteger(1));
console.log('Interger: 4, Pivot: ', pivotInteger(4));
