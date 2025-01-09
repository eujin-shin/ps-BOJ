function solution(common) {
    const [first, second, ] = common;
    const last = common[common.length - 1];
    const [diff, ratio, ] = common.reduce(([diff, ratio, prev], cur, index) => {
        if(index === 0) {
            return [diff, ratio, cur];
        }
        return [(diff === cur - prev) ? diff : null, (ratio === cur / prev) ? ratio : null, cur];
    }, [second - first, second / first, 0])
    return diff !== null ? last + diff : last * ratio;
}