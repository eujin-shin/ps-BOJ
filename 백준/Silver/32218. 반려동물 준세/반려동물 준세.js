const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], list] = input.map((str) => str.split(" ").map(Number));

function solution(n, list) {
  let finish = false;
  let count = 0;

  const findBigger = (start, x) => {
    let result = 0;
    for (let i = start; i < n; i++) {
      result += x < list[i] ? 1 : 0;
    }
    return result;
  };

  while (!finish) {
    count++;
    finish = true;
    for (let i = 0; i < n; i++) {
      const nextX = findBigger(i + 1, list[i]);
      finish = finish && nextX === list[i];
      list[i] = nextX;
    }
  }
  return count;
}

console.log(solution(n, list));
