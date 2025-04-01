// Number of Ones
//
//Task:
// Count the number of ones in the binary representation of a given integer.
//
// Input Format:
// An integer.
//
// Output Format: 
// An integer representing the count of ones in the binary representation of the input.
//
// Sample Input:
// 9
//
// Sample Output:
// 2
//
// Explanation: 
// The binary representation of 9 is 1001, which includes 2 ones.
//
// 
// WTF is binary?
// Binary is the another number format. It is base two number, unlike the usual base 10 numbers that we use in daily life.
// Here's a simple conversion trick to convert for base ten numbers to base two.
//
// 	Base ten	->	Base two
// 	0			0
// 	1			1
// 	2			10		(10^1)
// 	3			11
// 	4			100		(10^2)
// 	5			101
// 	6			110
// 	7			111
// 	8			1000		(10^3)
// 	9			1001
// 	.			.
// 	.			.
// 	.			.
//
// Starting to see the pattern now?
//
//
// What if the nubmers are more than that?
//
// Ex. 45 to bianry.
//
// 	What we'll do is we will divide the number by two until it cannot be divided futher,
// 	and take its remainder to be a bianry, by ordering from last to first.
//
// 	45 / 2 = 22 remainder 1     ^
// 	22 / 2 = 11 "-------" 0     |
// 	11 / 2 =  5 "-------" 1     |
// 	 5 / 2 =  2 "-------" 1     |
// 	 2 / 2 =  1 "-------" 0	    |
//       1 / 2 =  0 "-------" 1	    | 	 (end it here, because the quotient is 0)
//
//       The binary form of 45 is 101101.


#include <stdio.h>

void toBinary(int base_ten)
{
	int binary_reversed = 0;

	while (base_ten != 0) 
	{
		binary_reversed = base_ten % 2;
		base_ten /= 2;
		printf("%d", binary_reversed);		
	}	
}

int main()
{
	int input = 0;

	scanf("%d", &input);
	toBinary(input);
	
	return 0;
}

