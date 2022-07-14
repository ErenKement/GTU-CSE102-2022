#include "util.h"				//I have defined headers and macros in the util.h file



/*




*/


/*
	A recursive function which calls itself by incrementing currentlen by 1
	
	mathfunc is written by me
	
	This function fills the seq array



*/



void generate_sequence (int xs, int currentlen, int seqlen, int *seq) {


	
	
	
	
	
	if(currentlen == seqlen)
		return;
		
	else {
	
		seq[currentlen] = xs;
		mathfunc(&xs);
		generate_sequence(xs, currentlen + 1, seqlen, seq);
		
	
	
	
	}





}


	/*

	This function calculates the input for odd and even numbers. 





*/



void mathfunc(int *inp) {

	if(*inp % 2 == 1) {
	
		 *inp = 3 * *inp + 1;
	
	
	}

	else {
	
		*inp /= 2;
	
	
	}

}


/*

	Divide 2 the meaningful part
	
	Number of elements are the same if last elements are also same so there's a loop



	at first, found stores the first encounter with a core loop member. In that way, the part until the core element of the loop becomes out of my consideration
	
	but the found will be modified
	
	total is for all number of 'meaningful' elements
	
	I mean by meaningful is core elements; 4, 2, 1
	
	total and check are static in order to preserve their values



	This function decides starting and ending point of the loop's first part
	
	And fill le and ls values




*/




int has_loop(int *arr, int n, int looplen, int *ls, int *le){

	int i, j, k, mid;

	static int total;	
	
	
	int found;
	static int check = 0;
	
	
	
	printf("Checking if there is a loop of length %d...\n", looplen);
	
	for(j = 0; j < n; j++) {
	
			if(arr[j] == CORE1 || arr[j] == CORE2 || arr[j] == CORE3) {
			
			
				found = j; 					//Store the index of the first encounter
			
				break;
			
			
				}
			
		
	
	
		}
	
	
	
	if(looplen == (n / 2)) {		// Calculates total only once
	
		
	
		total = n - found;
	
	
	
	}
	
	
	if(total % 2 == 1) {  //If total is odd we can ignore the first integer
	
		found += 1;
	
	}
	
	
	
	if(check != 0) {
	
	found = n - looplen * 2;			//We check the for looplen. So it's good to modify found backwards. Only if check is not zero!
	
	
	}
	
	
	
	
	
	
	
	
	
	
	
	if(looplen > (total / 2)) {		//total/2 is the possible maximum value for looplen. Ignore others
	
	
		
	
		return 0;
	
	
	}
	
	
	
	
	
	
	
	mid = (found + n-1) / 2;		//Mid is the last element of the first part 
	
	
	
	
	
	
	
	
	
	
	
	
	if(arr[mid] == arr[n-1]) {			//Number of elements are the same if last elements are also same so there's a loop
	
		*ls = found;
		*le = mid; 
		
		
		
		
		
		
		
		return 1;	
	}
	
	
	
	
	
	else {
		
		check++;  		//If it reaches there so it's in the possible range. Modify the found at the next call
	
		
		return 0;
	
	
		
	
	
	
	
	
	}	
	
	
	
	
	
	


}


/*


	A recursive function that calls two functions: generate_sequence and has_loop
	
	


	It fills the loop array
	
	



*/



void check_loop_iterative(void (*f)(int xsc, int currentlen, int seqlenc, int *seq), int xs, int seqlen, int *loop, int *looplen) {

	static int genseq = 0; 
	
	int ls = 0, le = 0;
	int lenlenlen = *looplen;				//to store value of the looplen variables
	int cur = 0, *sequence;
	sequence = (int *) malloc(seqlen * sizeof(int));		//memory allocation
	int y, i, j;
	int result = 0;	
	

	
	(*f)(xs, cur, seqlen, sequence);			//function pointer
	
	if(genseq == 0) {
	
		genseq++;

		printf("Sequence:{");
	
	
	
		for(y=0;y<seqlen - 1;y++){			//Prints the sequence
		
			printf("%d, ", sequence[y]);
		}
	
	
	
	
	
	
		printf("%d}\n\n", sequence[y]);
	



	}
	
	
	
	
	
	
	if(lenlenlen < 2 ) 		//There's no loop shorter than 2
		return;
		
	
	result = has_loop(sequence, seqlen, lenlenlen, &ls, &le);  //call has_loop and store it's return value
	
	
	
	
	
	if(result == 0 && lenlenlen>1){   //Recursive part
	
		--(*looplen);
	
	
		check_loop_iterative(generate_sequence, xs, seqlen, loop, looplen);
	
	
	
	}
	

	else if(result == 1) {		//Recursion base 1
	
		printf("\nLoop detected with a length of %d.\n", le - ls + 1);
		
		printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n", ls, le);
		
		for(i = le+1, j = 0; i <= ls+1, j < lenlenlen; i++, j++) {
		
			loop[j] = sequence[i];
			
		
		}
		
		
	
	
	}	
	
	
	else if(result == 0 && lenlenlen < 2) {  //Recursion base 2
		
		
		return;
	
	
	}
	
	
	
	
	free(sequence);  //free the space
	
	return;




}



/*


	It calls itself by incremeting digit variable by 1
	
	It fills h array





*/


void hist_of_firstdigits(void (*f)(int xsc, int currentlen, int seqlenc, int *seq), int xs, int seqlen, int *h, int digit){


	int clen = 0, i;
	int *sequenceh;
	sequenceh = (int *) malloc(seqlen * sizeof(int));
	int firstdigit;
	
	(*f)(xs, clen, seqlen, sequenceh);


	if(digit > 0 && digit < 10) { 			// Digit variable must be in that range
	
		for(i = 0; i < seqlen; ++i) {
		
			firstdigit = sequenceh[i];			//Finding first digit
			
			while(firstdigit > 9) {
			
				firstdigit /= 10;
			
			
			}
			
			
			if(firstdigit == digit) {		//Fills the array if there's a match
			
				++h[digit - 1];
			
			
			}
			
		
		
		}
		
		
		hist_of_firstdigits(generate_sequence, xs, seqlen, h, digit+1);




	}



	else if(digit > 9){  //When digit exceeds the range

	free(sequenceh);
	
	return;
	
	}
	
	
	
	
	
	
	
}


