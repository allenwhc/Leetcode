class Codec:
	def __init__(self):
		self.d = {}
		self.flag = False

	def encode(self, longUrl):
		"""Encodes a URL to a shortened URL.
		
		:type longUrl: str
		:rtype: str
		"""
		if longUrl and longUrl[-1] == '/': self.flag = True
		parse,shortUrl = filter(None,longUrl.split('/')),''
		self.d['http:'] = parse[0]
		shortUrl += 'http:' + '//'
		if len(parse) > 2:
			self.d['tinyurl.com'] = filter(None, parse[1:len(parse)-1])
			shortUrl += 'tinyurl.com' + '/'
		self.d['4e9iAk'] = parse[-1]
		shortUrl += '4e9iAk'
		return shortUrl
 
	def decode(self, shortUrl):
		"""Decodes a shortened URL to its original URL.
		
		:type shortUrl: str
		:rtype: str
		"""
		parse = filter(None, shortUrl.split('/'))
		return self.d[parse[0]] + '//' + ('/'.join(self.d[parse[1]]) + '/' if len(parse)>2 else '') + self.d[parse[-1]] + ('/' if self.flag else '')

url = "https://leetcode.com/problems/design-tinyurl"
cc = Codec()
print cc.decode(cc.encode(url))