#include <stdio.h>


				/*Eren Kement 1801042096 */
				
				


void draw();

int fux(int);

int neg(int );                                                  /*Function prototypes */ 
								 
void red () {
  printf("\033[1;31m");               			 /* For the colors*/
}
void yellow () {
  printf("\033[1;33m");
}
void reset () {
  printf("\033[0m");
}

void graph();


int main() {

	int a, b, c, select;
	
	

	
	
	
	
	
	
	do {				 /* Infinite loop until selection of '4' bu the user*/
	
	
	printf("Select an operation...\n1 -> Enter the coefficients.\n2 -> Draw the graph.\n3 -> Print the graph into a .txt file.\n4 -> Exit\n\nChoice: ");
	scanf("%d", &select);
	printf("\n\n");
	
	if(select < 1 || select > 4) {
	
		printf("Please enter a valid input!\n\n");						 /*when the input is not valid */
		continue;
	
	
	
	}
	
	else if(select == 1) {
	
		FILE *fp = fopen("coefficients.txt", "w");												 /*Open or create the file to write*/
	
		printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y+ c\n");
		
		printf("a: ");
		scanf("%d", &a);
		printf("\n");
		
		printf("b: ");
		scanf("%d", &b);
		printf("\n");
		
		printf("c: ");
		scanf("%d", &c);
		printf("\n\n");
	
		fprintf(fp, "%d\n%d\n%d", a, b, c);
		
		fclose(fp);
		
		printf("coefficients.txt has been created.");
		
		printf("\n\n");
	
	}
	
	else if(select == 2) {
	
			
	
	
		draw();
		printf("\n\n");
	}
	
	else if(select == 3) {
	
	
		graph();
		printf("\n\n");
	
	
	}
	
	else if(select == 4) {
	
		printf("The program will stop!\n");
		printf("\n\n");
	
	}
	
	
	
	
	
	
	}while(select != 4);	
	
	
	
	return 0;
	
	
	


}



void draw() {					 /*There's a problem with my functions about relocating the numbers. Doesn't relocate just not print the number at all*/

	int a, b, c;
	
	
	
	FILE *fp = fopen("coefficients.txt", "r");
	
	if( fp != NULL) {									 /* If there's a file for us to read. Its purpose is to avoid segmentation fault*/
	
	fscanf(fp, "%d %d %d", &a, &b, &c);
	
	
	printf("Coefficients has been read from the coefficients.txt file.\nPrinting the graph of x = %d*(y*y) + %d*y + %d\n\n", a, b, c);
	
	
	
	int x, y, hat = -56;				 /* hat variable is for the symbol at the end of the axises */
	
	
	
	while(hat != 0) {
	
		printf(" ");									 /* Printing space until reach the point*/
		hat++;
	
	}
	
	yellow();
	
	printf("^\n");											 /* Prints a yellow hat*/
	
	reset();
	
	
	
	
	
	for(y = 16; y >= -16; y--) {							 /* Nested for loops to scan all the coordinate plane*/
	
	
		for(x = -56; x <= 56; x++) {
		
		if(x == -56 && y == 0) {
			
			yellow();
			
			printf("<");				/* Left hat*/
			
			reset(); 
			
			
			
			}
			
		
			
		
	if(x == a * (y * y) + b * y + c) {						 /*Prints dash when the point is on the function graph*/
		
		red();
		
		printf("#");
		
		reset();
	}
	
	else if(x == 0) {						 /* x = 0, y axis*/
		
		yellow();
		
		printf("|"); 			
		
		reset();
		}
		
		
	
	
	
	else if(y == 0) {
	
		if(x == -55)
			printf("\b");				/* Remove the unnecesseray one*/
			
			
		yellow();
		
		printf("-");						/* y = 0, x axis*/
		
		reset();
		
		if( x == 56) {
			
			yellow();
			printf(">"); 					/* Right hat*/
			reset();
			
			}
		
	
	}
	
	/* A complicated if statement. It doesn't work as I intend. To write numbers there mustn't be a dash. I tried to check the digits including minus sign*/
	
	else if((x == -2 && y % 5 == 0 && (x != a * (y * y) + b * y + c -1)) && (fux(y) == 2 ? x != a * (y * y) + b * y + c: 1) && (fux(y) == 3 ? x != a * (y * y) + b * y + c + 1: 1) ) {
		
		
		for(int i = 0; i < fux(y) - 1; i++) {
		
		
		
			printf("\b");          
		
		
			
		}	
		
		
		printf("%d", y);
		
	}
	

	
	
	
	
	
	else if(x == -1 && y == -1) {			/* Print 0 for the origin*/
	
		printf("%d", 0);
	
	}
		
	/* This if statement works better than the one for y axis. Doesn't print the number if there's a dash encountered. neg checks the negativity for number of digits*/		
			
	else if(y == -1 && x % 10 == 0 && x != a * (y * y) + b * y + c + 1 && (neg(y) == -1 ? x != a * (y * y) + b * y + c + 2: 1)) {  		

	
		
		
		for(int i = 0; i < fux(x) - 1; i++) {
		
		printf("\b");
		}
		
		
		
		
		printf("%d", x);
		
		
		
		
		
		
	}
	
	
	
	
	
	else
		printf(" ");				/* Else to all the if's. Just prints space*/
		
	
	
	//
	
	
	
		
		}
		
		printf("\n");				/*Newline */
		
		}
		
		hat = -56;				/* For the hat down the y axis*/
		
		while(hat != 0) {
	
			printf(" ");
			hat++;
	
	
	}
	
	yellow();
	
	printf("v\n");
	
	reset();


		fclose(fp);				/*Close the file */
		
		
		}
		
	else {
	
		printf("There is no coefficients.txt file\n\n");			/*If there's not a coefficients.txt file */
	
	}

}

