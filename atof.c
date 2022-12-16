#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
# define MAXLEN 1000

void getValue(char* s,int limit){
	printf("Enter the double value in string => ");
	int i = 0,c;
	while(( c = getchar()) != EOF && i < limit ){
		s[i++] = c;
	}
	s[i++] = '\n';
	s[i++] = '\0';
	return;
}

double atof(char* s){

	double val,power;	//declare the double variables
	int i,sign;		//declare the integer variables

	for( i = 0 ; s[i] == ' ' ; i++)	//skip the white space

	sign = (s[i] == '-') ? -1 : 1; // get the sign of number
	
	if( s[i] == '+' || s[i] == '-'){ // if the string value is + or - then skip it
		i++;
	}

	for( val = 0.0 ; isDigit(s[i]) ; i++){
		val = 10.0*val + (s[i] - '0');      
	}

	if(s[i] == '.'){
		i++;
	}

	for( power = 1.0 ; isDigit(s[i]) ; i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
		

}

int main(){
	
	printf("\nPROGRAM FOR CONVERTING STRING TO DOUBLE\n");

	char input[MAXLEN];
	getValue(input,MAXLEN);	
	printf("\nDouble value entered is =>  %s",input);
	printf("\nActual double value entered is => ",atof(input));
	return 0;

}
