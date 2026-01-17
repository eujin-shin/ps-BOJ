const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const evenPrefix = [];
const odd = [];
const count = new Map();
input.split("").forEach((l) => count.set(l, (count.get(l) || 0) + 1));
[...count].forEach(([l, c]) => {
  if (c % 2 === 0) evenPrefix.push(l.repeat(c / 2));
  else odd.push(l.repeat(c));
});
console.log(Math.max(odd.length, 1));
if (odd.length === 0)
  console.log(evenPrefix.join("") + evenPrefix.reverse().join(""));
odd.forEach((v, idx) =>
  console.log(
    idx === 0 ? evenPrefix.join("") + v + evenPrefix.reverse().join("") : v
  )
);
