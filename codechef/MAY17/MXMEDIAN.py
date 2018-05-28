for test in range(int(raw_input())):
	N=int(raw_input())
	arr=[int(i) for i in raw_input().split()]
	arr.sort()
	temp = arr[N:]
	print temp[N/2]
	for j in range(N):
	print arr[j],arr[j+N],
	print