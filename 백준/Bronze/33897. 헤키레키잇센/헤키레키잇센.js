const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], numbers] = input.map((str) => str.split(" ").map(Number));
const record = {
  count: 0,
  max: 0,
  current: 0,
};
for (let i = 0; i < n; i++) {
  if (i === 0 || numbers[i - 1] > numbers[i]) {
    record.count++;
    record.max = record.max < record.current ? record.current : record.max;
    record.current = 1;
  } else {
    record.current++;
  }
}
record.max = record.max < record.current ? record.current : record.max;
console.log(record.count, record.max);
