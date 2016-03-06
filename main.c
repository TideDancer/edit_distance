#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAP 1 		//add a apace in one string (equal to delete a character in the other) contributes 1 distance
#define MISMATCH 1 	//convert a character in s1 to corresponding one in s2 contribute 1 distance
#define MATCH 0

// get min of two arguments
int min(int a, int b)
{ return a<b?a:b; }

int main(int argc, char* argv[]) // $./edit string1 string2 to run the program to compute edit distance
{
  char *s1, *s2, *output_s, *p; // s1 and s2 are from input, output_s and p is used for output
  int **M;  					// M is dynamic programming table
  int len_s1,len_s2;
  int case1, case2, case3 = 0; 	// some temp var
  int i,j=0;
 
  // read string1 and string2
  if(argc != 3)
  	printf("Please Input 2 Sequences");
  else{
  	s1 = argv[1];
  	s2 = argv[2];
  }

  // get length of two strings
  len_s1 = strlen(s1);
  len_s2 = strlen(s2);	

  // assign memory to the dynamic programming table size of len_s1 * len_s2
  M = (int**) malloc((len_s1+1)*sizeof(int*));
  for(int i=0; i<=len_s1; i++)
    M[i] = (int*) malloc((len_s2+1)*sizeof(int));

  // init first column and first row of dynamic programming table
  M[0][0] = 0;
  for(int i=1; i<=len_s1; i++)
    M[i][0] = M[i-1][0] + GAP;
  for(int i=1; i<=len_s2; i++)
    M[0][i] = M[0][i-1] + GAP;

  // build dynamic table using rule: M{i,j] = min(M[i-1,j-1]+{mis or match}, M[i-1,j]+gap, M[j-1,i]+gap)
  for(int i=1; i<=len_s1; i++)
	  for(int j=1; j<=len_s2; j++)
	  {
		case1 = M[i-1][j] + GAP;
		case2 = M[i][j-1] + GAP;
		if(s1[i-1] == s2[j-1])
			case3 = M[i-1][j-1] + MATCH;
		else
			case3 = M[i-1][j-1] + MISMATCH;
                
		case1 = min(case1, case2);
		case1 = min(case1, case3);
		M[i][j] = case1;
	  }
  
  // M[len_s1,len_s2] store the value of edit distance
  printf("The edit distance is %d \n",M[len_s1][len_s2]);

  // prepare the output buffer
  i = len_s1;
  j = len_s2;
  output_s = (char*) malloc((len_s1+len_s2+1)*sizeof(char));
  p = output_s;
  
  // trace back from low-right end of the table, find the route back to M[0,0]
  // the route corresponds to each edit on the strings (add_space/convert/match)
  while(i>0 || j>0) 
  {
    case1 = min(M[i-1][j], M[i][j-1]);
	case1 = min(case1, M[i-1][j-1]);
	if(case1 == M[i-1][j-1])
	{
	    if(M[i-1][j-1] == M[i][j])
		{ *p = '|'; p++; } 	// '|' means a match between s1 and s2, such that no editing needed
		else
		{ *p = '*'; p++; }  // '*' means need to convert symbol of one string to corresponding one in the other string
		i--;
		j--;
	}
    else if(case1 == M[i-1][j])
	{
        *p = '2'; p++;      // '2' means add a gap at current position in string 2
		i--;
    }
    else //case1 == M[i][j-1]
	{
        *p = '1'; p++;      // '1' means add a gap at current position in string 1
		j--;
    }
  }
  while(i>0)
  { *p = '1'; p++; i--; }
  while(j>0)
  { *p = '2'; p++; j--; }

  // print out the editing
  while(p > output_s)
  {
    printf("%c",*p);
	p--;
  }
  printf("%c\n",*p);

}
