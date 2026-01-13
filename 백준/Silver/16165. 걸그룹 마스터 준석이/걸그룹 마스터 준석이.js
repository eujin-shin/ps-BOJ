const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const teams = new Map();
const members = new Map();
let idx = 0;
const [n, m] = input[idx++].split(" ").map(Number);
for (let i = 0; i < n; i++) {
  const team = input[idx++];
  const x = Number(input[idx++]);
  const member = input.slice(idx, idx + x).sort();
  teams.set(team, member);
  member.forEach((name) => members.set(name, team));
  idx += x;
}
for (let i = 0; i < m; i++) {
  const target = input[idx++];
  const q = Number(input[idx++]);
  console.log(q === 0 ? teams.get(target).join("\n") : members.get(target));
}
