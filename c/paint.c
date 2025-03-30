// Paint costs
//
// You are getting ready to paint a piece of art. The canvas and brushes that you want to use will cost 40.00. Each color of paint that you buy is an additional 5.00. 
// Determine how much money you will need based on the number of colors that you want to buy if tax at this store is 10%.
// 
// Task 
// Given the total number of colors of paint that you need, calculate and output the total cost of your project rounded up to the nearest whole number.
// 
// Input Format 
// An integer that represents the number of colors that you want to purchase for your project.
//
// Output Format 
// A number that represents the cost of your purchase rounded up to the nearest whole number.
//
// Sample Input 
// 10
//
// Sample Output 
// 99
//
// Explanation 
// You need 50.00 to buy 10 colors of paint + 40.00 for the canvas and brushes + 9.00 for the tax.

#include <stdio.h>

int main()
{
	const double canvas_cost = 40.00;
	const double paint_cost = 5.00;
	const double tax_percent = 0.1;

	int paints;
	scanf("%d", &paints);

	double total_no_tax = canvas_cost + (paint_cost * paints);
	double total = total_no_tax * (1.0 + tax_percent);

	printf("%.0f", total);

	return 0;
}
