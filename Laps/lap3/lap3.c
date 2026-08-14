#include<stdio.h>


float Area_Circle(float ) ;
float Volume_Cylinder(float,float ) ;
int $main ;
int main()
{
	
	/*for(int i=0;i<=20;i+=2)
		printf("%d\n",i) ;*/
	
	/*********************************************************************/
  /*int num;
	do
	{
	printf("please enter a number less than 100:\n") ;
	
	scanf("%i",&num) ;
	}
	while(num>=100) ;
		
	printf("Thanks 3>\n") ;
	/**********************************************************************/
	
	/*int sum=0 ,num;
	for(int i=0;i<10;i++)
	{
		printf("enter the num:") ;
		scanf("%d",&num);
		sum+=num ;
	
	}
	
	printf("the summation:%d\n",sum) ;*/
	/************************************************************************/
	//int num,fac=1;
	/*printf("enter the num :") ;
	
	scanf("%i",&num) ;
	
	if(num==0) 
		printf("factorial of !%d = %d\n",num,fac) ;
	else if(num>0)
	{
		for(int i=1;i<=num;i++)
			{
				fac*=i ;
			}
			printf("factorial of !%d = %d\n",num,fac) ;
	}
	else
		printf("error num should be positive\n") ;*/
	/**************************************************************************/
	/*do
	{
		
		printf("enter the num :") ;
	
	scanf("%i",&num) ;
	
	if(num==0) 
		printf("factorial of !%d = %d\n",num,fac) ;
	else 
	{
		for(int i=1;i<=num;i++)
			{
				fac*=i ;
			}
			printf("factorial of !%d = %d\n",num,fac) ;
			fac=1 ;
	}
	}
	while(num>=0) ;
	printf("error num should be positive\n") ;*/
	/***********************************************************************************/
	float r,h ,area,volume ;
	
	printf("enter radius of circle:") ;
	scanf("%f",&r) ;

	area =Area_Circle(r) ;
	printf("Area of circle:%.2f\n\n",area) ;
	
	printf("enter radius of cylinder:") ;
	scanf("%f",&r) ;
	printf("enter height of cylinder:") ;
	scanf("%f",&h) ;
	
	volume =Volume_Cylinder(r,h) ;
	
	printf("Volume of cylinder:%.2f\n\n",volume) ;
	/*************************************************************************************/
	return 0 ;
}


float Area_Circle(float r)
{
	
	return r*r*3.14 ;
	
}

float Volume_Cylinder(float r, float h)
{
	
	return Area_Circle(r)*h ;
	
}