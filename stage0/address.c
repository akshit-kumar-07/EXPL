#include <stdio.h>
#include <stdlib.h>
int main()
{
	char x;
	while(1)
	{
		getchar();
		scanf("%c",&x);
		switch(x)
		{
			case 't':
				return 0;
				break;
			default:
				int y=atoi(x);
				printf("The address is %d and the addend is %d\n",2056+(y-9)*2,(y-9)*2);
				break;
		}
	}
	return 0;
}
