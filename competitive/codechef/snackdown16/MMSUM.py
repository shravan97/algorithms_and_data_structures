
t=raw_input()
t=(int)(t)

def chck_neg(l):
	flag=1
	for k in l:
		if k>0:
			flag=0
			break

	return flag		

def max_neg(l):
	max_neg_val=0
	for k in l:
		if k<0:
			if max_neg_val==0 or max_neg_val<k:
				max_neg_val=k
	return max_neg_val			

for i in range(0,t):
	n=raw_input()
	a=raw_input()
	a=a.split(' ')
	a=[(int)(k) for k in a]

	if chck_neg(a)==1:
		print max(a)
	else:
		max_so_far=0
		l_max_so_far=[]
		max_now=0

		for k in a:
			if 0>=(max_so_far+(int)(k)):
				del l_max_so_far[:]
				max_so_far=0
			else:
				l_max_so_far.append((int)(k))
				max_so_far=max_so_far+(int)(k)	
			max_now = max(max_now,max_so_far)

		print max_so_far-max_neg(l_max_so_far)