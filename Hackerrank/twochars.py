import sys

def isPalindrome(s):
	rev = ''.join(reversed(s))
	if (s == rev):
		return True
	return False


def twoCharaters(s):
	ans = isPalindrome(s)
	temp = s
	if (ans):
		return len(s)

	else:
		for i in s:
			s = s.replace(i,"")
			print(s)
			if (isPalindrome(s)):
				print(s)
				return len(s)
			else:
				s = temp
				continue



if __name__ == "__main__":
    l = int(raw_input().strip())
    s = raw_input().strip()
    result = twoCharaters(s)
    print result
