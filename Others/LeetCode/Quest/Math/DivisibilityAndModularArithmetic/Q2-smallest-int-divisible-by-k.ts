/**
 * deno run --watch file.ts
 */

/**
 *
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

Example 1:
  Input: k = 1
  Output: 1
  Explanation: The smallest answer is n = 1, which has length 1.
Example 2:
  Input: k = 2
  Output: -1
  Explanation: There is no such positive integer n divisible by 2.
Example 3:
  Input: k = 3
  Output: 3
  Explanation: The smallest answer is n = 111, which has length 3.
*/
function smallestRepunitDivByK(k: number): number {
  // 11111 not divisible by 2 and 5
  if (k == 2 || k == 5) {
    return -1;
  }

  let remainder = 0;
  for (let length = 1; length <= k; length++) {
    // add one at every loop (this modulo allows to avoid breaking integer limits)
    remainder = (remainder * 10 + 1) % k;
    if (remainder == 0) {
      return length;
    }
  }

  return -1;
};

console.debug("Test k = 1", smallestRepunitDivByK(1));
console.debug("Test k = 2", smallestRepunitDivByK(2));
console.debug("Test k = 3", smallestRepunitDivByK(3));
console.debug("Test k = 19", smallestRepunitDivByK(19)); // 18
