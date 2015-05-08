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

	std::cout << "Enter a sentence and watch it encode!" << std::endl;
	
	std::getline(std::cin, input);

	clock_t pStart = clock();

	for (int i = 0; i < input.length(); i++)
	{
		printf("%c", input[i]);
		if (std::binary_search(vowels.begin(), vowels.end(), input[i]) == false && isalpha(input[i]))
		{
			printf("o%c", tolower(input[i]));
		}
	}
	std::cout << std::endl;
	printf("Time taken: %.5fs\n", (double)(clock() - pStart) / CLOCKS_PER_SEC);

	system("pause");
	
	return 0;
}