#include <stdio.h>
#include <stdlib.h>

void counting(int a[],int n,int max)
{
	int i;
	int *f=calloc(max+1,sizeof(int));
	int *b=calloc(n,sizeof(int));
	
	for(i=0;i<n;i++) printf("%3d",i); putchar('\n');
	for(i=0;i<n;i++) printf("---"); putchar('\n');
	for(i=0;i<n;i++) printf("%3d",a[i]); putchar('\n');
	
	for(i=0;i<=max;i++) f[i]=0;
	for(i=0;i<n;i++) f[a[i]]++;
	
	for(i=0;i<max;i++) printf("%3d",i); putchar('\n');
	for(i=0;i<max;i++) printf("---"); putchar('\n');
	for(i=0;i<max;i++) printf("%3d",f[i]); putchar('\n');
	
	for(i=1;i<=max;i++) f[i]+=f[i-1];
	
	puts("\n누적 도수 분포");
	for(i=0;i<max;i++) printf("%3d",i); putchar('\n');
	for(i=0;i<max;i++) printf("---"); putchar('\n');
	for(i=0;i<max;i++) printf("%3d",f[i]); putchar('\n');
	
	putchar('\n');	
	for(i=n-1;i>=0;i--)
	{
		b[--f[a[i]]]=a[i];
		printf("a[%2d]의 %2d를 b[%2d]에 저장\n",i,a[i],f[a[i]]);
	}
	
	for(i=0;i<n;i++) a[i]=b[i];
	
	puts("\n정렬 후의 배열");
	for(i=0;i<n;i++) printf("%3d",i); putchar('\n');
	for(i=0;i<n;i++) printf("---"); putchar('\n');
	for(i=0;i<n;i++) printf("%3d",a[i]); putchar('\n');
	
	free(b);
	free(f);
}

int main()
{
	int i;
	int nx;
	const int max=100;
	puts("도수 정렬");
	printf("요소 개수 : ");
	
	scanf("%d",&nx);
	int *x=calloc(nx,sizeof(int));
	printf("0~%d의 정수를 입력하세요\n",max);
	for(i=0;i<nx;i++)
	{
		do
		{
			printf("x[%d] : ",i);
			scanf("%d",&x[i]);
		} while(x[i]<0 || x[i]>max);
	}
	
	counting(x,nx,max);
	puts("오름차순으로 정렬했습니다.");
	
	for(i=0;i<nx;i++)
		printf("x[%d] = %d\n",i,x[i]);
	
	free(x);
	
	return 0;
}
