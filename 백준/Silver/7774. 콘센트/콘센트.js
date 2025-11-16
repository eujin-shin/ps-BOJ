const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, arrA, arrB] = input.map((str) =>
  str
    .split(" ")
    .map(Number)
    .sort((a, b) => b - a)
);
const count = {
  a: 1,
  b: 0,
};
while (1) {
  if (count.b > 0 && arrB.length > 0) {
    count.b -= 1;
    count.a += arrB.shift();
  } else if (count.a > 0 && arrA.length > 0 && arrB.length > 0) {
    count.a -= 1;
    count.b += arrA.shift();
  } else {
    break;
  }
}
console.log(count.a);
