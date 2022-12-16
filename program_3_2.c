#include<stdio.h>
#define MAXLEN 1000 //here the max length of character array is 1000
		    

void get_line(char* arr,int max_size){
	int i,c;
	for(i = 0 ; i < max_size - 1 && (c = getchar()) != EOF && c != '\n' ; ++i){
		arr[i] = c;
	}

	if(c == '\n'){
		arr[i++] = c;
	}

	arr[i] = '\0';

	return;
}

// function for converting source string to destination string
void escape(char* dest,char* src){
	
	int i,j; //intitialize the pointers to source string and destination string
	
	// iterate the source string and update destination string according to the current character of source str	   
	 for(i = j = 0; src[i] != '\0' ; ++i, ++j){
	 	switch (src[i])
		{
			case '\a':
				dest[j++] = '\\';
				dest[j] = 'a';
				break;

			case '\b':
				dest[j++] = '\\';
				dest[j] = 'b';
				break;

                        case '\f':
				dest[j++] = '\\';
				dest[j] = 'f';
				break;

			case '\n':
				dest[j++] = '\\';
				dest[j] = 'n';
				break;
	                case '\r':
				dest[j++] = '\\';
				dest[j] = 'r';
				break;

			case '\t':
				dest[j++] = '\\';
				dest[j] = 't';
				break;
			case '\v':
				dest[j++] = '\\';
				dest[j] = 'v';
				break;

			case '\\':
				dest[j++] = '\\';
				dest[j] = '\\';
				break;

                        case '\?':
				dest[j++] = '\\';
				dest[j] = '?';
				break;

			case '\'':
				dest[j++] = '\\';
				dest[j] = '\'';
				break;
	                case '\"':
				dest[j++] = '\\';
				dest[j] = '"';
				break;

			default:
				dest[j] = src[i];
				break;


		}	
	 }

	 if(src[i] == '\0'){
			 dest[i] = src[i];
		 }

}


int main(){

	printf("\nPROGRAM FOR DISPLAYING TAB,SPACE,NEWLINE CHARACTERS\n");
	
	char src[MAXLEN];	// initialize and declare the characters arrays
	char dest[MAXLEN];	// src is given input and dest is our new made string with computations
	
	// get the input line from user
	get_line(src,MAXLEN);
	printf("INPUT FROM USER => %s\n",src);
	
	// convert the tabs and other space characters to there particular alphabets
	escape(dest,src);
	printf("CONVERTED STRING => %s\n",dest);
	
	return 0;
}
