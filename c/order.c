// Food order.
//
// You and three friends go to a baseball game and you offer to go to the concession stand for everyone.
// They each order one thing, and you do as well. 
//
// Nachos and Pizza both cost $6.00. A Cheeseburger meal costs $10. Water is $4.00 and Coke is $5.00. Tax is 7%.
//
// Task 
// Determine the total cost of ordering four items from the concession stand. If one of your friend’s orders something that isn't on the menu, you will order a Coke for them instead.
//
// Input Format
// You are given a string of the four items that you've been asked to order that are separated by spaces.
//
// Output Format 
// You will output a number of the total cost of the food and drinks.
//
// Sample Input 
// 'Pizza Cheeseburger Water Popcorn'
// 
// Sample Output 
// 26.75
//
// Explanation
// Because Popcorn is not on the menu, this friend gets a coke which brings the subtotal to $25.00 and $26.75 with tax.


#include <stdio.h>
#include <string.h>

int main()
{
	const int max_words = 4;

	// This is a tax percent, represented as 7/100 = 0.07 = 7%
	// We gonna be adding 1 later on, cause the total include tax will be 1.07 = 107%
	const double tax_percent = 0.07;
	
	// Don't make the mistake that setting the char array TOO LOW.
	// This may result it the text getting cutted of and ruin the program.
	char input[100];

	char output_buff[4][32];
	char* token;

	double total_no_tax = 0.0;
	double total = 0.0;

	int count =  0;
	
	// To compare with.
	char order[5][32] = 
	{
		"Nachos", "Pizza", "Cheeseburger", "Water", "Coke"
	};
	
	// Prices of the stuff.
	int prices[5] = {6, 6, 10, 4, 5};

	// To get strings include space.
	fgets(input, sizeof(input), stdin);

	// Remove \n out.
	input[strcspn(input, "\n")] = 0;
	
	// For strtok() "Separating spaces."
	token = strtok(input, " ");

	while (token != NULL && count < max_words)
	{
		// Copy string from token -> output_buff[count]
		strcpy(output_buff[count], token);

		count++;

		// End copying strings.
		token = strtok(NULL, " ");
	}
	
	// The found int must be added, 
	// or else it will stuck in loop and number will be messed up.
	for (int i = 0; i < max_words; i++)
	{
		int found = 0;

		for (int j = 0; j < 5; j++)
		{
			// Use strcmp() to compare strings.
			// Don't compare them directly output_buff[] is a pointer,
			// but order[] IS NOT, so this if statement will be ignored.
			if (strcmp(output_buff[i], order[j]) == 0)
			{
				found = 1;
				total_no_tax += prices[j];
				break;	
			}
		}

		if (!found)
		{	
			total_no_tax += prices[4];	
		}
	}

	total = total_no_tax * (1.0 + tax_percent);

	// Make the output be the float in two digits.	
	printf("%.2f\n", total);

	return 0;
}
