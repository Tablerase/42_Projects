/**
 * bun run --hot file.ts
 */


/**

On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n - 1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.

*/

function getRandomColorCode(): number {
  return Math.floor(Math.random() * (231 - 16 + 1)) + 16;
};

function formatColorSquare(colorCode: number, text: string) {
  // \x1b[48;5;{code}m = background color
  // \x1b[30m         = dark text so the number stays readable
  // \x1b[1m          = bold text
  // \x1b[0m          = reset formatting
  return `\x1b[48;5;${colorCode}m\x1b[30m\x1b[1m  ${text}  \x1b[0m`;
};

interface LogInfo {
  id: number;
  status: "start" | "end",
  timestamp: number,
}

function exclusiveTime(n: number, logs: string[]): number[] {
  const res: number[] = [];

  const squares: string[] = [];
  const funcColors: number[] = [];
  for (let index = 0; index < n; index++) {
    funcColors.push(getRandomColorCode());
  }

  let maxTimestamp = 0;
  const logArray: LogInfo[] = [];

  logs.forEach((log) => {
    const infos = log.split(":");
    const res = {
      id: Number(infos[0]),
      status: infos[1],
      timestamp: Number(infos[2])
    } as LogInfo;
    logArray.push(res);
    if (res.timestamp > maxTimestamp) {
      maxTimestamp = res.timestamp;
    }
  })
  console.debug("maxTimestamp", maxTimestamp);

  function readLog(index: number): LogInfo {
    const currentLogData = logs[index].split(":");
    const currentLog: LogInfo = { id: Number(currentLogData[0]), status: currentLogData[1] as "end" | "start", timestamp: Number(currentLogData[2]) }
    return currentLog;
  }

  let time = 0;
  let logIndex = 0;
  const callStack: LogInfo[] = [];
  let currentLog: LogInfo = readLog(logIndex);
  while (time <= maxTimestamp) {
    // iterate over timestamp
    // read log to find what happens at timestamp

    // TODO: handle multiple event during the same unit of time (start / end for different function)
    // TODO: handle function that span over a single unit of time
    while (
      (currentLog = readLog(logIndex)) &&
      currentLog.timestamp == time &&
      logIndex < logArray.length - 1
    ) {
      // console.log(currentLog, time);

      // add new function when start
      if (currentLog.status === 'start' && currentLog.timestamp <= time) {
        callStack.push(currentLog);
        res[currentLog.id] = isNaN(res[currentLog.id]) ? 1 : res[currentLog.id] + 1;
        squares.push(formatColorSquare(funcColors[currentLog.id], time.toString()));
        logIndex++;
        continue;
      }

      // pop function when end
      if (currentLog.status === 'end' && currentLog.timestamp <= time) {
        callStack.pop();
        res[currentLog.id] = isNaN(res[currentLog.id]) ? 1 : res[currentLog.id] + 1;
        squares.push(formatColorSquare(funcColors[currentLog.id], time.toString()));
        logIndex++;
        continue;
      }
    }

    // count increase on last/top function of the call stack
    const topFunction = callStack[callStack.length > 0 ? callStack.length - 1 : 0];
    if (topFunction) {
      res[topFunction.id] = isNaN(res[topFunction.id]) ? 1 : res[topFunction.id] + 1;
      squares.push(formatColorSquare(funcColors[topFunction.id], time.toString()));
    }

    time++
  }
  console.debug(squares.join(" "));

  // let time = 0;
  // let logIndex = 0;
  // while (time <= maxTimestamp) {
  //   if (
  //     logArray[logIndex + 1 < logArray.length ? logIndex + 1 : logArray.length - 1].timestamp <= time
  //   ) {
  //     if (logIndex + 1 < logArray.length) {
  //       logIndex++;
  //       continue;
  //     }
  //   }
  //   res[logArray[logIndex].id] = isNaN(res[logArray[logIndex].id]) ? 1 : res[logArray[logIndex].id] + 1;
  //   squares.push(formatColorSquare(funcColors[logArray[logIndex].id], time.toString()));
  //   time++;
  // }
  // console.debug(squares.join(" "));

  return res;
};

function test(n: number, logs: string[], expected: number[]) {
  console.debug("=".repeat(50));
  console.debug("functions:", n, "logs:", logs)
  console.debug("expected:", expected, exclusiveTime(n, logs));
};

test(2, ["0:start:0", "1:start:2", "1:end:5", "0:end:6"], [3, 4]);
test(1, ["0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"], [8]);
test(2, ["0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"], [7, 1]);
test(8, ["0:start:0", "1:start:5", "2:start:6", "3:start:9", "4:start:11", "5:start:12", "6:start:14", "7:start:15", "1:start:24", "1:end:29", "7:end:34", "6:end:37", "5:end:39", "4:end:40", "3:end:45", "0:start:49", "0:end:54", "5:start:55", "5:end:59", "4:start:63", "4:end:66", "2:start:69", "2:end:70", "2:start:74", "6:start:78", "0:start:79", "0:end:80", "6:end:85", "1:start:89", "1:end:93", "2:end:96", "2:end:100", "1:end:102", "2:start:105", "2:end:109", "0:end:114"], [20, 14, 35, 7, 6, 9, 10, 14]);

