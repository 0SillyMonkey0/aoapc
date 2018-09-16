#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn 100
const float gmol[] = {12.01, 1.008, 16.00, 14.01};
const char ele[] = {'C', 'H', 'O', 'N'};

int element(char ch)
{
	for(int i = 0; i < 4; i++)
	{
		if(ch == ele[i])
			return i;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		float mass = 0;
		char molar[maxn];
		scanf("%s", molar);
		int len = strlen(molar);
		for(int i = 0; i < len; i++)
		{
			if(isalpha(molar[i]))
			{
				int e = element(molar[i]);
				if(len == 1 || (i == len - 1 && isalpha(molar[i])))
					mass += gmol[e];
				if(i != len - 1 && isalpha(molar[i + 1]))
					mass += gmol[e];
				else if(i != len - 1 && isdigit(molar[i + 1]))
				{
					char num[5] = {0};
					int pos = 0;
					for(int j = i + 1; j < len; j++)
					{
						if(isalpha(molar[j]))
							break;
						num[pos++] = molar[j];
					}
					int numlen = strlen(num);
					for(int j = 0; j < numlen; j++)
						mass += gmol[e] * (num[j] - '0') * pow(10, numlen - 1 - j);
				}
			}		
		}
		printf("%.3f\n", mass);
	}
	return 0;
}
