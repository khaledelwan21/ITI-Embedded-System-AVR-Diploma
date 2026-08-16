#include<stdio.h>

void Odd_Even_numbers(int * ,int *,int *) ;
int n ;

int main()
{

int Sum_E=0,Sum_O=0 ;

printf("Enter the Size of Array >>>>>>>>>>>>>>> ") ;
scanf("%d",&n) ;
int arr[n] ;

for(int i=0 ; i<n; i++) 
{
	
	printf("Enter the Element %d:",i+1) ;
	scanf("%d",&arr[i]) ;
	
}


Odd_Even_numbers(arr,&Sum_E,&Sum_O) ;

printf("The Sumiation of even numbers:   %d\n",Sum_E) ;
printf("The Sumiation of odd numbers :   %d\n",Sum_O) ;

return 0 ;
}

void Odd_Even_numbers(int arr[],int * ptr_even,int *ptr_odd)
{ 
	
	for (int i=0 ; i<n ; i++)
	{
		if(arr[i]%2==0)   (*ptr_even) +=arr[i] ;
		else 		   	  (*ptr_odd)  +=arr[i]  ;	
	}
}