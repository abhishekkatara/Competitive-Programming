for test in range(int(raw_input())):
	n = int(raw_input())
	temp = 0
	arr = [int(x) for x in raw_input().split()]
	for j in range(len(arr)):
	if temp<arr[j]:
	temp = arr[j]
	 
	print (n-temp)