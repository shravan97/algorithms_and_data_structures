

while 1:
	l = raw_input('')
	l = int(l)
	if l==0:
		break

	ig =[]
	i =0

	while l>0:
		ig[i]=raw_input('')
		i=i+1
		l=l-1
	flag=1

	while flag:
		s = raw_input('')
		if s=='LAST CASE':
			break

		w = s.split(' ')
		abbr = w[0].lower()

		wnum=1
		wlen = len(w)

		# 1 : Store all prefixes in a dict , along with their frequencies
		# 2 : Match from first letter to length of word - no. words left 
		# 3 : Then match the next prefix of the word ... and so on 

		for k in range(1,wlen):
			if k>=wlen:
				break
			if w[k] in ig:
				w.pop(k)
				wlen--

		for k in range(1,wlen):
