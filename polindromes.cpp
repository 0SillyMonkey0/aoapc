#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char r(char ch)
{
	if(isalpha(ch)) return rev[ch - 'A'];
	else{
//		printf("%c\n", rev[ch - '0' + 25]);
		return rev[ch - '0' + 25];	
	}
	
}

int main()
{
	
	char s[20];
	while(scanf("%s", s) == 1)
	{
		int prol = 1, miro = 1;
		int len = strlen(s);
		for(int i = 0; i < (len + 1)/2; ++i)
		{
			if (s[i] != s[len - 1- i])  prol = 0;
			if (r(s[i]) != s[len - 1 - i]) miro = 0;
		}	
		
		if(prol && !miro)
			printf("%s -- is a regular polindromes\n\n", s);
		else if(!prol && !miro)
			printf("%s -- is not a palindrome\n\n", s);
		else if (!prol && miro)
			printf("%s -- is a mirrored string\n\n", s);
		else if(prol && miro)	
			printf("%s -- is a mirrored palindrome\n\n", s);
	}
}

