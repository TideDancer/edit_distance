#include <stdio.h>
#include <math.h>

#define GAP -2
#define MIS -3
#define MATCH 2

int main(int argc, char* argv[]) {

  char* s1, s2;
  int** M;
  int len_s1,len_s2;
  int case1, case2, case3 = 0;
  
  if(argc != 3)
  	printf("Please Input 2 Sequences");
  else{
  	s1 = argv[1];
  	s2 = argv[2];
  }

  len_s1 = strlen(s1);
  len_s2 = strlen(s2);	

	M = (int**) malloc((len_s1j+1)*sizeof(int*))
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
                
		case1 = max(case1, case2);
		case1 = max(case1, case3);
		M[i][j] = case1;
	  }

}
