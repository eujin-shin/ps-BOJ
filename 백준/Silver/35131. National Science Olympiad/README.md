# [Silver V] National Science Olympiad - 35131 

[문제 링크](https://www.acmicpc.net/problem/35131) 

### 성능 요약

메모리: 9436 KB, 시간: 92 ms

### 분류

정렬

### 제출 일자

2026년 1월 15일 19:32:46

### 문제 설명

<p>In the recent National Science Olympiad, a new tie-breaker rule was implemented using time penalties measured in minutes.</p>

<p>The olympiad ran for two days and participated in by $N$ contestants. The $i$-th participant, whose name is $S_i$, received $A_i$ points with time penalty $B_i$ on the first day, and received $C_i$ points with time penalty $D_i$ on the second day.</p>

<p>The contestants are ranked based on their total points from both days, with <strong>higher points</strong> being ranked higher. Contestants who receive the same total points will be ranked based on the sum of their time penalties from both days, with <strong>lower penalties</strong> being ranked higher. If there are still ties, they will be ranked based on their name, with the <strong>lexicographically smaller name</strong> being ranked higher.</p>

<p>Your task is to output the name of the contestants ranked from highest to lowest.</p>

### 입력 

 <p>The first line contains an integer $N$ ($1 \le N \le 100$). Each of the next $N$ lines contains a string $S_i$ ($1 \leq |S_i| \leq 10$), containing uppercase English alphabets, followed by four integers $A_i$, $B_i$, $C_i$, and $D_i$ ($0 \le A_i, B_i, C_i, D_i \le 300$) representing their points and penalties from both days.</p>

### 출력 

 <p>Output $N$ lines, each containing the name of the contestants, in order from the higher-ranked to the lower-ranked.</p>

