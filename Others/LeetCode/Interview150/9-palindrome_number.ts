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
  const xs = String(x);
  let xs_rev = "";
  for (let lastchar = xs.length - 1; lastchar >= 0; lastchar--) {
    xs_rev = xs_rev.concat(xs[lastchar]);
  }
  // console.debug("String origine:", xs, "String reversed:", xs_rev);
  if (xs_rev === xs) {
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
