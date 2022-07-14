#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
									/*     Eren Kement 1801042096              */
int select_shape();														/*       Homework 5         */
int select_calc();
int calculate(int(), int());
int calc_triangle(int);
int calc_quadrilateral(int);
int calc_circle(int);
int calc_pyramid(int);
int calc_cylinder(int);


enum shapes {triangle = 1, quadrilateral, circle, pyramid, cylinder};				/*   Enums start from 1                */
enum calculators {area = 1, perimeter, volume};



int main() {

	int val;
	
	
	printf("Welcome to the geometric calculator!\n\n");
	
	do{
									/*     do while until the user type 0 to exit              */
	
	val = calculate(select_shape, select_calc);
	
	}while(val != 0);

	return 0;

}



int select_shape() {							/*     Controls if the selection is valid not a char              */

	int choice_shape;
	int check;
	
	do{
	printf("Select a shape to calculate:\n-----------------\n1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cylinder\n0. Exit\n----------------\nInput : ");
	check = scanf("%d", &choice_shape);
	
	if(check != 1) {
		
		getchar();
		
		printf("\n\nPlease enter a valid input!\n\n");				/*      getchar to not to get infinite loop             */
	
	}
	
	}while(check != 1);
	
	printf("\n");
	
	
	return choice_shape;



	

}


int select_calc() {

	int choice_calc;
	int check;
	
	do{
	
	
	printf("Select calculator:\n-----------------------\n1. Area\n2. Perimeter\n3. Volume\n0. Exit\n---------------\nInput : ");
	check = scanf("%d", &choice_calc);
	
	if(check != 1) {
		
		getchar();
		
		printf("\nPlease enter a valid input!\n\n");					/*    gets input for calc selection               */
	
	}
	
	}while(check != 1);
	
	printf("\n");
	
	return choice_calc;




}


int calculate(int (*f1)(), int (*f2)()) {					/*   Functions as parameters                */

	
	int result;
	
	int shape_selection = (*f1)();					/*     Function call and a variable to store its return value              */
	
	
	switch(shape_selection) {
	
		case 1:
			
			calc_triangle((*f2)());						/* I didn't create a variable to store f2 function pointer result in order to exit in case of input 0*/
			result = 1;
			
			break;
			
		
		case 2: 
		
			calc_quadrilateral((*f2)());
			result = 1;
		
			break;
			
		case 3:	
			calc_circle((*f2)());
			result = 1;
			
			break;
			
			
		case 4:
			calc_pyramid((*f2)());
			result = 1;
			
			break;
			
			
		case 5: 
			calc_cylinder((*f2)());
			result = 1;
		
			break;
			
		case 0:
			
			printf("Cancelling...\n");
			result = 0;								/* return 0 to exit */
			break;
		
		default:
		
			printf("\n\nPlease enter a valid entry!\n\n");
			result = -999;
			break;
	
	
	
	
	}
	
	return result;
	

}







int calc_triangle(int select) {

	double s1, s2, s3, ar, peri, s;
	int check1, check2, check3;
	int errorcount = 0;
	int result;
	
	if(select == volume) {											/*    There is no volume calculation for a triangle               */
	
		printf("ERROR! You cannot calculate the volume of a triangle. Please try again.\n\n");
		result = -1;
		return result;
	}
	
	if(select == 0) {
	
	
		printf("Cancelling...\n");					/*   Quit                */
		result = 0;
		return result;
	
	
	}
	
	
	printf("Please enter three sides of Triangle : \n");
	
	check1 = scanf("%lf", &s1); 
	check2 = scanf("%lf", &s2);
	check3 = scanf("%lf", &s3);					/*    checks for controlling input types               */
	
	
	 do {
		
		if(check1 != 1 ||  check2 != 1 || check3 !=  1 || s1 <= 0  || s2 <= 0 || s3 <= 0)
		
		{
		
		
		getchar();
		
		errorcount++;						/*    Counts error               */
		
		printf("ERROR ! Please enter a valid input!\n\n");
	
		
		check1 = scanf("%lf", &s1); 
		check2 = scanf("%lf", &s2);
		check3 = scanf("%lf", &s3);
		
		
		
		
		}
		
		else
			errorcount = 0;
			
			
			
			
		if(s1 + s2 < s3 || s1 + s3 < s2 || s2 + s3 < s1)					/*   Triangle rule                */
		
		{
		
		
		getchar();
		
		errorcount++;
		
		printf("ERROR ! Please enter a valid triangle!\n\n");
	
		
		check1 = scanf("%lf", &s1); 
		check2 = scanf("%lf", &s2);
		check3 = scanf("%lf", &s3);
		
		
		
		
		}
		
		else
			errorcount = 0;
			
			
		
		
		
		
	
	
	}while(errorcount != 0);
	
	peri = s1 + s2 + s3;
	s = peri / 2;
	ar = sqrt(s * (s - s1) * (s - s2) * (s - s3));				/*    Geometric rules               */
	
	
	switch(select) {
	
		case area:
			
			result = 1;
			
			printf("Area of TRIANGLE : %.2lf\n", ar);
			
			
		
			break;
		
		case perimeter: 
			
			result = 1;
			printf("Perimeter of TRIANGLE : %.2lf\n", peri);
		
			break;
			
			
		default:
			
			printf("Please try again!\n");
			result = -999; 						/* Probably don't go there*/
			
			break;
			
			
	
		return result;
	
	
	
	
	}





}



