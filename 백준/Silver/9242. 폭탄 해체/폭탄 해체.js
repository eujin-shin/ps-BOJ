const fs = require("fs");
const input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .split("\n")
  .map((str) => str.replace(/\r/g, "").split(""));
const numbers = [
  ["***", "* *", "* *", "* *", "***"],
  ["  *", "  *", "  *", "  *", "  *"],
  ["***", "  *", "***", "*  ", "***"],
  ["***", "  *", "***", "  *", "***"],
  ["* *", "* *", "***", "  *", "  *"],
  ["***", "*  ", "***", "  *", "***"],
  ["***", "*  ", "***", "* *", "***"],
  ["***", "  *", "  *", "  *", "  *"],
  ["***", "* *", "***", "* *", "***"],
  ["***", "* *", "***", "  *", "***"],
];
let code = 0;
for (let i = 0; i < input[0]?.length && code !== -1; i += 4) {
  const number = input.map((str) => str.slice(i, i + 3).join(""));
  const decode = numbers.findIndex((value) =>
    value.every((word, index) => word === number[index])
  );
  code = decode === -1 ? -1 : code * 10 + decode;
}
console.log(code === -1 || code % 6 !== 0 ? "BOOM!!" : "BEER!!");
