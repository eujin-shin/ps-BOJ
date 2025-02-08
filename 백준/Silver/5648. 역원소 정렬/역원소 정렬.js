const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const words = [];
input.forEach((str) => {
  if (str !== "") words.push(...str.trim().split(" "));
});

function solution([n, ...numbers]) {
  return numbers
    .map((num) => Number(num.split("").reverse().join("")))
    .sort((a, b) => a - b);
}

const result = solution(words);
result.forEach((num) => console.log(num));
