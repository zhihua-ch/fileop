#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *SrcFp;
	FILE *TgtFp;
	char line[100] ;
	int i ;
	/*initial character */
	for(i=0;i<100;i++) line[i] = NULL;
	
	//printf("This is DEV C++ application.\n");
	SrcFp = fopen("cut.txt", "r");
	
	if(SrcFp==NULL) printf("open file failed.\n");
	
	if(fgets(line, 90, SrcFp)){
		do{
			printf("%c", line[i]);
		}while(line[i++]);
	}
	else{
		printf("meet source file end\n");
	}
	
	fclose(SrcFp);
	return 0;
}
