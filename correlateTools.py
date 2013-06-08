import fileinput, re, glob, os

infile = 'C:\\Users\\andrew\\Desktop\\Logon.c'
outfile = 'C:\\Users\\andrew\\Desktop\\TestFile.c'

foundCount = 0
permType = []
permValue = []
permSubstitution = []		#Array of what is subbed in
permBlankLine = []
permOriginalLine = []
permName = []
permSurroundingLines = []	#Array of the line above and below the value
permInFile = []

type  = []
value = []				#Array storing values to be substituted
substitution = []		#Array of what is subbed in
blankLine = []
originalLine = []
name = []
surroundingLines = []	#Array of the line above and below the value
inFile = []

server = ""
serverReplace = True
userReplace = True
replaceAll = -1

def getPrevBlank(infile, lineNumber):	#Locates the first blank line above the input
	blankLine = -1
	fp = open(infile)
	for i, line in enumerate(fp):
		if i >= lineNumber:	#Checks for us passing the valid line
			break
		if line == '\n':
			blankLine = i	#Only updates value if we are on a valid line
	fp.close
	return blankLine

def getCurrentAMFCall(infile, lineNumber):		#Returns the line where the current AMF call starts
	callLine = -1
	fp = open(infile)
	for i, line in enumerate(fp):
		if i >= lineNumber:	#Checks for us passing the valid line, if so breaks
			break
		match = re.search( r'\tflex_amf_call\("AMF3_call_(\w+)",', line)
		if match:
			callLine = i	#Only updates value if we are on a valid line AND match found
			callNumber = match.group(1)
	fp.close
	if callLine == -1:
		print "Error: Current AMF call not found for line " + lineNumber + " in file " + infile
		callNumber = -1
	return callLine, callNumber					#Returns callLine and callNumber

def getPrevAMFCall(infile, prevCallNumber):		#Returns the line where the previous AMF call starts
	callLine = -1			#Sets to invalid line number
	prevCallNumber = int(prevCallNumber)-1		#Sets callNumber to the value we are looking for
	fp = open(infile)
	if prevCallNumber == 0:
		searchString = "flex_amf_call(\"AMF3_call\","
	else:
		searchString = "flex_amf_call(\"AMF3_call_" + str(prevCallNumber) + "\","
	#print searchString
	for i, line in enumerate(fp):
		if searchString in line:
			#print "Match on line " + str(i)
			callLine = i+1	#Sets equal to the line the call starts on
			return callLine
	fp.close
	if callLine == -1:
		print "Error: Previous AMF call (call" + str(prevCallNumber) + ") not found in file " + infile
	return callLine

