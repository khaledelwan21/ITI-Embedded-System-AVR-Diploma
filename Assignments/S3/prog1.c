#include<stdio.h>



int main()
{   
int ans =0;

	while(1) 
	{
	printf("enter the result of (7*6)=") ;
	scanf("%d",&ans) ;
	
	if (ans == 6*7) 
	{
		
		printf("Correct answer........\n") ;
		break ;
	}
	else  printf("Wrong answer  try again....\n") ;
		
	}	


	return 0 ;
}


