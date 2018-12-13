#include <stdio.h>
#include <math.h>
int count = 1;
int isprime[50000] = { 2 };
int find_prime_num(int);
int main()
{
	int line;
	scanf("%d", &line);
	for (int i = 0; i < line; i++)
	{
		int number;
		scanf("%d", &number);
		int outcome = find_prime_num(number);
		printf("%d\n", outcome);
	}
}

int find_prime_num(int a)
{
	for (int i = isprime[count-1]+1; count < a; i++)
	{
		int flag = 1;
		for (int b = 0; isprime[b] <= sqrt(i); b++)
		{
			if (i%isprime[b] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			isprime[count] = i;
			count++;
		}
	}
	return isprime[a - 1];
}






