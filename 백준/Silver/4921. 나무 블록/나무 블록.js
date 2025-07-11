const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
function solution(block) {
  const n = block.length;
  if (block[0] !== "1" || block[n - 1] !== "2") return "NOT";
  let f = 0;
  let invalid = false;
  let before = block[0];
  for (let i = 1; i < n; i++) {
    switch (block[i]) {
      case "1":
        invalid = true;
        break;
      case "2":
        invalid = i !== n - 1 || (before !== "4" && before !== "6");
        break;
      case "3":
        invalid = before !== "4" && before !== "6";
        break;
      case "4":
        invalid = before !== "1" && before !== "3";
        break;
      case "5":
        f++;
        invalid = before !== "1" && before !== "3";
        break;
      case "6":
        invalid = f < 1 || before !== "8";
        f--;
        break;
      case "7":
        invalid = before !== "8";
        break;
      case "8":
        invalid = before !== "5" && before !== "7";
        break;
      default:
        break;
    }
    if (invalid) return "NOT";
    invalid = false;
    before = block[i];
  }
  return f === 0 ? "VALID" : "NOT";
}
for (let i = 0; i < input.length - 1; i++) {
  console.log(`${i + 1}. ${solution(input[i])}`);
}
