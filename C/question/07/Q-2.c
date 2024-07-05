#include <stdio.h>

#define swap_ptr(type,x,y) do{type *t=x; x=y; y=t;} while(0)

int main()
{
	char *s1="ABCD";
	char *s2="EFGH";
	
	printf("포인터 s1은 \"%s\"를 가리킵니다.\n",s1);
	printf("포인터 s2는 \"%s\"를 가리킵니다.\n",s2);
	
	swap_ptr(char *,s1,s2);
	
	puts("\n포인터 s1과 s2의 값을 서로 교환했습니다.\n");
	
	printf("포인터 s1은 \"%s\"를 가리킵니다.\n",s1);
	printf("포인터 s2는 \"%s\"를 가리킵니다.\n",s2);
	
	return 0;
}
