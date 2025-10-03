/**
 * To debug:
 * deno run --watch file.ts
 *
 *
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

TOPICS:
Array
Binary Search
Sliding Window
Prefix Sum

TIPS:
https://www.geeksforgeeks.org/dsa/segment-tree-data-structure/
https://algorithm-visualizer.org/dynamic-programming/sliding-window
 */


function minSubArrayLen(target: number, nums: number[]): number {
  let minWindowLen = Infinity;
  let currSum = 0;
  let windowLeft = 0;
  // Grow window till sum is reach
  for (let windowRight = 0; windowRight < nums.length; windowRight++) {
    console.log("=".repeat(10), "CurrentSum:", currSum, "+", nums[windowRight]);
    currSum += nums[windowRight];
    // Reduce window to find min window length for target sum
    while (currSum >= target) {
      minWindowLen = Math.min(minWindowLen, windowRight - windowLeft + 1);
      console.log("Window: ", windowLeft, windowRight, "CurrentSum:", currSum, "minWindowLen: ", minWindowLen);
      currSum -= nums[windowLeft];
      windowLeft++;
    }
  }

  return minWindowLen != Infinity ? minWindowLen : 0;
};

function test(target: number, nums: number[], expected: number) {
  console.log("Array: ", nums, "Target: ", target);
  console.log("Result:", minSubArrayLen(target, nums), "Expected:", expected);
}

test(15, [1, 2, 3, 4, 5], 5);
// test(7, [2, 3, 1, 2, 4, 3], 2)
// test(4, [1, 4, 4], 1)
// test(11, [1, 1, 1, 1, 1, 1, 1, 1], 0)
// test(11, [1, 2, 3, 4, 5], 3)
