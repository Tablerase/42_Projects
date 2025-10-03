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
  let sumFound = false;
  let minWindowLen = nums.length;
  // Reduce window length till 1 is reach
  for (let index = 0; index < nums.length; index++) {
    // Search in window length
    let currWindowLen = 1;
    let currSum = 0;
    for (let windowIndex = 0; windowIndex < minWindowLen && windowIndex + index < nums.length; windowIndex++) {
      currSum = currSum + nums[index + windowIndex];
      // console.log("CurrentSum", currSum, "Index:", index, "windowIndex:", windowIndex, "currWindowLen", currWindowLen);
      // Update if sum reached
      if (currSum >= target) {
        sumFound = true;
        if (currWindowLen < minWindowLen) {
          minWindowLen = currWindowLen;
          if (minWindowLen == 1) {
            return 1;
          }
          break;
        }
      }
      currWindowLen++;
    }
    // console.log("=".repeat(50));
  }

  return sumFound ? minWindowLen : 0;
};

function test(target: number, nums: number[], expected: number) {
  console.log("Array: ", nums, "Target: ", target);
  console.log("Result:", minSubArrayLen(target, nums), "Expected:", expected);
}

test(7, [2, 3, 1, 2, 4, 3], 2)
test(4, [1, 4, 4], 1)
test(11, [1, 1, 1, 1, 1, 1, 1, 1], 0)
test(11, [1, 2, 3, 4, 5], 3)
