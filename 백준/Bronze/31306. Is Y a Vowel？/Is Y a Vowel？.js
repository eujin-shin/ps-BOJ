const fs = require("fs");
const string = fs.readFileSync("/dev/stdin").toString().trim();

function solution(string) {
  const vowels = string.match(/a|e|i|o|u/g)?.length || 0;
  const y = string.match(/y/g)?.length || 0;
  return [vowels, vowels + y];
}

console.log(...solution(string));
