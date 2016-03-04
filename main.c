#include <stdio.h>

int main(int argc, char* argv[]) {

  char* s1, s2;
	int** M;
	int len_s1,len_s2;

	if(argc != 3)
		printf("Please Input 2 Sequences");
	else{
		s1 = argv[1];
		s2 = argv[2];
	}

  len_s1 = strlen(s1);
  len_s2 = strlen(s2);	

	M = (int**) malloc(len_s1*sizeof(int*))
	for(int i=0; i<len_s1; i++)
	  M[i] = (int*) malloc(len_s2*sizeof(int));

  for(int i=0; i<len_s1; i++)
	  for(int j=0; j<len_s2; j++)
		{
			
		}

}
