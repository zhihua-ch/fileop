#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *SrcFp;
	FILE *TgtFp;
	char line[100];
	char TgtWds[100];
	
	int i, x;
	long int loc;
	/*initial character */
	for(i=0;i<100;i++) {
		line[i] = NULL;
		TgtWds[i] = NULL;
	}
	
	//printf("This is DEV C++ application.\n");
	SrcFp = fopen("cut.txt", "r+");
	
	if(SrcFp==NULL) printf("open file failed.\n");
	else printf("open Src file\n");
	
	TgtFp = fopen("tgt.txt", "r");
	if(TgtFp == NULL) printf("open Target file failed \n");
	else printf("open content file\n");
	/*if(fgets(line, 90, SrcFp)){
		i = 0;
		do{
			printf("%c", line[i]);
		}while(line[i++]);
	}
	else{
		printf("meet source file end\n");
	}*/
	if(fgets(line, 90, SrcFp)){
		i =0;
		
		while(line[i] != '=') {
			i++;
		//	printf("i is %d", i);
		}
		
		printf("index is %d\n", i);
	}else printf("Source file open to empty.\n");
	
	loc = ftell(SrcFp);
	
	if(fgets(TgtWds, 10, TgtFp)){
		/*x = 0;
		do{
			printf("%c", TgtWds[x]);}
		while(TgtWds[x++]);
			
		i++;
		
		while(TgtWds[x]){
			line[i++] = TgtWds[x++];
			printf("i is %d\n", i);
		}*/
		i++;
		strncpy(&line[i], TgtWds, 4);
		
		
		//printf("content index end is %d, total line length is %d\n", x, i);
		
		/*show result line*/
		i = 0;
		do{
			printf("%c", line[i]);
		}while(line[i++]);
		
	}else printf("Target file is empty\n");
	
	fseek(SrcFp, loc, SEEK_SET);
	//fputs(line, SrcFp);
	fwrite(line, 1, 15, SrcFp);
	
	fclose(SrcFp);
	fclose(TgtFp);
	return 0;
}
