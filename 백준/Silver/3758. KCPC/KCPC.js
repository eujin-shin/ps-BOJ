const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((str) => str.split(" ").map(Number));

function solution(logs, teams, questions, x) {
  function Record() {
    this.scores = Array.from({ length: questions }, () => 0);
    this.scoreSum = 0;
    this.tryCount = 0;
    this.lastSubmit = 0;

    this.update = (newScore, question, tryTime) => {
      const prevScore = this.scores[question - 1];
      this.scores[question - 1] = prevScore < newScore ? newScore : prevScore;
      this.scoreSum += this.scores[question - 1] - prevScore;
      this.tryCount++;
      this.lastSubmit = tryTime;
    };
    this.isHigher = (compare) => {
      return (
        this.scoreSum > compare.scoreSum ||
        (this.scoreSum === compare.scoreSum &&
          (this.tryCount < compare.tryCount ||
            (this.tryCount === compare.tryCount &&
              this.lastSubmit < compare.lastSubmit)))
      );
    };
  }

  const records = Array.from({ length: teams }, () => new Record());
  logs.forEach(([t, q, s], idx) => records[t - 1].update(s, q, idx));

  return records.filter((v) => v.isHigher(records[x - 1])).length + 1;
}

while (0 < input.length) {
  const [[teams, questions, x, count]] = input.splice(0, 1);
  console.log(solution(input.splice(0, count), teams, questions, x));
}