int calc_quadrilateral(int select) {

	int result, errorcount = 0;
	int check1, check2, check3, check4;
	double s1, s2, s3, s4, ar, peri, s;
	

	if(select == volume) {
	
		printf("\n\nERROR! You cannot calculate the volume of a quadrilateral. Please try again.\n\n");
		result = -1;
		return result;
	}
	
	
	
	if(select == 0) {
	
	
		printf("Cancelling...\n");	
		result = 0;
		return result;
	
	
	}
	
	printf("Please enter four sides of Quadrilateral : \n");
	
	check1 = scanf("%lf", &s1); 
	check2 = scanf("%lf", &s2);
	check3 = scanf("%lf", &s3);
	check4 = scanf("%lf", &s4);
	


	do{
	
		if(check1 != 1 || check2 != 1 || check3 != 1 || check4 != 1 || s1 <= 0 || s2 <= 0 || s3 <= 0 || s4 <= 0) {			/*   No negative length                */
		
		errorcount++;
		getchar();
		printf("\n\nPlease enter a valid input!\n\n");
		
		check1 = scanf("%lf", &s1); 
		check2 = scanf("%lf", &s2);
		check3 = scanf("%lf", &s3);
		check4 = scanf("%lf", &s4);
		
		
		
		}
		
		else 
			errorcount = 0;
			
		
	
	
	}while(errorcount != 0);
	
	peri = s1 + s2 + s3 + s4;
	s = peri / 2; 
	ar = sqrt((s - s1) * (s - s2) * (s - s3) * (s - s4));


	switch(select) {
	
		case area:
			printf("Area of QUADRILATERAL : %.2lf\n\n", ar);
			result = 1;
			break;
			
		case perimeter:
			printf("Perimeter of QUADRILATERAL : %.2lf\n\n", peri);
			result = 1;
			break;
			
		
		default:
		
			printf("Please try again!\n");
			result = -999; 						/* Probably don't go there*/
			break;
			
	
	
	
	
	
	
	}


}



int calc_circle(int select) {

	int result, errorcounter = 0, check;						/*       Calculations for a circle            */
	double circum, ar, radius;
	


	if(select == volume) {
	
		printf("\n\nERROR! You cannot calculate the volume of a circle. Please try again.\n\n");
		result = -1;
		return result;
	}


	printf("Please enter the radius of Circle : \n");
	check = scanf("%lf", &radius);
	
	do{
	
		if(check != 1 || radius <= 0) {
			
			
			getchar();			
						
			errorcounter++; 
			
			printf("\n\nPlease enter a valid input!\n\n");
			
			check = scanf("%lf", &radius);
			
		
		}
		
		else 
			errorcounter = 0;
	
	
	
	}while(errorcounter != 0);

	circum = 2 * PI * radius;
	ar = PI * radius * radius;



	switch(select) {
	
		case area:
			printf("Area of CIRCLE : %.2lf\n\n", ar);
			result = 1;
			break;
			
		case perimeter:
		
			printf("Circumference of CIRCLE : %.2lf\n\n", circum);
			result = 1;
			break;
			
		default:
						
			printf("Please try again!\n");
			result = -999; 						/* Probably don't go there*/
			break;
	
	
	
	}



	return result;



}

