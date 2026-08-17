#include<stdio.h>


//void  func(int *ptr1,int *ptr2, int * ,int*) ;
//int num1,num2 ;
void func(void) ;
int main()
{
/*int sum ,sub ;
printf("enter value1: ") ;
scanf("%d",&num1) ;
printf("enter value2: ") ;
scanf("%d",&num2) ;


func(&num1 ,&num2,&sum,&sub) ;

printf("Sum >>>>> %d\n" ,sum) ;
printf("Sub >>>>> %d\n" ,sub) ;*/
int n ;
printf("%p\n",&n) ;
func();
/*printf("Enter the size of Array >>>>>>>>>>>>>   ") ;
scanf("%d" ,&n) ;
int arr[n] ;
int *ptr=arr ;
int sum=0 ;
for (int i=0 ; i<n ; i++)
{
	printf("Enter the element of %d : ",i+1) ;
	scanf("%d",ptr+i) ;
	sum+=*(ptr+i) ;
}
printf("Sum of Array >>>>>>>>>>>>>> %d \n", sum) ;

*/
return 0 ;
}
/*
void func(int *ptr1,int *ptr2,int *sum,int *sub) 
{
	
	*sum = *ptr1+*ptr2 ;
	*sub = *ptr1-*ptr2 ;
}*/
void func(void)
{
printf("%p\n",&n) ;
}