#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
//#include <sys/ioctl.h>

//#include <linux/gpio.h>
//FILE *fp;
/*int main(int argc, char**argv){
	char path[4];
	char Grp;
	int Num, i;
	int input = 152;

	path = transform(input);
	for(i=0;i<4;i++)
	printf("%c", path[i]);
	
	
}

char * transform(int pinNum){*/
int main(int argc, char**argv){
	int input, i, tmp;
	char name[4];

	for(i=0;i<4;i++) name[i] = 0x0;//NULL

	//input = argc;//pinNum
	input = 153;
	tmp = input % 32;

	name[0] = (input/32) + 'A';

	if(tmp /10) {
		name[1] = (tmp / 10) + '0';
		name[2] = (tmp % 10) + '0';
	}
	else{
		name[1] = (tmp % 10) + '0';
		}
	for(i=0;i<4;i++)
	printf("%c", name[i]);

	return 1;
	//return name;
}
