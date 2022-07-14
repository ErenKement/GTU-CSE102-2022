#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

   int problem_selection;
   double pl, pw, sl, sw;
   char problem1, problem1a, problem1b;
   double problem2, problem2a, problem2b, x1, x2, x3;
   int x4, x5;
   double big, small;
   double height, salary;
   int gender;
   int rebound, point;
   double problem3, problem3a, problem3b;     /*The variables that are needed for all the program */
   
   do {													/*When the user type 999 in the selection screen the program stops */
   
   printf("\nProblem 1\n\nProblem 2\n\nProblem 3\n\n\n");
   printf("Which problem do you want me to solve? If you enter 999 the program will stop. Enter 1, 2, or 3 respectively: ");
   scanf("%d", &problem_selection);
   
   if(problem_selection < 1 || problem_selection > 3 && problem_selection != 999) {    		/* Only 1-2-3 selections are acceptable*/
   	
   
   	printf("\n\nPlease enter a valid number!\n\n\n");
   
   
   } 
   
   
   if(problem_selection == 1) {
   	
   	printf("PL: ");
   	scanf("%lf", &pl);
   	
   	printf("PW: ");
   	scanf("%lf", &pw);
   	
   	printf("SL: ");
   	scanf("%lf", &sl);
   	
  	printf("SW: ");
   	scanf("%lf", &sw);				/* Taking inputs for the first problem*/
   	
   	printf("\n");
   	
  	problem1a = dt1a(pl, pw, sl, sw);
  	problem1b = dt1a(pl, pw, sl, sw);
  	
  	if(problem1a == problem1b) {   			/*If the both solutions are the same */
  	
  	problem1 = problem1a;									/*Actuallly, not necessary but for a clear meaning */
  	
  	printf("\nThe solution in both cases is %c\n\n\n", problem1);
  	
  	}
  	
  	else {
  	
  	printf("\nFirst Solution: %c\n", problem1a);
  	printf("\nSecond Solution: %c\n", problem1b);					/* Different results */
  
  	}
  
   }
   
   
   else if(problem_selection == 2) {
   
     
   	do {
   	
   	
   	printf("x1: ");
   	scanf("%lf", &x1);
   	
   	printf("x2: ");
   	scanf("%lf", &x2);
   	
   	printf("x3: ");
   	scanf("%lf", &x3);
   	
   	printf("x4 (0 or 1): ");					/* x4 and x5 must be binary*/
   	scanf("%d", &x4);
   	
   	printf("x5 (0 or 1): ");
   	scanf("%d", &x5);
   	
   	if(x4 > 1 || x4< 0 || x5 > 1 || x5 < 0) {
   	
   		printf("\nx4 and x5 may only takes binary values, 0 and 1\n");
   	}
   	
   	
   	
   	} while(x4 > 1 || x4< 0 || x5 > 1 || x5 < 0);
   	
   	printf("\n\n");
   	
   	
   	problem2a = dt2a(x1, x2, x3, x4, x5);
   	problem2b = dt2b(x1, x2, x3, x4, x5);
   	
   	
   	big = bigger(problem2a, problem2b);
   	small = smaller(problem2a, problem2b);       /* I wrote my own functions to find the bigger and the smaller*/
   	
   	
   	if((big - small) < CLOSE_ENOUGH) {					/* A control with the macro */
   	
   		problem2 = (problem2a + problem2b) / 2;
   		
   		printf("\nThe final solution (average of two): %lf\n", problem2);
   	
   	}
   	
   	
   	else {
   	
   	
   		printf("\nThe first solution: %lf\n\n", problem2a);
   		printf("\nThe second solution: %lf\n\n", problem2b);			/* Different results*/
   	
   	
   	
   	}
	   
   
   }
   
   else if(problem_selection == 3) {							/* I have created a program that takes inputs and generates player rating*/
   
   	printf("\nWelcome to the basketball player rater!!\n\n");
   	
   	do {
   	
   	printf("\nFor a female player press 0 and for a male player press 1: ");
   	printf("\n");
   	scanf("%d", &gender);
   	
   	if(gender > 1 || gender < 0) {
   		printf("\nPlease enter a valid input for the gender!!!\n\n");     }			/* I have used gender as binary value*/
   	
   	}while(gender > 1 || gender < 0);
   	
   	printf("\nPlease enter the height of the player in meters (ex. 1.92): ");
   	scanf("%lf", &height);
   	
   	printf("\nPlease enter the annual salary of the player in million dollars (ex. for $1.78 million, type just 1.78): ");
   	scanf("%lf", &salary);
   	
   	printf("\nHow many points are scored(for numbers grater than 31, just type 31): ");
   	scanf("%d", &point);
   	
   	printf("\nHow many rebounds are taken(for numbers greater than 15, just type 15): ");
   	scanf("%d", &rebound);
   	
   	if(point > 31)						/* More than 5, I have used 32 base and 16 base*/
   		point = 31;
   		
   	if(rebound > 15)
   		rebound = 15;						/* The maximum values  */
   		
   	
   	problem3a = dt3a(height, salary, rebound, gender, point);
   	problem3b = dt3b(height, salary, rebound, gender, point);
   	
   	big = bigger(problem3a, problem3b);
   	small = smaller(problem3a, problem3b);					/* I have used my functions again*/
   	
   	if(big - small < CLOSE_ENOUGH) {												/* Again a control with the macro*/
   		
   		problem3 = (problem3a + problem3b) / 2;				/* Arithmetic meean*/
   		
   		printf("\nThe solution is (average of two): %lf\n", problem3);
   		
   		if(problem3 > 0.0080)
   			printf("\nThe player has played well\n");
   		else 
   			printf("\nStll has a place for improvement\n");					/*classification based on returning double values */
   	
   	}
   	
   	else {
   	
   		printf("\nThe first solution: %lf\n\n", problem3a);
   		printf("\nThe second solution: %lf\n\n", problem3b);
   		
   		
   		if(problem3a > 0.0075 && problem3b > 00.75)
   			printf("\nThe player has played well\n");
   		else 
   			printf("\nStll has a place for improvement\n");
   	
   	}
   
   
   }
   
   
   
   
   
   
   } while(problem_selection != 999);					/* Halts when the user wants*/
   
   
   
   
   
   
   
   
   
   
   
    /* Ask for the problem selection (1,2,3) .....  */

    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */

    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */

    return 0;
}
