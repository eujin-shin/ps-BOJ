month, date = map(int, input().split())
dayArr = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
monthArr = [30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]
sum = 0
if month==1:
  sum=date-1
else:
  for i in range(month-1):
    sum=sum+monthArr[i]
  sum=sum+date
print(dayArr[sum%7])