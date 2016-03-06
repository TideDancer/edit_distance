compile:
$gcc main.c -o edit

run the program:
$./edit [string1] [string2]

output will be a sequence including '|', '*', '1' and '2'
	'|' means a match between s1 and s2, such that no editing needed
	'*' means need to convert symbol of one string to corresponding one in the other string
	'1' means add a gap at current position in string 1
	'2' means add a gap at current position in string 2

example:
$./edit ATGTGTC ACCGTGT
output:
	the edit distance is 3
	|1*||||2
	
	meaning that the final editing is as following:
	A-TGTGTC
	| *||||
	ACCGTGT-

