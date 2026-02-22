const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const answer = input.map((str) => {
  const [s, t] = str.split(" ");
  const [isSub] = t.split("").reduce(
    ([isSub, idx], v) => {
      const nextIdx = !isSub && s[idx] === v ? idx + 1 : idx;
      return [nextIdx === s.length, nextIdx];
    },
    [false, 0]
  );
  return isSub ? "Yes" : "No";
});
console.log(answer.join("\n"));
