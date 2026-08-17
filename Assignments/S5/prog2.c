#include<stdio.h>

int n;
void Sort_Array(int * , int n ) ;
int main()
{
printf("Enter the size off Array >>>>>>>>>>") ;
scanf("%d",&n) ;
int arr[n] ;
for(int i=0 ; i<n;i++)
{
	printf("Enter the %d element : ",i+1) ;
	scanf("%d",&(*(arr+i))) ;
}
Sort_Array(arr , n) ;
for(int i=0 ; i<n;i++)
{
	printf(" %d\n",arr[i]) ;
	
}


return 0 ;
}

void Sort_Array(int *ptr ,int n) 
{
	
for (int i=0 ;i<n-1; i++)
{
for (int j=0;j<n-1-i;j++) 
{
	if (*(ptr+j)>(*(ptr+j+1)))
	{
		int temp = *(ptr+j) ;
		*(ptr+j) =(*(ptr+j+1)) ;
		(*(ptr+j+1)) =temp ;
	}
}
	
}	
}
