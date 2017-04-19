from datetime import datetime,timedelta
class Solution(object):
	def findMinDifference(self, timePoints):
		"""
		:type timePoints: List[str]
		:rtype: int
		"""
		res = 1440.0
		d = sorted([datetime.strptime(s,'%H:%M') for s in timePoints])
		bound = (min(d) + timedelta(days=1) - max(d)).total_seconds()/60
		for i in range(1, len(d)):
			if (d[i] - d[i-1]).total_seconds()/60 < res:
				res = (d[i] - d[i-1]).total_seconds()/60

		return int(res) if res < bound else int(bound)

timePoints = ['22:05','11:47','23:59','21:34','22:16','11:43','00:00']
print Solution().findMinDifference(timePoints)