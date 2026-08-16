#include<stdio.h>


int main()
{


int n ;
printf("Enter the Size of Array >>>>>>>>>>>>>>> ") ;
scanf("%d",&n) ;
int arr[n] ;

for(int i=0 ; i<n; i++) 
{
	
	printf("Enter the Element %d:",i+1) ;
	scanf("%d",&arr[i]) ;
}

for(int i =0 ;i<n-1 ;i++)
{
	for(int j=0 ;j<n-1-i;j++)
	{   
		if(arr[j] > arr[j+1] )
		{
			int temp=arr[j] ;
			arr[j] =arr[j+1] ;
			arr[j+1] =temp ;
			
		}
	}
}	
	printf("The Maximum >>>>>>>>  %d  \
	      \nThe Minimum >>>>>>>>  %d  \n ",arr[n-1],arr[0] ) ;

		return 0 ;
}

