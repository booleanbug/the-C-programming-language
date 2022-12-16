#include<stdio.h>
#define MAXLINE 100
#include<string.h>


void reverse(char* s){
	int i,j,c;
	for( i = 0 , j = strlen(s) - 1 ; i < j ; i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


void itob(int n,char* s,int b){
	
	int i,sign;

	if((sign = n) < 0){
		n = -1*n;
	}

	i = 0;

	do
	{
		s[i++] = ( n%b <= 9 ) ? (n%b) + '0' : (n%b) + 'a'-10;
	}while( (n/=b) > 0);

	if(sign < 0){
		s[i++] = '-';
	}

	s[i] = '\0';

	reverse(s);

}

int main(){
	
	printf("\nPROAGRAM FOR PRINTING STRING IN BASE OF NUMBER n\n");

	int number,base;
	char str[MAXLINE];

	number = 42425;
	base = 16;

	itob(number,str,base);
	printf("\nCONVERTED TO PARTCULAR BASE =>  %s\n",str);

	return 0;
}
