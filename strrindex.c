#include<stdio.h>
#include<stdlib.h>
# define MAXLINE 1000

int gettline(char* s,int lim)
{
	int c,i;

	i = 0;

	while(--lim > 0 && ( c = getchar()) != EOF && c != '\n'){
		s[i++] = c;
	}

	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	
	return i;
}

char pattern[] = "od";

int strindex(char* s,char* t){
	int i,j,k;
	int flag = -1;
	for( i = 0 ; s[i] != '\0' ; i++){
		for( j = i , k = 0 ; t[k] != '\0' && s[j] == t[k];j++,k++)
			;
		if(k > 0 && t[k] == '\0')
			flag = i;
	}
	
	return flag;
}


int main(){

	char line[MAXLINE];
	int found = 0;

	while(gettline(line,MAXLINE) > 0){
		printf("%d\n",strindex(line,pattern));
	}
	

	return 0;
}
