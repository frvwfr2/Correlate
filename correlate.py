import correlateTools, sys, os, shutil

def fullCorrelate():
	fileOrder = []
	if len(sys.argv) == 1:
		print "Usage: python correlate.py <inputfile> <outputfile>"
		sys.exit()
	inputLocation = sys.argv[1] + "\\"
	backupLocation = inputLocation + "\\backups\\"
	if len(sys.argv) > 2: outputLocation = sys.argv[2]
	else: outputLocation = sys.argv[1] + "\\output\\"
	if not os.path.exists(outputLocation):		#Checks for output folder
		os.makedirs(outputLocation)			#Creates folder
	if not os.path.exists(backupLocation):	#Checks for backup folder at input\backups
		os.makedirs(backupLocation)			#Creates folder

	userFileName = inputLocation + sys.argv[1].split('\\')[-1] + ".usr"
	#print "UserFile name: " + userFileName
	try:
		userFile = open(userFileName)
	except:
		print "Directory name must match .usr file name: " + sys.argv[1]
		sys.exit()
	print backupLocation + sys.argv[1].split('\\')[-1] + ".usr"
	if not os.path.exists(backupLocation + sys.argv[1].split('\\')[-1] + ".usr"):
		shutil.copy(userFileName, backupLocation + sys.argv[1].split('\\')[-1] + ".usr")
	actions = False
	for line in userFile:		#Searches the userFile for the order of .c files
		#print line
		if ("[" in line) or ("]" in line):
			actions = False
		if actions == True:
			#print line
			orderedFileName = line.split('=')[1]
			orderedFileName = orderedFileName.split('\n')[0]
			#print orderedFileName
			fileOrder.append(orderedFileName)
		if "[Actions]" in line:
			actions = True

	for files in fileOrder:
		if os.path.exists(inputLocation + files):					#If input file exists
			if not os.path.exists(backupLocation + files):			#And backup file does not
				shutil.copy(inputLocation + files, backupLocation)	#Copy it to the backups folder

	#print fileOrder
	for files in fileOrder:		#Runs the methods on each .c file
		#print "check 1: " + inputLocation + files
		if os.path.exists(inputLocation + files):
			correlateTools.infile = inputLocation + files	#Sets input file 
			correlateTools.outfile = outputLocation + files	#Sets output file
			correlateTools.findValues()
			correlateTools.write_file()
		else: 
			print "FNF: " + inputLocation + files + " ...Skipping"
	correlateTools.dataWriter(outputLocation + "data.txt")
	print "Complete"


def findEightxEights():	#Finds all values of 8.8/___ format in all files of .c type in folder
	try:
		inputfolder = str(sys.argv[1])	#First arg; input file
	except:
		print "Usage: python correlate.py <inputfile>; defaulted to \".\""
		inputfolder = "."
		pass
	for files in os.listdir(inputfolder):		#The command argument determines what folder we are searching in
		if files.endswith(".c"):
			correlateTools.infile = str(sys.argv[1]) + "\\" + files		#Sets the file we are searching
			print "8.8s found in: " + files
			print correlateTools.findValues();
			print "\n"
			del correlateTools.value[:]		#Clears records from correlateTools.py
			del correlateTools.substitution[:]
			del correlateTools.name[:]

fullCorrelate();

#findEightxEights();
