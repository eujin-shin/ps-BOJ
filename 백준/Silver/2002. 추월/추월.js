const fs = require("fs");
const [firstLine, ...entry] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);
const out = entry.splice(n);

function solution(entry, out) {
  const checked = new Map(entry.map((name) => [name, false]));
  return out.reduce(
    ([target, count], name) => {
      if (name === entry[target]) {
        while (++target < entry.length) {
          if (!checked.get(entry[target])) {
            break;
          }
        }
        return [target, count];
      } else {
        checked.set(name, true);
        return [target, count + 1];
      }
    },
    [0, 0]
  )[1];
}

console.log(solution(entry, out));
