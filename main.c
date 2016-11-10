#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *SrcFp, *TgtFp, *ConFp;
	
	char line[100];
	char ConWds[100];
	char Ent[2];
	
	int i, x, index, size, lastsize;
	long int loc;
	/*initial character */
	for(i=0;i<100;i++) {
		line[i] = NULL;
		ConWds[i] = NULL;
	}
	lastsize = 0;
	//Ent[0] = 0x0d;
	Ent[0] = 0x0a;
	
	//printf("This is DEV C++ application.\n");
	SrcFp = fopen("cut.txt", "r+");
	
	if(SrcFp==NULL) printf("open file failed.\n");
	else printf("open Src file\n");
	
	ConFp = fopen("tgt.txt", "r");
	if(ConFp == NULL) printf("open Content file failed \n");
	else printf("open content file\n");
	
	TgtFp = fopen("target.txt", "w");
	
	/*if(fgets(line, 90, SrcFp)){
		i = 0;
		do{
			printf("%c", line[i]);
		}while(line[i++]);
	}
	else{
		printf("meet source file end\n");
	}*/
	for(index=0;index<3;index++){
	
		if(fgets(line, 90, SrcFp)){
			i =0;
		
			while(line[i] != '=') {
				i++;
		//	printf("i is %d", i);
			}	
		
		//	printf("index is %d\n", i);
		}else printf("Source file open to empty.\n");
	
	//loc = ftell(SrcFp);
	
	
#if 1	
		if(fgets(ConWds, 80, ConFp)){
		/*x = 0;
		do{
			printf("%c", TgtWds[x]);}
		while(TgtWds[x++]);
			
		i++;
		
		while(TgtWds[x]){
			line[i++] = TgtWds[x++];
			printf("i is %d\n", i);
		}*/
			//x=0; size=0;
			//while(ConWds[x++] != 0x0d) size++;
			size = ftell(ConFp);
			printf("Content line size is %d\n", size);
			i++;
			strncpy(&line[i], ConWds, (size-lastsize));//need get content size
		
			lastsize = size;
		
		//printf("content index end is %d, total line length is %d\n", x, i);
		
		/*show result line*/
			i = 0;
			do{
				printf("%c", line[i]);
			}while(line[i++]);
		
		}else printf("Target file is empty\n");
	
	/*fseek(SrcFp, loc, SEEK_SET);
	//fputs(line, SrcFp);
	fwrite(line, 1, 15, SrcFp);*/
	
		fwrite(line, 1, i-1, TgtFp);
		//1 add "enter"; 2 size
		//fwrite(Ent, 1, 1, TgtFp);
	
}
#endif	
	fclose(TgtFp);
	fclose(SrcFp);
	fclose(TgtFp);
	return 0;
}
