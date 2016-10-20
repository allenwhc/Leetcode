x = 6
def guess(num):
	global x 
	if num < x: 
		return 1
	elif num > x: 
		return -1
	else:
		return 0

class Solution(object):
	def guessNumber(self, n):
		s,e = 1, n
		while s<=e:
			mid = (e-s)/2+s
			if guess(mid) == 0: 
				return mid
			elif guess(mid) == 1: 
				s = mid+1
			else:
				e = mid
		return 0

if __name__ == '__main__':
	n = 10
	sol = Solution()
	print sol.guessNumber(n)