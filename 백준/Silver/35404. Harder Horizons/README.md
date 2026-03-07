# [Silver IV] Harder Horizons - 35404 

[문제 링크](https://www.acmicpc.net/problem/35404) 

### 성능 요약

메모리: 23468 KB, 시간: 180 ms

### 분류

그리디 알고리즘

### 제출 일자

2026년 3월 7일 17:57:10

### 문제 설명

<p>Lola keeps a long to-do list of tasks she needs to finish. Each task has a difficulty number (the bigger the number, the harder the task), and the tasks must be completed in the order they appear.</p>

<p>The list keeps growing because items are rarely removed. Tired of that, Lola decided to take action: she wants to split her list into several consecutive groups of tasks, where each group represents the work she will do in one day.</p>

<p>To stay motivated, Lola wants to feel that each day is a step forward. So, starting from the second day, the hardest task of that day must be strictly harder than the hardest task from the previous day.</p>

<p>Lola also does not want to do too much in one day, so she wants to spread the work over as many days as possible.</p>

<p>What is the maximum number of days she can split the tasks into under these rules?</p>

### 입력 

 <p>The first line contains an integer $N$ ($1 \le N \le 10^5$) indicating the number of tasks. The second line contains $N$ integers $D_1, D_2, \ldots, D_N$ ($1 \le D_i \le 10^5$ for $i = 1, 2, \ldots, N$), representing the difficulties of the tasks in the order they appear in the list.</p>

### 출력 

 <p>Output a single line with an integer indicating the maximum number of days Lola can split the tasks into, such that the hardest task in each day is strictly harder than the hardest task in the previous day.</p>

