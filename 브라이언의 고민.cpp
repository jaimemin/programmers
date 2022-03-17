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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {
	bool visited[ALPHABET_MAX] = { false, };
	bool isRuleOne = false, isRuleTwo = false;
	char ruleOneChar = INIT_CHAR, ruleTwoChar = INIT_CHAR;
	vector<string> words;
	string temp = "";

	for (int i = 0; i < sentence.length(); i++)
	{
		// ��Ģ1 && ��Ģ2
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
		// ��Ģ 1
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
		// ��Ģ 2
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
		// !��Ģ1 && !��Ģ2 (���ο� �ܾ� ����)
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

					// �� �κ� �����ϴ� �Ļ����� ���� (https://ansohxxn.github.io/programmers/131/)
					int specialCnt = idxes.size();

					// �ϳ� �ۿ� ���ٴ°� ���� ������ �ҹ��ڰ� ��Ģ 1 �ܾ��� Ư�����ڰ� �Ǿ��Ѵٴ� ��.
					// ex) OaO
					if (specialCnt == 1)
					{
						continue;
					}

					// 3�� �̻��ε� ��� �빮�� ���̻��̿� �ε��� 2 ���̷� ���� ������ ���� ������ �ҹ��ڰ��� ��Ģ 1 �ܾ��� Ư�����ڰ� �Ǿ��Ѵٴ� ��
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
						// �ҹ��ڰ� ���� ��Ģ 2 Ȥ�� ��Ģ 1+2 �ܾ��� Ư�����ڰ� �Ǿ�� �Ѵ�
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