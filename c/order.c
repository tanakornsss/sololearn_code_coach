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
	const char input[32];
	const char output_buff[4][32];

	int count = 0;
	char* token;
	
	// To compare with.
	char order[5][32] = 
	{
		"Nachos", "Pizza", "Cheeseburger", "Water", "Coke"
	};
	
	// Prices of the stuff.
	int prices[5] = {6, 6, 10, 4, 5};

	// To get strings include space.
	fgets(input, sizeof(input), stdin);
	
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

	for (int i = 0; i < count; i++)
	{
		printf("Word %d: %s\n", i + 1, output_buff[i]);
	}

	return 0;
}
