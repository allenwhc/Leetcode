class Solution(object):
	def findMedianTwoSortedArray(self, nums1, nums2):
		"""Test Case:
			 	nums1 = [1,2,4,7,8], nums2 = [3,4,5,9]
		 		After sort by length:
		 		nums1 = [3,4,5,9], nums2 = [1,2,4,7,8]
		 		m = 4, n = 5
		 		boundary = (m+n-1)/2 = 4
		 		l = 0, r = m = 4
				Iteratons:
				1. l = 0, r = 4, boundary = 4
					mid1 = (l+r)/2 = 2
					mid2 = boundary - mid1 - 1 = 1
					boundary - mid1 = 2 > 1, but nums1[mid1] = 5 >= nums2[mid2] = 2:
						hence, r = mid1 = 2, l = 0
				2. l = 0, r = 2, boundary = 4
					mid1 = (l+r)/2 = 1
					mid2 = boundary - mid1 - 1 = 2
					boundary - mid1 = 3 > 1, but nums1[mid1] = 4 >= nums2[mid2] = 4:
						hence, r = mid1 = 1, l = 0
				3. l = 0, r = 1, boundary = 4
					mid1 = (l+r)/2 = 0
					mid2 = boundary - mid1 - 1 = 3
					boundary - mid1 = 4 > 1, and nums1[mid1] = 3 < nums2[mid2] = 7:
						r = 1, l = mid1 + 1 = 1
				Now l = r, iterations are over

		"""
		nums1,nums2 = sorted((nums1,nums2), key=len) #Sort two arrays by length
		m,n = len(nums1),len(nums2)	# m = length of shorter array, n = length of longer array
		l,r = 0,m 	#Start positions of two array
		boundary = (m+n-1)/2	#Median of the virtual combined array
		while l < r:
			mid = (l + r) / 2	#Middle of left subarray
			if boundary - mid < 1 or nums1[mid] >= nums2[boundary-mid-1]:
				r = mid 	# If median of nums1 >= median of nums2, we need to traverse nums1[0...mid1] and nums2[mid2+1...n]
			else:
				l = mid + 1	# Else, we need to traverse nums1[mid1+1...m] and nums2[0...mid2]
		#print l,r,boundary
		pend = sorted(nums1[l:l+2] + nums2[boundary-l: boundary-l+2])
		return float(pend[0]) if (m+n)%2 else (pend[0]+pend[1])/2.0

nums1 = [1, 2]
nums2 = [3, 4]
print Solution().findMedianTwoSortedArray(nums1,nums2)