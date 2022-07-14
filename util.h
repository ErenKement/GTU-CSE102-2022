#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>
#include <stdlib.h>
#define CORE1	4			//CORE stands for elements of the minimum length loop 
#define CORE2	2
#define CORE3	1



void generate_sequence (int xs, int currentlen, int seqlen, int *seq); 											//rec
void check_loop_iterative(void (*f)(int xsc, int currentlen, int seqlenc, int *seq), int xs, int seqlen, int *loop, int *looplen); 				//rec
int has_loop(int *arr, int n, int looplen, int *ls, int *le);												//not rec
void hist_of_firstdigits(void (*f)(int xsc, int currentlen, int seqlenc, int *seq), int xs, int seqlen, int *h, int digit);					//rec

void mathfunc(int *inp);


#endif
