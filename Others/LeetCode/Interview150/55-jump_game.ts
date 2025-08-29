function recursJump(nums: number[], index: number, memo: Map<number, boolean>): boolean {
  if (index >= nums.length - 1){
    return true;
  }
  if (memo.has(index)) {
    return memo.get(index)!;
  } 
  if (nums[index] === 0){
    // console.log('End reach at', index, 'value', nums[index]);
    memo.set(index, false);
    return false;
  }
  for (let i = 1; i <= nums[index]; i++){
    if (recursJump(nums, index + i, memo)){
      memo.set(index, true);
      return true;
    }
  }
  memo.set(index, false);
  return false;
}

function canJump(nums: number[]): boolean {
  if (!nums){
    return false;
  }
  return recursJump(nums, 0, new Map());
};

const test : number[] = [2,3,1,1,4]; 
console.log('Origin:', test);
console.log('Result:', canJump(test));
const test2 : number[] = [3,2,1,0,4];
console.log('Origin:', test2);
console.log('Result:', canJump(test2));

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//
// Return true if you can reach the last index, or false otherwise.
//
//
//
// Example 1:
//
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
//
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
