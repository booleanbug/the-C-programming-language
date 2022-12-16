#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLINE 10000


// code for taking string input
void getinput(char* s,int limit){
	
	printf("ENTER THE DECIMAL EXPRESSION IN C => ");
	int i,c;
	for( i = 0 ; i < limit - 1 &&  ( c = getchar()) != EOF && c != '\n' ; ++i){
		s[i] = c;
	}

	if( c == '\n'){
		s[i++] = c;
	}

	s[i] = '\0';

}


int power(int base,int exp){
	int power;
	power = 1;
	while(exp-- > 0){
		power = power *base;
	}
	return power;
}

// function for converting float string to float variable
double extended_atof(char* s){
	
	double val,pow;	//val keeps record of final double value
			//pow keeps record of final power of 10 by which are going to divide our final ans
	int sign,i,esign,exp ;	//sign states whether the double value is going to be negative or positibe
				//i is pointer to the character array
				//esign states whether the 
				//
 
	for( i = 0 ;  isspace(s[i]) ; i++) // while traversing skip blank spaces
	
	sign = ( s[i] == '-') ? -1 : 1; // get the sign of given input 

	if( s[i] == '+' || s[i] == '-'){ // after getting the sign skip + & - 
		i++;
	}

	for( val = 0.0 ; isdigit(s[i]) ; i++){ // update the double variable as you encounter digits
		val = 10.0*val + (s[i] - '0');
	}

	if( s[i] == '.' ){ // if you get . skip it
		i++;
	}

	for( pow = 1.0 ; isdigit(s[i]) ; i++) // update power so that your can divide the final ans at last
	{
		val = 10.0 * val + (s[i] - '0');
		pow *= 10.0;
	}

	if(s[i] == 'e' || s[i] == 'E'){ // skip if you get e or E in string
		i++;
	}

	if(s[i] == '+' || s[i] == '-') // get the sign of e or E power (are we going to multiply or are we going 
	{
		esign = s[i];
		i++;
	}

	for(exp = 0 ; isdigit(s[i]) ; i++){
		exp = 10.0*exp + (s[i] - '0');
	}

	if( esign == '-')
		return sign*(val/pow)/power(10,exp);
	else
		return sign*(val/pow)/power(10,exp);

}

int main(){
	char input[MAXLINE]; // string input
	double result;	// storing final result
	getinput(input,MAXLINE);	//get the input from user
	printf("\nDECIMAL EXPRESSION IS => %s\n",input); // display the string input
	result = extended_atof(input); // get the double result
	printf("\nACTUAL DECIMAL VALUE IS => %lf\n",result);	// display the double result
	return 0;
}

