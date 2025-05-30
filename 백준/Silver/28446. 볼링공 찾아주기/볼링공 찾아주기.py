import sys

input = sys.stdin.readline

n = int(input())

dit = dict()
for _ in range(n):
    command = input().split()
    if command[0] == "1":
        dit[command[2]] = command[1]
    else:
        sys.stdout.write(dit[command[1]]+"\n")
sys.stdout.flush()