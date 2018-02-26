import sys

t=int(input())
if(t>100):
    sys.exit()
for z in range(t):
    n=int(input())
    if(n<=100000):
        check=[]
        for _ in range(n):
            l,r=map(int,raw_input().strip().split(' '))
            check.append([l,r])
        checklength=len(check)
        q=int(input())
        if(q<=n and q<=100000):
            for _ in range(q):
                qrange=[]
                insert=map(int,raw_input().strip().split(' '))
                insert.remove(insert[0])
                lengthinsert=len(insert)
                odd=0
                for k in range(0,checklength):
                    count=0
                    for i in range(0,lengthinsert):
                        if((insert[i]>=check[k][0]) and(insert[i]<=check[k][1])):
                            count+=1
                    if(count%2!=0):
                        odd+=1
                print(odd)