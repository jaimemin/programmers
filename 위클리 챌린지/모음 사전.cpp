#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
vector<string> dictionary;

void func(string word, int wordLength)
{
	if (wordLength == word.length())
	{
		dictionary.push_back(word);

		return;
	}

	for (char vowel : vowels)
	{
		func(word + vowel, wordLength);
	}
}

int solution(string word) {
	for (int len = 1; len <= 5; len++)
	{
		string word = "";

		func(word, len);
	}

	sort(dictionary.begin(), dictionary.end());

	for (int i = 0; i < dictionary.size(); i++)
	{
		if (word == dictionary[i])
		{
			return i + 1;
		}
	}
}

int main(void)
{
	cout << solution("I") << "\n";
	
	return 0;
}