# [Bronze I] Triple Jump - 34646 

[문제 링크](https://www.acmicpc.net/problem/34646) 

### 성능 요약

메모리: 9588 KB, 시간: 92 ms

### 분류

수학, 애드 혹, 사칙연산

### 제출 일자

2025년 11월 16일 00:09:31

### 문제 설명

<p>You’re watching your friend playing a platformer game. In this game, when a player jumps in a straight line, there are three different integer distances they can choose to travel. You don’t know what the three are, but hope to find out by watching the gameplay.</p>

<p>You’ve seen your friend perform many “triple jumps” (i.e. three jumps in a row in the same direction) and recorded the total distance they traveled over all three jumps combined. In each triple jump, your friend can use any of the three integer differences, including repeating the same distance one or more times. After a long time of watching, you’ve recorded a list of unique distances, and are sure that all possible triple jump distances are in this list.</p>

<p>Given the distances you wrote down, can you recover the three distances?</p>

### 입력 

 <p>The first line of input contains a single integer $n$ ($7 \le n \le 10$), which is the number of unique observations you made.</p>

<p>The next line contains $n$ space separated integers $d$ ($1 \le d \le 1\, 000$). These are your observations, in strictly ascending order.</p>

### 출력 

 <p>Output three space-separated integers on a single line. These are the three jump distances. Output them in sorted order, smallest to largest. The three jump distances are guaranteed to be unique.</p>

