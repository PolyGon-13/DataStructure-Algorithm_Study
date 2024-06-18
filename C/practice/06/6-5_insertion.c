#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void insertion(int a[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		int tmp=a[i];
		int j;
		for(j=i;j>0 && a[j-1]>tmp;j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}

int main()
{
	int nx;
	puts("단순 삽입 정렬");
	printf("요소 개수 : ");
	scanf("%d",&nx);
	int* x=calloc(nx,sizeof(int));

	int i;
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}

	insertion(x,nx);

	puts("오름차순으로 정렬했습니다.");
	for(i=0;i<nx;i++)
		printf("x[%d]=%d\n",i,x[i]);

	free(x);

	return 0;
}
