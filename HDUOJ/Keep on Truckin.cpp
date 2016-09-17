#include <stdio.h>

int main(int argc, char *argv[])
{
	int height=168;
	int a[3],i;
	for(i=0;i<3;i++)
	scanf("%d",&a[i]);
	for(i=0;i<3;i++)
	if(a[i]<height)
	{
		printf("CRASH %d\n",a[i]);
		break;
	}
	if(i==3) printf("NO CRASH\n");
		
	//system("pause");
	return 0;
}
