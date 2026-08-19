
// Assignment node linked list


#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
typedef struct
{
	u32 salary ;
	u32 bouns ;
	u32 deduction  ;
} student ;

int main()
{
	student khaled ;
	khaled.salary=4000 ;
	khaled.bouns=200 ;
	khaled.deduction=50;
	
	student ahmed ;
	ahmed.salary=6000 ;
	ahmed.bouns=0;
	ahmed.deduction=500;
	
	student ali ;
	ali.salary=2000;
	ali.bouns=200 ;
	ali.deduction=0;
	
	u32 sum_salary = khaled.salary+ahmed.salary+ali.salary ;
	u32 sum_bouns =khaled.bouns+ahmed.bouns+ali.bouns ;
	u32 sum_deduction=khaled.deduction+ahmed.deduction+ali.deduction ;
	printf("The value needded ; %d\n",sum_salary+sum_bouns-sum_deduction) ;
	
    return 0;
}	