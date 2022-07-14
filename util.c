#include <stdio.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {				
    int r = 0;
    if (t>35 && w!=3) r = 1;					/*Because it's an example I don't use it the selection screen. There's no obligation for that, right?*/
    else if (t<=35 && s==0) r = 1;
    return r;
}


/* Provide your implementations for all the requested functions here */




double bigger(double q, double w) {

	if (q > w) {
		
		
		return q;
		
		
		}
	
	
	else { 
		return w;

	    }
}
							/* My basic funtions to find the bigger and the smaller of the two functions*/



double smaller(double q, double w) {				
	
	if (q > w) {
		
		
		return w;
		
		
		}
	
	
	else { 
		return q;

	    }
}

char dt1a(double pl, double pw, double sl, double sw) {

	if(pl < 2.45) {
	
		return 'S';
							/* I do exactly like in the flowchart*/

	}
	
	else if(pw < 1.75) {
	
		if(pl < 4.95) {
			
			if(pw < 1.65) {
			
				return 'v';
			
			}
			
			else {
			
				return 'V';
			
			}
		
		}
		
		else {
		
			return 'V';
		
		}
	
	
	}
	
	else {
	
		return 'V';
	
	
	}



}

char dt1b(double pl, double pw, double sl, double sw) {

	if(pl < 2.55) {
		
		return 'S';
	
	
	}
	
	else if(pw < 1.69) {
	
		if(pl < 4.85) {
		
			return 'v';			/* Again as it's in the pdf*/

		
		
		}
		
		else {
		
			return 'V';
		
		}
		
		
		
	
	
	}
	
	
	else {
	
		return  'V';
	
	}



}







double dt2a(double x1, double x2, double x3, int x4, int x5) {

	if(x1 < 31.5) {
	
		if(x2 > 2.5) {
		
			return 5.0;
		
		
		}
		
		else if(x2 - 0.1 <= x1 && x1 <= x2 + 0.1) {
		
			return 2.1;
		
		}
		
		else {
		
			return -1.1;
		
		}
	
	
	
	
	}
	
	else if(-1 <= x3 && x3 <= 2) {
	
		return 1.4;
	
	
	
	}
	
	else if(x4 && x5) {						/*As it's in the pdf */
	
		return -2.23;
	
	
	}
	
	else {
	
	
		return 11.0;
	
	}
	



}
	



double dt2b(double x1, double x2, double x3, int x4, int x5) {


	if(x1 > 12 && x1 < 22) {
	
		if(x3 > 5/3) {
		
			return -2.0;
		
		
		}
		
		else if(x1 -0.1 <= x3 && x3 <= x1 + 0.1) {
		
			return  1.01;
		
		
		}
		
		else {
		
			return -8;
		
		}
	
	}
	
	else if(x4 && x5) {
	
		return -1;
	
	
	
	}
	
	
	else if(x2 >= -1 && x2 <= 2) {
	
		
		return -1/7;
	
	}
	
	else {
	
	
		return SQRT_2/3;				/* I have used a macro for a near value for square root of 2. I don't want to add a library */
	
	}



}


double dt3a(double height, double salary, int rebound, int gender, int point) {			/* The function I implement for a player rating*/

	
	double rating = 0.0067;							/* Neutral or starting rating*/
	
	
	
	if(gender == 0) {						/* First check the gender*/
	
		
		if(height > 1.88) {						/* If the height is bigger I expect more rebounds and less points*/
		
			if(salary > 0.150) {
			
				if(rebound + point > 18 || rebound > 5) {
				
					
					rating += 0.0009;			/* Adding or cutting from the starting value*/
				
				
				}
				
				if(rebound + point < 7 || rebound < 2) {
				
					rating -= 0.0012;
				
				
				}
			
			
			}
			
			
			else if(salary > 0.083) {						/* Salary is an important factor, there are 3 categories*/
			
				if(rebound + point > 12 || rebound > 4) {
				
					
					rating += 0.0011;
				
				
				}
				
				if(rebound + point < 7 || rebound < 3) {
				
					rating -= 0.0008;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 8 || rebound > 3) {
				
					
					rating += 0.0012;
				
				
				}
				
				if(rebound + point < 7 || rebound < 2) {
				
					rating -= 0.0006;
			
			
			}
		
		
		}
			
	
	}
	
	
	else {	
	
	
		if(salary > 0.165) {									/*The more the salary the more the expectations */
			
				if(rebound + point > 22 || point > 18) {
				
					
					rating += 0.0016;
				
				
				}
				
				if(rebound + point < 13 || point < 11) {
				
					rating -= 0.0018;
				
				
				}
			
			
			}
			
			
			else if(salary > 0.092) {
			
				if(rebound + point > 17 || point > 14) {
				
					
					rating += 0.0013;
				
				
				}
				
				if(rebound + point < 10 || point < 8) {
				
					rating -= 0.0007;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 13 || point > 11) {
				
					
					rating += 0.0019;
				
				
				}
				
				if(rebound + point < 8 || point < 7) {
				
					rating -= 0.0012;
			
			
			}
		
		
		}
			
	
	
	}
	
	} 
	
	else if(gender == 1) {
	
		if(height > 1.96) {						/* There is a gap in terms of height between man and woman*/
		
			if(salary > 20.342) {						/* A huge gap in terms of salary*/
			
				if(rebound + point > 25 || rebound > 7) {
				
					
					rating += 0.0018;
				
				
				}
				
				if(rebound + point < 13 || rebound < 4) {
				
					rating -= 0.0022;
				
				
				}
			
			
			}
			
			
			else if(salary > 13.768) {
			
				if(rebound + point > 17 || rebound > 6) {
				
					
					rating += 0.0013;
				
				
				}
				
				if(rebound + point < 11 || rebound < 5) {
				
					rating -= 0.0015;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 11 || rebound > 5) {
				
					
					rating += 0.0019;
				
				
				}
				
				if(rebound + point < 7 || rebound < 3) {
				
					rating -= 0.0011;
			
			
			}
		
		
		}
			
	
	}
	
	
	else {
	
	
		if(salary > 28.372) {					/* If the height is low I expect more points*/
			
				if(rebound + point > 32 || point > 28) {
				
					
					rating += 0.0031;
				
				
				}
				
				if(rebound + point < 21 || point < 18) {
				
					rating -= 0.0044;
				
				
				}
			
			
			}
			
			
			else if(salary > 17.419) {
			
				if(rebound + point > 25 || point > 21) {
				
					
					rating += 0.0034;
				
				
				}
				
				if(rebound + point < 17 || point < 14) {
				
					rating -= 0.0028;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 19 || point > 15) {
				
					
					rating += 0.0051;
				
				
				}
				
				if(rebound + point < 13 || point < 10) {
				
					rating -= 0.0055;
			
			
			}
		
		
		}
			
	
	
	}
	
		
	
	}


	return rating;			/*Return the double value */


}






