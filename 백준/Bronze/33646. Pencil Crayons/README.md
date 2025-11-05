# [Bronze I] Pencil Crayons - 33646 

[문제 링크](https://www.acmicpc.net/problem/33646) 

### 성능 요약

메모리: 11192 KB, 시간: 88 ms

### 분류

구현, 그리디 알고리즘

### 제출 일자

2025년 11월 5일 22:01:58

### 문제 설명

<p>Mr. Daniels bought a set of $N$ identical boxes of pencil crayons for his classroom, each containing the same set of $K$ distinct colours of pencils. Over the course of the year, the pencil crayons got mixed up between the boxes. Surprisingly, none of them have been lost (yet). But some boxes may not have $K$ distinct colours any more.</p>

<p>Mr. Daniels has a gap in his schedule and the break room is currently undergoing maintenance. He might as well rearrange the pencil crayons so each box again has exactly $K$ distinct colours. To do this, he will first remove a number of pencil crayons from each box (perhaps $0$) and then place the removed pencil crayons back in boxes.</p>

<p>Help Mr. Daniels figure out the minimum number of pencil crayons that need to be removed so that he can place them back in boxes to ensure each box again has $K$ distinct colours of pencil crayons. The order the pencil crayons are arranged in a box does not matter, just that all $K$ colours are now present in each box.</p>

### 입력 

 <p>The first line of input contains two integers $N$ ($2≤N≤100$) and $K$ ($2≤K≤100$). Then $N$ lines follow. Each line describes the contents of a box by listing $K$ strings describing the pencil crayons that are currently found in that box.</p>

<p>Each string describing a colour will have a length between $1$ and $10$ and will only contain lowercase letters. There will be exactly $K$ distinct strings appearing among all rows describing the boxes and each such string will appear exactly $N$ times.</p>

### 출력 

 <p>Output a single number indicating the fewest pencil crayons that need to be removed from all boxes so that Mr. Daniels can place them back in the boxes while ensuring each box has exactly $K$ distinct colours.</p>

