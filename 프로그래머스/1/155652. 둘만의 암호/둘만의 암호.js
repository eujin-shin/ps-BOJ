function solution(s, skip, index) {
    const base = "abcdefghijklmnopqrstuvwxyz".replaceAll(new RegExp(`[${skip.split('').join('|')}]`, "g"), "").repeat(3);

    return s.split("").map((letter) => base.at(base.indexOf(letter) + index)).join('');
}