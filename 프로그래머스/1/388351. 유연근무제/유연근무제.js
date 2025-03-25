function solution(schedules, timelogs, startday) {
    const limits = schedules.map((schedule) => {
        const a = schedule + 10;
        return 60 <= a % 100 ? a + 40 : a;
    });
    
    const isWeekend = (idx) => {
        const temp = (startday - 1 + idx) % 7;
        return temp === 5 || temp === 6;
    }
    
    return timelogs.filter((timelog, id) => timelog.every((v, day) => isWeekend(day) || v <= limits[id])).length;
}