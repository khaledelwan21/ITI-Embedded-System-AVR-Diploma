#include<stdio.h>

void Odd_Even_numbers(int * ,int *,int *) ;
void P_Z_N_numbers(int *,int *,int *,int *) ;

int n,sum=0 ;


int main()
{


printf("Enter the size of Array >>>>>>>>>>>>>   ") ;
scanf("%d" ,&n) ;

int arr[n] ;
for (int i=0 ; i<n ; i++)
{
	printf("Enter the element of %d : ",i+1) ;
	scanf("%d",(arr+i)) ;
}

for (int i=0 ; i<n ; i++)
{
	printf("%d\n",arr[i]) ;
}

for (int i=0;i<n/2;i++)
{
	int temp=arr[i] ;
	arr[i]=arr[n-i-1] ;
	arr[n-i-1]=temp ;
}
printf("==============================================================\n") ;
for (int i=0 ; i<n ; i++)
{
	printf("%d\n",arr[i]) ;
}


/*int count_p,count_n,count_z,count_e,count_o ;



Odd_Even_numbers(arr,&count_e,&count_o) ;
P_Z_N_numbers(arr ,&count_z,&count_p,&count_n) ;



printf("number of even numbers:   %d\n",count_e) ;
printf("number of odd numbers:   %d\n",count_o) ;
printf("number of posistive numbers:   %d\n",count_p) ;
printf("number of negative numbers:   %d\n",count_n) ;
printf("number of zero  numbers:   %d\n",count_z) ;


printf("Sum : %d\n",sum) ;
printf("Average : %f\n",sum/(n*1.0)) ;

for(int i=0 ; i<n-1;i++)
{
	for (int j=0;j<n-1-i;j++)
	{
		if(arr[j]>arr[j+1])  
		{
			
			int temp=arr[j] ;
			arr[j]=arr[j+1] ;
			arr[j+1]=temp ;
	
		}

	}

}

printf("The maximum >> %d \n\
The minimum >> %d \n",arr[n-1],arr[0]) ;
/*int search ;

printf("Enter your Search  Number: ") ;
scanf("%d",&search) ;
int low=0, high =n-1,middle ;
while(low<=high)
{
	
	middle=(low+high)/2 ;
	if(arr[middle]==search)
			break ;
	if(arr[middle]>search)   high =middle-1 ;
	else                      low = middle+1 ;
}	

(high>=low)?printf("index: %d\n" ,middle):printf("Not Found\n") ;

*/

		return 0 ;
}

void Odd_Even_numbers(int arr[],int * ptr_even,int *ptr_odd)
{ 
	
	for (int i=0 ; i<n ; i++)
	{
		if(arr[i]%2==0)   (*ptr_even)++ ;
		else 		   	 (*ptr_odd)++ ;	
	}
}

void P_Z_N_numbers(int arr[] ,int *ptr_Z,int *ptr_P,int *ptr_N)
{
	for (int i=0 ; i<n ; i++)
	{
		if(arr[i]>0)   (*ptr_P)++ ;
		else if(arr[i]<0)   (*ptr_N)++ ;
		else 		   (*ptr_Z)++ ;	
	}
}