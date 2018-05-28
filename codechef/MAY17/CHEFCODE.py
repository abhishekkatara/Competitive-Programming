from operator import mul
n,k = map(int,raw_input().split())
arr = map(int,raw_input().split())
count = 0
def set(arr):
	return reduce(lambda temp,j:temp+[sub_set+[j] for sub_set in temp],arr,[[]])
	sets = set(arr)
	for i in sets:
		x = i[:]
		if len(x)>0:
			final = reduce(mul,x)
			if k<final:
				count +=1
print (2**n-1)-count