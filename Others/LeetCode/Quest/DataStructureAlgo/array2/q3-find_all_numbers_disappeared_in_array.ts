/**
 * deno run --watch file.ts
 */

function findDisappearedNumbers(nums: number[]): number[] {
  // Array nums
  // [1, n]
  const res : number[] = [];

  // neg marker on already seen num
  for (let index = 0; index < nums.length; index++) {
    const index_to_update: number = Math.abs(nums[index]) - 1;
    if (nums[index_to_update] > 0) {
      nums[index_to_update] *= -1;
    }
  }
  // add positive value to result
  for (let index = 0; index < nums.length; index++) {
    if (nums[index] > 0){
      res.push(index + 1);
    }
  }

  return res;
};

function test(nums: number[], expected: number[]) {
  console.log("=".repeat(50));
  console.log("Input", nums);
  const res = findDisappearedNumbers(nums);
  console.log("Result", res);
  console.log("Expected", expected);
}

test([4, 3, 2, 7, 8, 2, 3, 1], [5, 6]);
test([1, 1], [2]);
