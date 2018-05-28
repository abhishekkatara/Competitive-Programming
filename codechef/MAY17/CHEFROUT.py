for t in xrange(int(raw_input())):
	 
	s = str(raw_input())
	chck =1
	strt = s[0]
	 
	for i in xrange(1,len(s)):
		nxt = s[i]
		 
		if strt == 'C':
			strt=nxt
			continue
			 
		elif strt == 'E':
			if nxt=='C':
				chck=0
				break
				 
			elif strt=='S':
				if nxt!='S':
					chck=0
					break
					 
					strt = nxt
					 
					if chck==1:
						print 'yes'
						 
					else:
						print 'no'