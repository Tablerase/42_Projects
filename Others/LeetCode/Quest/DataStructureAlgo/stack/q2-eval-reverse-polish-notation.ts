/**
 * deno run --watch file.ts
 */


/**
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

https://en.wikipedia.org/wiki/Reverse_Polish_notation

*/

function evalRPN(tokens: string[]): number {
  const stack: number[] = [];
  for (const token of tokens) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      const b = stack.pop() ?? 0;
      const a = stack.pop() ?? 0;

      switch (token) {
        case "+":
          stack.push(a + b);
          break;
        case "-":
          stack.push(a - b);
          break;
        case "*":
          stack.push(a * b);
          break;
        case "/":
          stack.push(Math.trunc(a / b));
          break;
        default:
          console.error("No data");
          break;
      }
    } else {
      stack.push(Number(token));
    }
  }

  return stack.pop() ?? 0;
};

function test(tokens: string[], expected: number) {
  console.log("target:", tokens, "res:", evalRPN(tokens), "expected:", expected);
}

test(["2", "1", "+", "3", "*"], 9);
test(["4", "13", "5", "/", "+"], 6);
