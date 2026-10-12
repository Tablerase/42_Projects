/**
 * deno run --watch file.ts
 */


/**
You are given an integer array target and an integer n.

You have an empty stack with the two following operations:

"Push": pushes an integer to the top of the stack.
"Pop": removes the integer on the top of the stack.
You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. You should follow the following rules:

If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
If the stack is not empty, pop the integer at the top of the stack.
If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.
Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.

*/

enum op {
  push = "Push",
  pop = "Pop"
}

function buildArray(target: number[], n: number): string[] {
  if (target.length < 1) {
    return [];
  }

  const res: string[] = [];
  const stack: number[] = []; // debug purpose
  let target_index = 0;
  for (let index = 1; index <= n; index++) {
    stack.push(index);
    // console.log("Index:", index)
    if (target[target_index] === index) {
      res.push(op.push);
      target_index++;
    } else {
      res.push(op.push);
      res.push(op.pop);
    }
    if (target.length === target_index) {
      break;
    }

    // console.log(stack)
    // console.log(res)
  }

  return res;
};

function test(target: number[], n: number) {
  console.log("target:", target, "res:", buildArray(target, n));
}

test([1, 3], 3);
test([1, 2, 3], 3);
test([1, 2], 4);
test([4, 6], 3);
