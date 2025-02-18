const fs = require("fs");
const arr = fs.readFileSync("/dev/stdin").toString().trim().split("");

function solution(arr) {
  for (let i = 1; i < arr.length; i++) {
    const front = arr[0] < arr[i] ? arr[0] : arr[i];
    const asc = arr.length === i + 1 || arr[i + 1] > front;
    if ((asc && front !== arr[0]) || (!asc && front !== arr[i])) {
      arr = arr
        .splice(0, i + 1)
        .reverse()
        .concat(arr);
    }
  }
  return arr.join("");
}

console.log(solution(arr));
