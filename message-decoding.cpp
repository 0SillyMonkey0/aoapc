#include <stdio.h>
#include <string.h>

#define DEBUG 0
int code[8][1 << 8];
int de[1000];
int readcodes();
int readchar();
int readint(int len);

int main()
{
//	FILE *ftp;
//	ftp = fopen("debug.txt","w");
	while(readcodes())
	{
		int pos = 0;
		for(;;)
		{
			int len = readint(3);
			if(len == 0) break;
//			printf("len = %d\n", len);
			for(;;)
			{
				int v = readint(len);
				if(v == (1 << len) - 1) break;
				de[pos++] = code[len][v];
			}
		}	
		for(int i = 0; i < pos; i++)
			printf("%c", de[i]);
	#if DEBUG
		for(int i = 0; i < pos; i++)
			fprintf(ftp, "%c", de[i]);
		fprintf(ftp, "\n");
	#endif
		putchar('\n');
	}	
//	fclose(ftp); 
	return 0;
}

int readchar()
{
	for(;;)
	{
		int ch;
		if((ch = getchar()) != '\n')
			return ch;
	}
}

int readint(int len)
{
	int res = 0;
	while(len--)
		res += ((readchar() - '0') << len);
	return res;
}

int readcodes()
{
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for(int len = 2; len < 8; len++)
	{
		for(int v = 0; v < (1 << len) - 1; v++)
		{
			int ch = getchar();
			if(ch == EOF) return 0;
			if(ch == '\n') return 1;
			code[len][v] = ch;
		}
	}	
	return 1;
}