def findValues():
	DSIDtimeout = 0
	ExEtimeout = 0
	GUIDtimeout = 0
	global name, server, serverReplace, userReplace
	lineNum = 1
	datafile = file(infile)
	line1 = datafile.readline()
	#print line1.strip()
	line2 = datafile.readline()
	#print line2.strip()
	while True:
		tempValue = []
		for val in value:
			tempValue.append(val)
		for val in permValue:
			tempValue.append(val)
		dupeFlag = False
		line = line1
		line1 = line2
		line2 = datafile.readline()
		#print line2.strip()
		string = line + line1 + line2
		if not line2: break
		lineNum += 1
		serverMatch = re.search( r'\tweb_url\("SASVisualAnalytics\w+", \n\t\t"URL=http://(.*)/', string)
		DSIDmatch = re.search( r'DSId["\n\t]*</string>["\n\t]*<string>["\n\t]*(?!d>)([A-Z0-9]{8}-[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{12})["\n\t]*(?!</m)+(?!</c)+</string>["\n\t]*', string)
		ExEmatch = re.search( r'([A-Z0-9]{8}\.[A-Z0-9]{8})/(\w+)', string) #searches for 8.8/__
		GUIDmatch = re.search( r'[Gg]uid[/<>"\n\t]*string[/<>"\n\t]*string[/<>"\n\t]*([a-z0-9]{8}-[a-z0-9]{4}-[a-z0-9]{4}-[a-z0-9]{4}-[a-z0-9]{12})[/<>"\n\t]*string', string) #checks for GUID
		if GUIDmatch and (GUIDtimeout < 1):
			GUIDtimout = 3
			for val in tempValue:
				#print val + " versus " + GUIDmatch.group(1)
				if val == GUIDmatch.group(1):
					dupeFlag = True
			if dupeFlag == False:
				print "Added GUID to tables: " + GUIDmatch.group(1).ljust(40) + str(lineNum)
				type.append("GUID")
				name.append("GUID")
				match = GUIDmatch.group(1)
				otherInfo(name, lineNum, match, line.strip() + "\n" + line1.strip() + "\n" + line2.strip())		
		elif DSIDmatch and (DSIDtimeout < 1):
			#print "DSID Match found! " + DSIDmatch.group(1)
			DSIDtimeout = 3
			for val in tempValue:
				if val == DSIDmatch.group(1):
					dupeFlag = True
					#print "Dupe found"
			if dupeFlag == False:
				print "Added DSID to tables: " + DSIDmatch.group(1).ljust(40) + str(lineNum)
				type.append("DSID")
				name.append("DSID")
				match = DSIDmatch.group(1)
				otherInfo(name, lineNum, match, line.strip() + "\n" + line1.strip() + "\n" + line2.strip())

		elif (ExEmatch and (ExEtimeout < 1)):
			#print "ExE Match found! " + ExEmatch.group()
			ExEtimeout = 3
			for val in tempValue:
				if val == ExEmatch.group(1):
					dupeFlag = True
			if dupeFlag == False:
				print "Added ExE  to tables: " + ExEmatch.group(1).ljust(40) + str(lineNum)
				type.append("ExE")
				name.append(ExEmatch.group(2))
				match = ExEmatch.group(1)
				otherInfo(name, lineNum, match, line.strip() + "\n" + line1.strip() + "\n" + line2.strip())
		elif (serverMatch and server == ""):	#If server matches AND server has not already been found
			server = serverMatch.group(1)
			serverReplace = int(raw_input("Do you want to replace the server name (" + server + ") with {Server}?\n1 for yes\n0 for no: ")) 
	return "Values:\t" + str(value) + "\nSubstitutions: " + str(substitution) + "\nName:\t" + str(name)

def otherInfo(name, lineNum, match, string):
	global originalLine, value, substitution, inFile, foundCount
	#print "Info added with name " + name[len(name)-1]
	inFile.append(infile)
	surroundingLines.append(string)
	foundCount += 1
	substitution.append("{" + name[len(name)-1] + "_" + str(foundCount) + "}")
	value.append(match)			#Stores the string
	originalLine.append(lineNum)		#Stores the line it is on
	#print "MATCH: " + match
	if len(originalLine) > 0:	#Locating line to insert "getter"
		line, callNumber = getCurrentAMFCall(infile, originalLine[-1])
		callLine = getPrevAMFCall(infile, callNumber)
		blankLine.append(callLine-1)	#Stores the line BEFORE the previous AMF call as the blank to insert into
		#print "Blank: " + str(blankLine) + " Original: " + str(originalLine[-1]) + " Infile: " + inFile[-1] 

