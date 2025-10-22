const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const soundex = ["BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"];
const match = new Map(
  soundex.map((v, idx) => v.split("").map((l) => [l, idx + 1])).flat()
);
input.forEach((word) => {
  console.log(
    [...word]
      .map((v) => match.get(v) || "")
      .filter((v, idx, arr) => idx === 0 || v !== arr[idx - 1])
      .join("")
  );
});
