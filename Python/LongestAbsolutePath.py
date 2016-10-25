class Solution(object):
	def lengthLongestPath(self, input):
		max_len = 0
		path_len = {0:0}
		for line in input.splitlines():
			name = line.lstrip('\t')
			len_diff = len(line) - len(name)
			if '.' not in name:	#path reached a sub-directory
				path_len[len_diff + 1] = path_len[len_diff] + len(name) + 1	# +1 represents '/'s among file paths
			else:	#path reached an exact file
				max_len = max(max_len, path_len[len_diff]+len(name))
		return max_len


input = 'dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext'
print input
print Solution().lengthLongestPath(input)