def getWriter(file):	#Writes the "get" statements for the values, always goes off of [0] value in lists
	global replaceAll
	if replaceAll == -1:
		replaceAll = int(raw_input("Do you want to auto-replace all recommended values?\n1 for yes\n0 for no: "))
	paramName = substitution[0][1:len(substitution[0])-1]	#skips the opening { and closing }
	recommendedL = " "
	if type[0] == "DSID":									#If type is DSID
		recommendedL = "<string>DSId</string><string>"		#Recommend this for lBound
		recommendedR = "</string>"							#this for rBound
	elif type[0] == "ExE":									#If type is ExE...
		recommendedL = "<string>"
		recommendedR = "/" + name[0] + "</string>"
	elif type[0] == "GUID":									#If type is GUID...
		recommendedL = "uid</string><string>"
		recommendedR = "</string><string>id"
	print "----------------------------Leading text--------------------------------\n" + surroundingLines[0].strip() + "\n------------------------------------------------------------------------\nName:\t" + name[0] + "\tValue:\t" + value[0] + "\nFile:\t" + inFile[0] + "\nOrigLine:\t" + str(originalLine[0]) + "\tGetLine:\t" + str(blankLine[0]) + "\n"
	if replaceAll == True and recommendedL != " ":		#If user chose to replace all AND a match was found, write then return
		leftBound = recommendedL
		rightBound = recommendedR
		string = "\tweb_reg_save_param_ex(\"ParamName=" + paramName + "\",\"LB=" + leftBound + "\",\"RB=" + rightBound + "\",\"Ordinal=1\",SEARCH_FILTERS,\"Scope=Body\",\"IgnoreRedirections=Yes\",\"RequestUrl=*/sasamf*\",LAST);"	#Builds entire string to catch input
		file.write("\n" + string + "\n")
		return
	if (recommendedL != " "):								#If a type was matched and recommended values have changed
		print "Recommended Left Bound: \t" + recommendedL + "\nRecommended Right Bound:\t" + recommendedR		#Prints out the recommended bounds
		leftBound = raw_input("1: recommended\n2: skip\nor enter Left bound: ")	#Get input
		if leftBound == "1":								#If 1, use rec values
			leftBound  = recommendedL						#Set bounds to use values
			rightBound = recommendedR
		elif leftBound == "2": return						#If 2, return (skip)
		else: rightBound = raw_input("Right bound: ")		#If neither, ask for rBound
	elif (recommendedL == " "):								#If a type was NOT matched and rec values haven't changed
		leftBound = raw_input("1 to skip, or enter Left bound: ")	#Ask user for leftBound
		if leftBound == "1": return									#If they enter 1, return (skip)
		rightBound = raw_input("Right bound: ")						#Else, ask for rightBound
	print "Chosen Left bound: \t" + leftBound				#Print values that were chosen
	print "Chosen Right bound:\t" + rightBound + "\n"

	string = "\tweb_reg_save_param_ex(\"ParamName=" + paramName + "\",\"LB=" + leftBound + "\",\"RB=" + rightBound + "\",\"Ordinal=1\",SEARCH_FILTERS,\"Scope=Body\",\"IgnoreRedirections=Yes\",\"RequestUrl=*/sasamf*\",LAST);"	#Builds entire string to catch input
#	print string
	file.write("\n" + string + "\n")

def write_file():			#Writes to the output file
	global foundCount, originalLine, blankLine, value, name, substitution, surroundingLines, permValue, permSubstitution, permBlankLine, permOriginalLine, permName, permSurroundingLines, permInFile
	count = 0
	for entry in value:	
		permValue.append(value[count])
		permSubstitution.append(substitution[count])
		permBlankLine.append(blankLine[count])
		permOriginalLine.append(originalLine[count])
		permName.append(name[count])
		permType.append(type[count])
		permSurroundingLines.append(surroundingLines[count])
		permInFile.append(inFile[count])
		count += 1
	newFile = open(outfile, "w")
	with open(infile) as f:
		for i, line in enumerate(f,1):	#i is NOT ACCURATE for what line we are on; getWriter "should" increase it by 3 each time, as it writes out 3 lines that this does not catch
			valCount = -1
			if serverReplace:
				if server in line:
					line = line.replace(server, "{Server}")
			for val in permValue:
				valCount += 1
				if val in line:
					#print "Replacing in " + line
					line = line.replace(val, permSubstitution[valCount])
					#print "Replacing " + val + " with " + permSubstitution[valCount]
			while (len(blankLine) > 0) and (i == blankLine[0]):
				getWriter(newFile)
				blankLine.pop(0)
				originalLine.pop(0)
				value.pop(0)
				type.pop(0)
				name.pop(0)
				substitution.pop(0)
				surroundingLines.pop(0)
				tempBlankLine = []
				#for blank in blankLine: tempBlankLine.append(blank - 3)	#This is to increase the count along with the values we are printing
				#blankLine = tempBlankLine
			if "web_add_cookie(" in line:
				line = "//" + line
			newFile.write(line)


def dataWriter(file):	
	count = 0
	dataOut = open(file, "w")
	for val in permValue:		#Writes out all stored values
		dataOut.write("------------------------------------------------------------------------------------------------------------------------------------------------\n" + str(val) + "\t" + str(permSubstitution[count]) + "\t" + str(permBlankLine[count]) + "\t" + str(permOriginalLine[count]) + "\t" + str(permName[count]) +  "\t" + str(permInFile[count]) + "\n\n" + permSurroundingLines[count] + "\n------------------------------------------------------------------------------------------------------------------------------------------------\n\n")
		count += 1

	if serverReplace == True:
		dataOut.write("\n" + server + " replaced with {Server}")
	dataOut.close





