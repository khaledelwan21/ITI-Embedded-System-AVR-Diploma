#include<stdio.h>



int main()
{   
int num =0,i=1;

	printf("enter the num : ") ;
	scanf("%d",&num) ;
	
	while((num>0)? i!=num+1 : i!=-num+1)
	{
		
		printf("%d * %d  = %d\n",num, i, i*num) ;
		i++;
	}
		
	return 0 ;
}


