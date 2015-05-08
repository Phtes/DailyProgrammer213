#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	// value maps
	char vowel[12] { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' }; //binary search match map
	std::vector<char> vowels(vowel, vowel+12); // allocate mem
	std::sort(vowels.begin(), vowels.end()); // prep map for binary search
	std::string input;
	std::string finalOutput;

	std::cout << "Enter a sentence and watch it encode!" << std::endl;
	
	std::getline(std::cin, input); // Get entire line as input

	clock_t pStart = clock();
	// Pass input to function that checks for consonants and adds to the string
		for (int i = 0; i < input.length(); i++)
		{
			
			if (std::binary_search(vowels.begin(), vowels.end(), input[i]) == true && isalpha(input[i]) && input[i] != input[i+1])
			{
				std::cout << "found" << std::endl;
				finalOutput.push_back(input[i]);
			}
			else
			{
				std::cout << "Not found" << std::endl;
				finalOutput.push_back(input[i]);
				finalOutput.push_back('o');
				finalOutput.push_back(tolower(input[i]));
			}
		}

	std::cout << finalOutput << std::endl;

	printf("Time taken: %.5fs\n", (double)(clock() - pStart) / CLOCKS_PER_SEC);

	system("pause");
	// return string
	
	
	return 0;
}