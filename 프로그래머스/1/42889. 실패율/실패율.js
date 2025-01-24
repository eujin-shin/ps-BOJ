function solution(N, stages) {
    const userCounts = Array(N).fill(0);
    stages.forEach((stage) => {if(stage <= N) userCounts[stage - 1]++});
    
    const failures = [];
    userCounts.reduce((leftUser, user, i) => {
        failures.push({stage: i + 1, failure: user / leftUser});
        return leftUser - user;
    }, stages.length);
    
    return failures.sort((a, b) => a.failure === b.failure ? a.stage - b.stage : b.failure - a.failure).map((v => v.stage));
}