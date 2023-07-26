numArr = list(map(int, input().split(' ')))
numSet = set(numArr)
numList = list(numSet)
numList.sort(reverse=True)
max = numList[0]
if len(numList)==1:
  ans = 1000*max+10000
elif len(numList)==2:
  numArr.remove(numList[0])
  numArr.remove(numList[1])
  ans = 100*numArr[0]+1000
else:
  ans = 100*max
print(ans)