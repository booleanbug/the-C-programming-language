#include<stdio.h>
#include<string.h>
# define MAXLEN 10000

// function for reverse the string
void reverse(char* s){
	
	int c,i,j;	//c is temporary container
			//i is forward pointer
			//j is backward pointer
	
	// iterate each and every character of string and perform swapping
	for( i = 0 , j = strlen(s) - 1 ; i < j ; i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	
	// return from this function
	return;

}

// function for taking string input
void get_str(char* string,int limit){

	int c,i = 0;
	while( i < limit - 1 && (c = getchar()) != '\n'){
	       string[i++] = c;
	}
	string[i] = '\0';
	return;	
}

// function for converting integer to character
void itoa(int n,char* s){
	
	int i,sign;

	//check the sign of given number
	if((sign = n ) < 0){
		 n = -1*n;// make it positive
	}

	// apply do while loop
	i = 0;
	do{
		s[i++] = n%10 + '0';
	}while((n/=10) > 0);

	//update the string according to sign
	if(sign < 0 ){
		s[i++] = '-';
	}
	s[i] = '\0';
	printf("NON REVERSE STRING => %s\n",s);
	reverse(s);
	printf("REVERSED STRING => %s\n",s);
	return;
}

int main(){

	// setup the initial string
	char str[MAXLEN];
	
	// get the input from user
	int n;
	scanf("%d",&n);
	printf("\nNUMBER ENTERED IS => %d",n);
	
	itoa(n,str);

	return 0;
}


