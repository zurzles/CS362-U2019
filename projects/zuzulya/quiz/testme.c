#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int ASCII_INDEX_START=32;
int ASCII_INDEX_END=126;

char inputChar()
{
    return (char) (rand()%(ASCII_INDEX_END-ASCII_INDEX_START+1)+ASCII_INDEX_START);
}

char *inputString()
{
    int length=10;
    char* str = malloc(length*sizeof(char));
    if((rand()%100)==0){
	str[0]='r';
	str[1]='e';
	str[2]='s';
	str[3]='e';
	str[4]='t';
	str[5]='\0';
    }else {
    	for(int i=0; i<length-1; i++){
		str[i]=(char)(rand()%(ASCII_INDEX_END-ASCII_INDEX_START+1)+ASCII_INDEX_START);
    	}
    	str[length-1]='\0';	
    }
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    free(s);
//  if(tcCount>10){
//	printf("10loops");
//	break;
//   }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
