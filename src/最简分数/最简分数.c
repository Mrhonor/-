#include<stdio.h>
int Input(int*, int);
void qsort(int*,int);
void Output(int*,int);
int GCD_is_one(int, int);
void swap(int*a, int*b) 
{ 
	int temp1,temp2; 
	temp1 = *a;
	temp2 = *(a + 1);
	*a = *b;
	*(a + 1) = *(b + 1);
	*b = temp1;
	*(b + 1) = temp2;
}
int main()
{
	int num;
	scanf("%d", &num);
	int storage[20000];
	int number = Input(storage, num);
	qsort(storage,number);
	Output(storage,number);
}
int Input(int* array, int n)
{
	array[0] = 0;
	array[1] = 1;
	int code = 2;
	for (int numerator = n; numerator > 0; numerator--)
	{
		for (int denominator = 1; denominator < numerator; denominator++)
		{
			if (GCD_is_one(numerator, denominator))
			{
				array[code++] = denominator;
				array[code++] = numerator;
			}
		}
	}
	return code;
}


int GCD_is_one(int a, int b)
{
	int temp;
	temp = (a > b) ? a : b;
	b = (a < b) ? a : b;
	a = temp;
	while (a%b)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	if (b == 1)
		return 1;
	else
		return 0;
}

void qsort(int* array,int num)
{
	int number = 0;
	int *min_no, *min_deno;
	for (int a = 0; a < num - 1; a+=2)
	{
		min_no = &array[a];
		min_deno = &array[a + 1];
		for (int b = a; b < num; b+=2)
		{
			if (array[b] / (double)array[b + 1] < *min_no / (double)*min_deno)
			{
				min_no = &array[b];
				min_deno = &array[b + 1];
			}
		}
		swap(&array[a], min_no);
	}
}

void Output(int*array,int num)
{
	for (int i = 0; i < num; i+=2)
	{
		printf("%d/%d\n", array[i], array[i + 1]);
	}
}