int calc_pyramid(int select) {


	int result, errorcounter, check1, check2, check3;
	double side, height, slant, vol, peri,  base, lateral, sur;
	
	
	if(select == 0) {
	
	
		printf("Cancelling...\n");	
		result = 0;
		return result;
	
	
	}
	
	
	switch(select) {
	
		case volume:
			
			errorcounter = 0;
			
			printf("Please enter the base side and height of a Pyramid : \n");
			do{
			
			
			check1 = scanf("%lf", &side);
			check2 = scanf("%lf", &height);
			
			if(check1 != 1 || check2 != 1 || side <= 0 || height <= 0) {						/*  No negative side or height                 */
			
				
				getchar();
				
				printf("\n\nPlease enter a valid input!\n\n");
				errorcounter++;
				
			
			
			}
			
			else
				errorcounter = 0;
				
				
			
			
			}while(errorcounter != 0);
			
			vol = side * side * height / 3;		
			
			printf("Volume of a Pyramid: %.2lf\n\n", vol);
			
			result = 1;
			
			break;
			
		case area:
			
			errorcounter = 0;
			
			
			printf("Please enter the base side and slant height of a Pyramid : \n");
			do{
			
			
			check1 = scanf("%lf", &side);
			check2 = scanf("%lf", &slant);
			
			if(check1 != 1 || check2 != 1 || side <= 0 || slant <= 0 ) {
			
				getchar();
				
				printf("\n\nPlease enter a valid input!\n\n");
				errorcounter++;
				
			
			
			}
			
			else
				errorcounter = 0;
				
				
			
			
			}while(errorcounter != 0);							/*   I had to do all the process in the switch case because of the different inputs         */
			
			base = side * side;
			lateral = 2 * side * slant;
			sur =  base + lateral;
			
			printf("\n\nBase Surface Area of a PYRAMID : %.2lf\n\n", base);
			printf("\n\nLateral Surface Area of a PYRAMID : %.2lf\n\n", lateral);
			printf("\n\nSurface Area of a PYRAMID : %.2lf\n\n", sur);
			
			result = 1;
			
			break;
			
			
		case perimeter:
			
			errorcounter = 0;
			
			printf("Please enter the base side of a Pyramid : \n");
			
			do{
			
			check1 = scanf("%lf", &side);
			
			if(check1 != 1 || side <= 0) {
			
				getchar();
				printf("\n\nPlease enter a valid input!\n\n");
				errorcounter++;
			
			}
			
			else 
				errorcounter = 0;
			
			}while(errorcounter != 0);
			
			
			peri = 4 * side;
			
			printf("\n\nBase Surface Perimeter of a Pyramid : %.2lf\n\n", peri);	
			
			
			result = 1;
			
			break;	
			
			
			
			
	
	
	}
	
	
	return result;




}


int calc_cylinder(int select) {



	double radius, height, vol, base, lateral, sur, peri;
	int errorcounter, result, check1, check2;
	
	if(select == 0) {
	
	
		printf("Cancelling...\n");	
		result = 0;
		return result;
	
	
	}
	
	
	printf("Please enter the radius and height of a Cylinder : \n");
	
	
	
	do {
	
		check1 = scanf("%lf", &radius);
		check2 = scanf("%lf", &height);
		
		
		if(check1 != 1 || check2 != 1 || radius <= 0 || height <= 0) {				/*        Controls all at once           */
			
			getchar();
			printf("\n\nPlease enter a valid input!\n\n");
			errorcounter++;
		
		
		}
		
		else 
			errorcounter = 0;
		
	
	
	
	}while(errorcounter != 0);
	
	
	vol = PI * radius * radius * height;
	base = PI * radius * radius;
	lateral = 2 * PI * radius * height;							/*    All the formulas are there               */
	sur = 2 * PI * radius * (radius + height);
	peri = 2 * PI * radius;
	
	
	switch(select) {
	
		case volume:
			printf("Volume of a CYLINDER: %.2lf\n\n", vol);
			result = 1;
			break;
			
		case area:
			
			printf("\n\nBase Surface Area of a CYLINDER : %.2lf\n\n", base);
			printf("\n\nLateral Surface Area of a CYLINDER : %.2lf\n\n", lateral);
			printf("\n\nSurface Area of a CYLINDER : %.2lf\n\n", sur);
			
			result = 1;
			
			break;
			
		case perimeter:
		
			printf("\n\nBase Surface Perimeter of a CYLINDER : %.2lf\n\n", peri);
			result = 1;
			
			break;
	
	
	}

	
	return result;




}


