#include <string>
#include <vector>
#include <iostream>
using namespace std;

const char INIT_CHAR = '@';

const int ALPHABET_MAX = 26;

const string INVALID = "invalid";

bool isUpper(char c)
{
	return c >= 'A' && c <= 'Z';
}

bool isLower(char c)
{
	return c >= 'a' && c <= 'z';
}

bool isLastChar(int i, string &sentence)
{
	return i == sentence.length() - 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	bool visited[ALPHABET_MAX] = { false, };
	bool isRuleOne = false, isRuleTwo = false;
	char ruleOneChar = INIT_CHAR, ruleTwoChar = INIT_CHAR;
	vector<string> words;
	string temp = "";

	for (int i = 0; i < sentence.length(); i++)
	{
		// 규칙1 && 규칙2
		if (isRuleOne && isRuleTwo)
		{
			if (isUpper(sentence[i]))
			{
				temp += sentence[i];

				if (isLastChar(i, sentence)
					|| isUpper(sentence[i + 1])
					|| (ruleOneChar != sentence[i + 1] && ruleTwoChar != sentence[i + 1]))
				{
					return INVALID;
				}
			}

			if (isLower(sentence[i]))
			{
				if (ruleTwoChar == sentence[i])
				{
					isRuleOne = false;
					visited[ruleOneChar - 'a'] = true;
					ruleOneChar = INIT_CHAR;

					isRuleTwo = false;
					visited[ruleTwoChar - 'a'] = true;
					ruleTwoChar = INIT_CHAR;

					words.push_back(temp);
					temp = "";

					continue;
				}

				if (isLastChar(i, sentence)
					|| isLower(sentence[i + 1]))
				{
					return INVALID;
				}
			}
		}
		// 규칙 1
		else if (isRuleOne)
		{
			if (isUpper(sentence[i]))
			{
				temp += sentence[i];

				if (isLastChar(i, sentence)
					|| isUpper(sentence[i + 1])
					|| ruleOneChar != sentence[i + 1])
				{
					isRuleOne = false;
					visited[ruleOneChar - 'a'] = true;
					ruleOneChar = INIT_CHAR;

					words.push_back(temp);
					temp = "";
				}
			}

			if (isLower(sentence[i]))
			{
				if (isLastChar(i, sentence)
					|| isLower(sentence[i + 1]))
				{
					return INVALID;
				}
			}
		}
		// 규칙 2
		else if (isRuleTwo)
		{
			if (isUpper(sentence[i]))
			{
				temp += sentence[i];

				if (isLastChar(i, sentence))
				{
					return INVALID;
				}

				if (isLower(sentence[i + 1])
					&& ruleTwoChar != sentence[i + 1])
				{
					if (ruleTwoChar != sentence[i - 1]
						|| visited[sentence[i + 1] - 'a'])
					{
						return INVALID;
					}

					isRuleOne = true;
					ruleOneChar = sentence[i + 1];
				}
			}

			if (isLower(sentence[i]))
			{
				isRuleTwo = false;
				visited[ruleTwoChar - 'a'] = true;
				ruleTwoChar = INIT_CHAR;

				words.push_back(temp);
				temp = "";
			}
		}
		// !규칙1 && !규칙2 (새로운 단어 시작)
		else
		{
			if (isUpper(sentence[i]))
			{
				temp += sentence[i];
				isRuleOne = true;

				if (isLastChar(i, sentence)
					|| isUpper(sentence[i + 1]))
				{
					isRuleOne = false;

					words.push_back(temp);
					temp = "";
				}

				if (isLower(sentence[i + 1]))
				{
					if (visited[sentence[i + 1] - 'a'])
					{
						return INVALID;
					}

					ruleOneChar = sentence[i + 1];
					vector<int> idxes;

					for (int j = i + 1; j < sentence.length(); j++)
					{
						if (sentence[j] == ruleOneChar)
						{
							idxes.push_back(j);
						}
					}

					// 이 부분 공부하는 식빵맘님 참고 (https://ansohxxn.github.io/programmers/131/)
					int specialCnt = idxes.size();

					// 하나 밖에 없다는건 다음 문자인 소문자가 규칙 1 단어의 특수문자가 되야한다는 것.
					// ex) OaO
					if (specialCnt == 1)
					{
						continue;
					}

					// 3개 이상인데 모두 대문자 사이사이에 인덱스 2 차이로 있을 때에도 다음 문자인 소문자가가 규칙 1 단어의 특수문자가 되야한다는 것
					// ex) AaBaCaDaE
					if (specialCnt >= 3)
					{
						bool isDistTwo = true;

						for (int j = 0; j < idxes.size() - 1; j++)
						{
							if (idxes[j + 1] - idxes[j] != 2)
							{
								isDistTwo = false;

								break;
							}
						}

						if (!isDistTwo)
						{
							continue;
						}
					}
					else
					{
						// 소문자가 전부 규칙 2 혹은 규칙 1+2 단어의 특수문자가 되어야 한다
						// ex) OaOOa, OaObOa, ObOb
						isRuleOne = false;
						ruleOneChar = INIT_CHAR;

						words.push_back(temp);
						temp = "";
					}
				}
			}

			if (isLower(sentence[i]))
			{
				if (visited[sentence[i] - 'a']
					|| isLastChar(i, sentence)
					|| isLower(sentence[i + 1]))
				{
					return INVALID;
				}

				isRuleTwo = true;
				ruleTwoChar = sentence[i];
			}
		}
	}

	string answer = "";

	for (string word : words)
	{
		answer += word + " ";
	}

	return answer.substr(0, answer.length() - 1);
}