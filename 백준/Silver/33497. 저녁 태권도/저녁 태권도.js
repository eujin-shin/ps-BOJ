const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], ...limits] = input.map((str) => str.split(" ").map(Number));

function solution(n, m, limits) {
  const answer = Array.from({ length: n }, () => Array.from({ length: m }));
  let absent = 0;
  for (let i = 0; i < m; i++) {
    const [am, pm] = limits[i];
    if (n < am + pm) {
      console.log("NO");
      return;
    }
    for (let j = 0; am + pm + j < n && absent < n; j++) {
      answer[absent % n][i] = "X";
      absent++;
    }
    for (let j = 0, count = 0; j < n; j++) {
      if (answer[j][i] === "X") {
        continue;
      }
      answer[j][i] = am < ++count ? "-" : "+";
    }
  }
  if (absent < n) {
    console.log("NO");
    return;
  }
  console.log("YES");
  for (let i = 0; i < n; i++) {
    console.log(answer[i].join(""));
  }
  return;
}

solution(n, m, limits);
