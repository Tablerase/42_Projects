function removeDuplicates(nums: number[]): number {
  if (nums.length === 0){
    return 0;
  }
  let write_index = 1;
  for (let i= 1; i < nums.length; i++){
    // console.log('Index',i,'Value',value, 'Last array val', new_nums[write_index - 1]);
    if (nums[i] != nums[write_index - 1]){
      // console.log('Adding ', value);
      nums[write_index] = nums[i];
      write_index += 1;
    }
  }
  // console.log('Pre assign', new_nums);
  return write_index;
};
//
let nums: number[] = [-1,0,0,0,0,3,3]
const r = removeDuplicates(nums)
console.log('Result: ', r, nums.slice(0, r));

