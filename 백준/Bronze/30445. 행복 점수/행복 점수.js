const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

const points = {
  happy: 0,
  sad: 0,
};
const happy = "HAPY";
const sad = "SAD";

[...input].forEach((v) => {
  points.happy += happy.includes(v);
  points.sad += sad.includes(v);
});

const score =
  points.happy === 0 && points.sad === 0
    ? 50
    : Math.round((points.happy / (points.happy + points.sad)) * 10000) / 100;

console.log(score.toFixed(2));
