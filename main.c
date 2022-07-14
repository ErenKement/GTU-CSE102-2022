#include "util.h" 				//I have defined headers and macros in the util.h file

/*


	EREN KEMENT 1801042096
	
	HW8


*/




int main() {

	int leng, first, i, j, *loop, looplen, *h, digit = 1;
	
	

	
	
	
	printf("Please enter the sequence length: ");
	scanf("%d", &leng);
	
	
	looplen = leng / 2;						//Maximum possible length of the loop
	
	
	
	loop = (int *) malloc(looplen * sizeof(int));
	
	h = (int *) malloc(9 * sizeof(int));			//Allocating memory for loop and h pointers
	
	
	
	printf("Please enter the first element: ");	
	scanf("%d", &first);
	printf("\n");
	
	
	check_loop_iterative(generate_sequence, first, leng, loop, &looplen);
	
	
	if(loop[0] == 0) {						//There may be an assignment to loop, to avoid it I have used if as this 
	
		printf("No loop found.");
	
	}
	
	else {
		
		
		
		
	
		
		
		printf("Loop: {");				//Printing loop 
		
		for(i = 0; i < looplen - 1; i++) {
		
			printf("%d, ", loop[i]);
		
		}
	
		printf("%d}", loop[(looplen -1)]);
	}
	
	
	hist_of_firstdigits(generate_sequence, first, leng, h, digit);
		
		
	printf("\n\nHistogram of the sequence: {");
								//Printing histogram
	for(j = 0; j < 8; j++) {
	
		printf("%d, ", h[j]);
	
	}	
	
		printf("%d}\n", h[8]);
	
		
	
	
	
	free(loop);
	
							//Freeing the memory space. It's an important practice.
	free(h);
	
	


	return 0;

}
