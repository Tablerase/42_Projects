/**
 * To debug:
 * deno run --watch file.ts
 */

function shuffle(nums: number[], n: number): number[] {
  const res: number[] = [];
  for (let it_x = 0, it_y = n; it_x < n; it_x++, it_y++) {
    // console.log(nums[it_x], nums[it_y]);
    res.push(nums[it_x]);
    res.push(nums[it_y]);
  }

  // console.log(res);
  return res;
};


console.log("=".repeat(20), "[Shuffle]", "=".repeat(20));

let nums = [2, 5, 1, 3, 4, 7];
let n = 3;
console.log(nums);
console.log(shuffle(nums, n));

nums = [1, 2, 3, 4, 4, 3, 2, 1];
n = 4;
console.log(nums);
console.log(shuffle(nums, n));

nums = [1, 1, 2, 2], n = 2;
console.log(nums);
console.log(shuffle(nums, n));

