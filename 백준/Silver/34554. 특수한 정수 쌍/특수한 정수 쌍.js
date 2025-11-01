const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const MAX = 10001;
const prime = Array.from({ length: MAX + 1 }, () => true);
for (let x = 2; x * 2 <= MAX; x++) {
  for (let i = x * 2; i <= MAX; i += x) {
    prime[i] = false;
  }
}
input.slice(1).forEach((str) => {
  const n = Number(str);
  if (prime[n + 1]) {
    console.log(1);
    console.log(1, n + 1);
  } else {
    console.log(0);
  }
});
