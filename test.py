import re, sys

datafile = file("..\\Scripts\\Action.c")
line1 = datafile.readline()
line2 = datafile.readline()

serverString = "r'\tweb_url\(\"SASVisualAnalytics\w+\", \n\t\t\"URL=http://(.*)/'"

checkNext = False
nextMatch = None
lineCount = 0
while len(line2) != 0:
	lineCount += 1
	line = line1
	line1 = line2
	line2 = datafile.readline()
	string = line + line1 + line2

	match = re.search(serverString, string)
	#print match
	if match and (serverTimeout < 1):
		serverTimeout = 3
		print match.group() + str(lineCount)
		print "Server:\t" + match.group(1)
datafile.close
print 
