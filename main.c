#include <stdio.h>
#include <math.h>

#define GAP 1
#define MISMATCH 1
#define MATCH 0

int main(int argc, char* argv[]) {

  char* s1, s2, output_s, p;
  int** M;
  int len_s1,len_s2;
  int case1, case2, case3 = 0;
  int i,j=0;
  
  if(argc != 3)
  	printf("Please Input 2 Sequences");
  else{
  	s1 = argv[1];
  	s2 = argv[2];
  }

  len_s1 = strlen(s1);
  len_s2 = strlen(s2);	

  M = (int**) malloc((len_s1+1)*sizeof(int*))
  for(int i=0; i<=len_s1; i++)
    M[i] = (int*) malloc((len_s2+1)*sizeof(int));

  M[0][0] = 0;
  for(int i=1; i<=len_s1; i++)
    M[i][0] = M[i-1][0] + GAP;
  for(int i=1; i<=len_s2; i++)
    M[0][i] = M[0][i-1] + GAP;

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
  
  print("The edit distance is %d \n",M[len_s1][len_s2];

  i = len_s1;
  j = len_s2;
  output_s = (char*) malloc((len_s1+len_s2+1)*sizeof(char));
  p = output_s;

  while(i>0 || j>0) 
  {
    case1 = min(M[i-1][j], M[i,j-1]);
	case1 = min(case1, M[i-1][j-1]);
	switch(case1)
	{
	  case M[i-1][j-1]:
	    if(M[i-1][j-1] == M[i][j])
		{ *p = '|'; p++; }
		else
		{ *p = '*'; p++; }
		i--;
		j--;
		break;
      case M[i-1][j]:
        *p = "1";
		i--;
        break;
      case M[i][j-1]:
        *p = "2";
		j--;
        break;
      default:
        break;		
	}
  }
  while(i>0)
  { *p = "1"; i--; }
  while(j>0)
  { *p = "2"; j--; }

  while(p != output_s)
  {
    printf("%s",*p);
	p--;
  }
  pritnf("%s\n",*p);

}
