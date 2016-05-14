t = raw_input()
t = int(t)

for i in range(0,t):
	n = raw_input()
	n=long(n)
	arr = raw_input()
	arr = list(arr.split(' '))
	arr = [long(k) for k in arr]
	ranks = [0 for k in range(0,n)]

	for j in range(0,n):
		ranks[j]=j+1

		for z in range(j-arr[j],j):
			if z>=0:
				if z-arr[z]>=j-arr[j]:
					ranks[z]+=1
					ranks[j]-=1

	print ' '.join([str(k) for k in ranks])