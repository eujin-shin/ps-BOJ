# [Silver II] 가위바위보 타일 - 32761 

[문제 링크](https://www.acmicpc.net/problem/32761) 

### 성능 요약

메모리: 9944 KB, 시간: 160 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 7월 5일 17:36:29

### 문제 설명

<p>$N$개의 타일이 원의 둘레를 따라 시계 방향으로 배치되어 있고, 각 타일에는 가위, 바위, 보를 상징하는 이니셜 <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>R</code></span>, <span style="color:#e74c3c;"><code>P</code></span>가 새겨져 있다. 이 타일 배치에서 일부 타일을 제거한 후 남은 $M$개의 타일을 $0$번부터 시계 방향으로 번호를 매겼을 때, 음이 아닌 임의의 정수 $i$에 대해 $i \pmod M$번 타일에 새겨진 가위바위보 문자가 $i+1 \pmod M$번 타일에 새겨진 가위바위보 문자를 항상 이기도록 적절히 타일을 제거하려 한다.</p>

<p>제거해야 할 최소 타일 개수를 출력해 보자.</p>

### 입력 

 <p>첫 번째 줄에 타일의 개수를 나타내는 정수 $N$이 주어진다.</p>

<p>두 번째 줄에 타일에 적힌 가위바위보 문자를 시계 방향으로 읽었을 때 나타나는 문자열 $S$가 주어진다. $S$는 길이가 $N$인 문자열이며 문자 <span style="color:#e74c3c;"><code>S</code></span>, <span style="color:#e74c3c;"><code>R</code></span>, <span style="color:#e74c3c;"><code>P</code></span> 만으로 구성되어 있다.</p>

<p>타일을 적절히 제거하여 조건을 만족하는 타일이 1개 이상 남도록 할 수 있음이 보장되는 입력만 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 제거해야 할 최소 타일 개수를 출력한다.</p>

