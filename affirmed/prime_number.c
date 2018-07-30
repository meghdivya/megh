
#include<stdio.h>
int check_if_prime(int num)
{
	if(0 >= num )
		return 0;
	int i = num;
	--i;
	while(i > 1)
	{
		//printf("%d :%d\n",__LINE__,i);
		if(num%i == 0)
		{
			printf("i=%d\n", i);
			return 0;
		}
		--i;
	}
	return 1;
}

int main()
{
	int num;
	scanf("%d",&num);
	if(check_if_prime(num))
	{
		printf("Number is prime\n");
	}
	else
	{
		printf("Number is not prime\n");
	}
	return 0;
}
