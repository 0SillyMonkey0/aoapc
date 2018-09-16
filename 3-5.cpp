#include <stdio.h>
#include <string.h>
int main()
{
	for(;;)
	{
		char puzzle[10][10] = {0};
		int flag = 1;
		int row = 0, col = 0;
		char c;
		for(int i = 0; i < 5; i++)
		{
			fgets(puzzle[i], 7, stdin);
			for(int j = 0; j < 5; j++)
				if(puzzle[i][j] == ' ')
				{
					row = i;
					col = j;
				}
			
			if(strcmp(puzzle[i], "Z\n" ) == 0)
			{
				flag = 0;
				break;
			}
	    }
	    
	    if(flag == 0)
	    	break;
	    
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				printf("%c%c", puzzle[i][j], j == 4 ? '\n': ' ');	
	    flag = 1; 
		while((c = getchar()) != '0')
		{
			if(c == 'A')
			{
				puzzle[row][col] = puzzle[row - 1][col];
				row--;
				if(row < 0)
					flag = 0;
				puzzle[row][col] = ' ';
			}
			
			if(c == 'B')
			{
				puzzle[row][col] = puzzle[row + 1][col];
				row++;
				if(row > 4)
					flag = 0;
				puzzle[row][col] = ' ';
			}
			
			if(c == 'L')
			{
				puzzle[row][col] = puzzle[row][col - 1];
				col--;
				if(col < 0)
					flag = 0;
				puzzle[row][col] = ' ';
			}
			
			if(c == 'R')
			{
				puzzle[row][col] = puzzle[row][col + 1];
				col++;
				if(col > 4)
					flag = 0;
				puzzle[row][col] = ' ';
			}
		}	
		c = getchar();
		
		if(flag)
		{
			for(int i = 0; i < 5; i++)
				for(int j = 0; j < 5; j++)
					printf("%c%c", puzzle[i][j], j == 4? '\n': ' ');
		}
		else printf("This puzzle has no final configuration.\n");
	}
	return 0;
} 
