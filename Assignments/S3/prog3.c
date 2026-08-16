#include<stdio.h>

int Factorial(int) ;
int Get_Num(char,int*) ;
int n,r ;

int fact_n ,fact_r;

int main()
{
	
fact_n =Get_Num('n',&n ) ;

fact_r =Get_Num('r',&r ) ;


	while(n<r) {
	
	printf("\"N\" must be >= \"R\"  try again \n") ;
	fact_r =Get_Num('r',&r ) ;
	}	
	int res=fact_n/Factorial(n-r) ;
	printf("     %dP%d     =  %d\n",n,r,res) ;
		return 0 ;
}

int Factorial(int n)
{

   if (n==1 || n==0 ) return 1 ;
   else  return  n*Factorial(n-1) ;
 
}
int Get_Num(char x, int *ptr) 
{
	while(1) 
{
	printf("Enter num of %c: ", x) ;

	scanf("%d",ptr) ;
	
	if(*ptr >=0) 
	{
	int fact=Factorial(*ptr) ;
	return fact ;
	} 
	else printf("Wrong ,,,Enter Positive Number \n") ;
}

}