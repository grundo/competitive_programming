words = raw_input().split()
dud = raw_input()
mdict = raw_input().split()
done = False

for i in words:
	if i not in mdict:
		print "Misspell"
		done = True
	if done:
		break

if not done:
	print "Correct"
	

