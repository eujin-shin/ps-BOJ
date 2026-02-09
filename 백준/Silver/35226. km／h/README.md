# [Silver V] km/h - 35226 

[문제 링크](https://www.acmicpc.net/problem/35226) 

### 성능 요약

메모리: 9532 KB, 시간: 100 ms

### 분류

수학, 구현, 시뮬레이션

### 제출 일자

2026년 2월 9일 19:24:34

### 문제 설명

<p>Many countries have a “national speed limit”: a default maximum speed that applies unless a <em>speed limit sign</em> explicitly sets a lower one. Such a speed limit sign shows a number and overrides the default while it is in force. By contrast, a <em>derestriction sign</em> shows no number at all; it cancels the previous restriction and restores the national speed limit, which is always strictly higher than any speed limit sign.</p>

<p>You pride yourself on being a careful and attentive motorist. Whenever you encounter a speed limit sign, you smoothly and safely adjust your vehicle's speed. Alas, despite your otherwise impeccable memory, the derestriction sign always leaves you guessing. You simply cannot remember the national speed limit -- only that it was a neat multiple of ten.</p>

<p>As you encounter each sign -- limit or derestriction -- determine the fastest you can go while abiding the law, based only on what you've seen so far.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
<li>One line with an integer $N$ with $1\leq N\leq 100$, the number of signs.</li>
<li>$N$ lines, one for each sign. Each line describes either a speed limit or a derestriction. A speed limit is an integer $L$ with $10\leq L\leq 160$, the speed limit that applies from that sign. A derestriction is the forward slash"<code>/</code>", reminiscent of the sign's diagonal bar. The first line contains a speed limit. There are never two consecutive derestrictions.</li>
</ul>

### 출력 

 <p>Output $N$ integers, the maximum legal speed that can be inferred when passing the $i$th sign for $1\leq i\leq N$.</p>