double dt3b(double height, double salary, int rebound, int gender, int point) {



	
	double rating = 0.0071;				/*A different way to determine rating */
	
	
	
	if(gender == 0) {
	
		
		if(height > 1.84) {
		
			if(salary > 0.142) {
			
				if(rebound + point > 15 && rebound > 6) {			/* Strict in both cases, requires and operator*/
				
					
					rating += 0.0007;
				
				
				}
				
				if(rebound + point < 10 && rebound < 3) {
				
					rating -= 0.0016;
				
				
				}							/* But the story is similar, add or drop from the first rating */
			
			
			}
			
			
			else if(salary > 0.077) {
			
				if(rebound + point > 12 && rebound > 4) {
				
					
					rating += 0.0017;
				
				
				}
				
				if(rebound + point < 7 && rebound < 3) {
				
					rating -= 0.0004;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound > 3) {
				
					
					rating += 0.0012;
				
				
				}
				
				if(rebound < 2) {
				
					rating -= 0.0006;
			
			
			}
		
		
		}
			
	
	}
	
	
	else {
	
	
		if(salary > 0.165) {
			
				if(point > 19) {
				
					
					rating += 0.0016;
				
				
				}
				
				if(rebound + point < 13 && point < 11) {
				
					rating -= 0.0018;
				
				
				}
			
			
			}
			
			
			else if(salary > 0.092) {
			
				if (point > 14) {
				
					
					rating += 0.0013;
				
				
				}
				
				if(rebound + point < 10 && point < 8) {
				
					rating -= 0.0007;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 13 && point > 11) {
				
					
					rating += 0.0019;
				
				
				}
				
				if(rebound + point < 8 && point < 7) {
				
					rating -= 0.0012;
			
			
			}
		
		
		}
			
	
	
	}
	
	} 
	
	else if(gender == 1) {
	
		if(height > 1.96) {
		
			if(salary > 20.342) {
			
				if(rebound + point > 25) {
				
					
					rating += 0.0018;
					
					if(rebound > 8) {
						rating += 0.0019;
						}
				
				
				}
				
				if(rebound + point < 13 && rebound < 4) {
				
					rating -= 0.0022;
				
				
				}
			
			
			}
			
			
			else if(salary > 13.768) {
			
				if(rebound + point > 17 && rebound > 6) {
				
					
					rating += 0.0013;
				
				
				}
				
				if(rebound + point < 11 && rebound < 5) {
				
					rating -= 0.0015;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 19 && rebound > 4) {
				
					
					rating += 0.0021;
				
				
				}
				
				if(rebound + point < 7 && rebound < 3) {
				
					rating -= 0.0014;
			
			
			}
		
		
		}
			
	
	}
	
	
	else {
	
	
		if(salary > 28.372) {
			
				if(rebound + point > 29 && point > 25) {
				
					
					rating += 0.0031;
				
				
				}
				
				if(rebound + point < 21 && point < 18) {
				
					rating -= 0.0044;
				
				
				}
			
			
			}
			
			
			else if(salary > 17.419) {
			
				if(rebound + point > 25 && point > 21) {
				
					
					rating += 0.0034;
				
				
				}
				
				if(rebound + point < 17 && point < 14) {
				
					rating -= 0.0028;
				
				
				}
			
			
			}
			
			
			else {
			
				if(rebound + point > 16 && point > 13) {
	
					
					rating += 0.0051;
				
				
				}
				
				if(rebound + point < 13 && point < 10) {
				
					rating -= 0.0055;
			
			
			}
		
		
		}
			
	
	
	}
	
		
	
	}


	return rating;


}



