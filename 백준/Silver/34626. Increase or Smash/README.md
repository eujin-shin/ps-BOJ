# [Silver V] Increase or Smash - 34626 

[문제 링크](https://www.acmicpc.net/problem/34626) 

### 성능 요약

메모리: 11808 KB, 시간: 164 ms

### 분류

그리디 알고리즘, 애드 혹

### 제출 일자

2026년 1월 19일 19:40:53

### 문제 설명

<p>Geumjae has an array $a$ consisting of $n$ zeros. His goal is to transform it into a given target array using a minimum number of operations.</p>

<p>He can perform the following two types of operations any number of times, in any order:</p>

<ol>
<li><strong>Increase</strong>: Choose any positive integer $x$. Increase <em>all</em> elements of the array $a$ by $x$. In other words, he chooses a positive integer $x$, and for each $i$ ($1 \le i \le n$), he replaces $a_i$ with $a_i + x$.</li>
<li><strong>Smash</strong>: Set <em>some</em> elements (possibly none or all) of the array $a$ to $0$. In other words, for each $i$ ($1 \le i \le n$), he either replaces $a_i$ with $0$ or leaves it as before.</li>
</ol>

<p>Given the final target state of the array $a$, find the minimum total number of operations (both <strong>Increase</strong> and <strong>Smash</strong>) Geumjae needs to perform.</p>

<p>It can be shown that for any given final array, a sequence of operations always exists.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.</p>

<p>The first line contains a single integer $n$ ($1 \le n \le 100$) --- the number of elements in the array $a$.</p>

<p>The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 100$) --- the elements of the target array $a$.</p>

### 출력 

 <p>For each test case, output a single integer --- the minimum number of operations required.</p>

