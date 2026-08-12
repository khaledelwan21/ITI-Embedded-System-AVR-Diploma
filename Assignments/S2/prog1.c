#include<stdio.h>

int main()
{
	
	int num1,num2,num3,max;
	printf("enter the num1 :") ;
	
	scanf("%i",&num1) ;
	printf("enter the num2 :") ;
	
	scanf("%i",&num2) ;
	printf("enter the num3 :") ;
	
	scanf("%i",&num3) ;
	
	max=num1 ;
	
		
	if(max<num2)  
		max=num2;
		
	if(max<num3)  
		max=num3;
	
	printf("The greatest number :%d\n",max) ;
	

	return 0 ;
}