int fux(int number) {					/*Calculates number of digits */

	int counter = 0, n = number;
	if(n < 0)
		counter++;
		
		
	while(n != 0) {
	
		n /= 10;
		counter++;
	
	
	}
	
	return counter;


}


int neg(int n) {					/* Check for negativity*/


	if(n < 0)
		return -1;
	else if(n > 0)
		return 1;




}



void graph() {							/* Drawing graph to the txt file without colors and numbers*/

	int a, b, c, x, y, hat = -56;					/* The same algorithm besides those two*/
	
	FILE *fptr = fopen("graph.txt", "w");
	FILE *fp = fopen("coefficients.txt", "r");				/* Open the files*/
	
	fscanf(fp, "%d %d %d", &a, &b, &c);
	
	printf("Coefficients has been read from the coefficient file\nThe graph of x=%d*(y*y) + %d*y + %d\n\n", a, b, c);
	
	
	
	
	while(hat != 0) {
	
		fprintf(fptr, " ");				/* have to use fprintf*/
		hat++;
	
	}
	
	fprintf(fptr, "^\n");
	
	
	
	
	
	for(y = 16; y >= -16; y--) {
	
	
		for(x = -56; x <= 56; x++) {
		
		if(x == -56 && y == 0) {
			fprintf(fptr, "<"); 
			
			
			
			}
			
		
			
		
	if(x == a * (y * y) + b * y + c) {
		
		
		
		fprintf(fptr,"#");					/* Other conditions are the same*/
		
		
	}
	
	else if(x == 0) {
		
		
		
		fprintf(fptr,"|"); 
		
		
		}
		
		
	
	
	
	else if(y == 0) {
	
		
	
		
		
		
		
		
		
		if( x == 56) {
			
			
			fprintf(fptr,">"); 
			
			
			}
			
		else if(x != -56) {
		
			fprintf(fptr,"-");
		
		}
		
	
	}
	
	
	
	
	
	
	
	
	
	
	
	else
		fprintf(fptr," ");
		
	
	
	
	
	
		
		}
		
		fprintf(fptr,"\n");
		
		}
		
		hat = -56;
		
		while(hat != 0) {
	
			fprintf(fptr," ");
			hat++;
	
	
	}
	
	fprintf(fptr,"v\n");
	


	fclose(fptr);
	fclose(fp);

}

