/**
*
Given an integer x, return true if x is a palindrome, and false otherwise.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

function isPalindrome(x: number): boolean {
  if (x < 0) {
    return false;
  }
  let rev = 0;
  let tmp_x: number = x;
  while (tmp_x) {
    rev = (rev * 10) + (tmp_x % 10);
    tmp_x = Math.floor(tmp_x / 10);
    // console.log("rev", rev, "tmp_x", tmp_x, "x", x)
  }
  if (x == rev) {
    return true
  } else {
    return false
  }
};

function test(x: number, expected: boolean) {
  console.log('='.repeat(50))
  console.log('value:', x);
  console.log('result:', isPalindrome(x))
  console.log('expected:', expected)
}

test(121, true)
test(-121, false)
test(10, false)

