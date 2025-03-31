// Balconies
//
// You are trying to determine which of two apartments has a larger balcony. Both balconies are rectangles, and you have the length and width, but you need the area.
// 
// Task 
// Evaluate the area of two different balconies and determine which one is bigger.
//
// Input Format 
// Your inputs are two strings where the measurements for height and width are separated by a comma. The first one represents apartment A, the second represents apartment B.
//
// Output Format:
// A string that says whether apartment A or apartment B has a larger balcony.
//
// Sample Input 
// '5,5'
// '2,10'
//
// Sample Output 
// Apartment A


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int apartASize[2];
int apartBSize[2];

void input(char* input)
{
	fgets(input, sizeof(input), stdin);	
}

void removeChar(char* input)
{
	int i, j = 0;

	for (i = 0; input[i]; i++) 
	{
		if (input[i] != '\'')
		{
			input[j++] = input[i];	
		}
	}

	input[j] = '\0';
}

void storeToArr(char* input, int* output)
{
	int count = 0;	
	char* token = strtok(input, ",");

	while (token != NULL && count < 2) 
	{
		output[count] = atoi(token);
		count++;
		token = strtok(NULL, ",");
	}

}

int calculateArea(int* size)
{
	int area = 1;

	for (int i = 0; i < 2; i++)
	{
		area *= size[i];	
	}

	return area;
}

int main()
{
	char apartA[10];
	char apartB[10];

	int areaA, areaB = 0;

	input(apartA);
	input(apartB);

	removeChar(apartA);
	removeChar(apartB);

	storeToArr(apartA, apartASize);
	storeToArr(apartB, apartBSize);

	areaA = calculateArea(apartASize);
	areaB = calculateArea(apartBSize);

	if (areaA > areaB)
	{
		printf("Apartment A");
	}
	else
       	{
		printf("Apartment B");	
	}


	return 0;
}
