const fs = require("fs");
const [target, search] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(target, search) {
  const getPi = () => {
    const arr = [0];
    let x = 0;
    for (let i = 1; i < search.length; i++) {
      while (0 < x && search[i] !== search[x]) {
        x = arr[x - 1];
      }
      arr[i] = search[i] === search[x] ? ++x : x;
    }
    return arr;
  };

  const pi = getPi();
  const stack = [];
  let t = 0;
  for (let i = 0; i < target.length; i++) {
    while (0 < t && target[i] !== search[t]) {
      t = pi[t - 1];
    }
    stack[stack.length] = [target[i] === search[t] ? ++t : 0, target[i]];
    if (t === search.length) {
      stack.splice(-t);
      t = stack[stack.length - 1]?.[0] || 0;
    }
  }
  return stack.length > 0 ? stack.map(([_, v]) => v).join("") : "FRULA";
}

console.log(solution(target, search));
