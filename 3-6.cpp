#include <stdio.h>
#include <string.h>

#define maxn 100
#define DEBUG 0
int find_r(int num[maxn][maxn], int count)
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			if(num[i][j] == count)
				return i;
	
	return 99;
}

int find_c(int num[maxn][maxn], int count)
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			if(num[i][j] == count)
				return j;
	return 99;
}

int main()
{
//	FILE *fpt;
//	fpt = fopen("debug.txt", "w");
	int puzzle = 1;
	for(;;)
	{
		char s[maxn][maxn] = {0};
		int num[maxn][maxn] = {0};
		int line = 1, chlen;
		scanf("%d", &line);
		
		if(line == 0)
			break;
		scanf("%d", &chlen);
		
		for(int i = 0; i < line; i++)
			scanf("%s", s[i]);
		int count = 0;
		for(int i = 0; i < line; i++)
		{
			for(int j = 0; j < chlen; j++)
			{
				if(s[i][j] != '*' && (j == 0 || i == 0 || s[i][j - 1] == '*' || s[i - 1][j] == '*'))
					num[i][j] = ++count;
			}	
		}
//		for(int i = 0; i < line; i++)
//		{
//			for(int j = 0; j < chlen; j++)
//			{
//				printf("%2d%c", num[i][j], j == chlen - 1? '\n' : ' ');
//			}	
//		}
		
		printf("puzzle #%d:\n", puzzle++);
		printf("Across\n");
#if DEBUG
		fprintf(fpt, "puzzle #%d:\n", puzzle++);
		fprintf(fpt, "Across\n");
#endif
		for(int i = 0; i < line; i++)
		{
			int start = 0, end = 1;
			while(end != chlen - 1)
			{
				while(!num[i][start] && start < chlen)
					start += 1;
				if(start >= chlen)
					break;
				printf("%3d.", num[i][start]);
#if DEBUG
				fprintf(fpt, "%3d .", num[i][start]);
#endif				
				for(end = start; end < chlen && s[i][end] != '*'; end++);
				end--;
				while(start <= end)
				{
					printf("%c", s[i][start]);
#if DEBUG
					fprintf(fpt, "%c", s[i][start]);
#endif
					start++;
				}	
				
				printf("\n");	
#if DEBUG
				fprintf(fpt, "\n");
#endif
			}
		}
		
		printf("Down\n");
#if DEBUG
		fprintf(fpt, "Down\n");
#endif
		for(int i = 1; i <= count; i++)
		{
			int col = find_c(num, i);
			int start = find_r(num, i);
			if(num[start][col])
			{
				
				printf("%3d.", num[start][col]);
#if DEBUG
				fprintf(fpt, "%3d .", num[i][start]);
#endif	
				for(int j = start; s[j][col] != '*' && j < line; j++)
				{
					printf("%c", s[j][col]);
#if DEBUG
					fprintf(fpt, "%c", s[i][start]);
#endif
					num[j][col] = 0;
				}
				printf("\n");
#if DEBUG
				fprintf(fpt, "\n");
#endif
			}
		}
		printf("\n");
#if DEBUG
		fprintf(fpt, "\n");
#endif
		
	} 
//	fclose(fpt); 
}







