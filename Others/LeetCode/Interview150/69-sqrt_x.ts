/**
* 
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

function mySqrt(x: number): number {
  if (x < 2) return x;
  let end = x;
  let start = 0;
  while (start < end - 1) {
    // Reduce window of choice by half
    const mid = start + Math.floor((end - start) / 2);
    console.log(start, mid, end);
    const sqrt = mid * mid;
    if (sqrt == x) {
      return mid;
    }
    if (sqrt > x) {
      end = mid;
    } else {
      start = mid;
    }
  }
  return start;
};

function test(x: number, expected: number) {
  console.log('='.repeat(50))
  console.log('value:', x);
  console.log('result:', mySqrt(x))
  console.log('expected:', expected)
}

test(4, 2)
test(8, 2)
test(36, 6)
test(1400000, 1183)
test(6531091, 2555)
test(1, 1)
