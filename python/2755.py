N = int(input())
grade_list = ["F", "D", "C", "B", "A"]
grade_sum = 0
credit_sum = 0
for i in range(N):
  subject_list = list(input().split())
  x = grade_list.index(subject_list[2][0])
  if not "F" in subject_list[2]:
    if "+" in subject_list[2]:
      x += 0.3
    elif "-" in subject_list[2]:
      x -= 0.3
  y = int(subject_list[1])
  credit_sum += y
  grade_sum += x*y
ans = grade_sum / credit_sum + 0.000000001
print("%.2f" % ans)