//CSCI 115 Project Part 2: Two Sum

#include <iostream>

using namespace std;

void genValid2Sum(int s[], int indexOfSol1, int indexOfSol2, int input, int size)
{
	//input = the number x that we are trying to find numbers to sum up to it
	//x = solution1, y = solution2
	int x = (input / 2) + 1;
	int y = input - x;
	cout << x << " " << y;
	srand(time(0));

	cout << "2sum array: ";
	//indexOfSol1/indexOfSol2 = index(s) of where you want to put the solutions
	for (int i = 0; i < size; i++)
	{
		if (i == indexOfSol1)
		{
			s[indexOfSol1] = x;
		}
		else if (i == indexOfSol2)
		{
			s[indexOfSol2] = y;
		}
		else
		{
			s[i] = rand() % size;
		}
		cout << s[i] << " ";
	}
}



int main()
{
	int s[1000];

	//-----inputs-----
	//1st: s is the 2sum array
	//2nd: index of first solution
	//3rd: index of 2nd solution
	//4th: number x for which we are finding the numbers that sum up to it
	//5th: size of 2sum array
	genValid2Sum(s, 20, 995, 234, 1000);

	return 0;
}