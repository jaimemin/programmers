#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

const string BODY_TAG_START = "<body>";

const string BODY_TAG_END = "</body>";

const string A_TAG = "<a href=\"https://";

typedef struct
{
	int idx;
	int basicScore;
	int externalLinkCnt;
	int linkToMeCnt;
	string content;
} WebPage;

vector<WebPage> webPages;

map<string, int> content2idx;

double getTotalScore(WebPage webPage)
{
	double totalScore = (double)webPage.basicScore;

	if (webPage.externalLinkCnt != 0)
	{
		totalScore += (double)webPage.linkToMeCnt / (double)webPage.externalLinkCnt;
	}

	return totalScore;
}

bool cmp(WebPage a, WebPage b)
{
	if (getTotalScore(a) == getTotalScore(b))
	{
		return a.idx < b.idx;
	}

	return getTotalScore(a) > getTotalScore(b);
}

string getLowerCase(string s)
{
	string lower = "";

	for (char c : s)
	{
		lower += (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
	}

	return lower;
}

int getWordCnt(string s, string word)
{
	int startIdx = s.find(BODY_TAG_START);
	startIdx += BODY_TAG_START.length();
	int endIdx = s.find(BODY_TAG_END);
	s = s.substr(startIdx, endIdx - startIdx);

	int cnt = 0;
	string temp = "";

	for (char c : s)
	{
		if (!isalpha(c))
		{
			cnt += (temp == word);
			temp = "";

			continue;
		}

		temp += c;
	}

	return cnt;
}

vector<string> getExternalLinks(string s)
{
	vector<string> externalLinks;
	int idx = s.find(A_TAG);

	while (idx != -1)
	{
		idx += A_TAG.length();

		string temp = "";

		for (; s[idx] != '\"'; idx++)
		{
			temp += s[idx];
		}

		externalLinks.push_back(temp);

		s = s.substr(idx);
		idx = s.find(A_TAG);
	}

	return externalLinks;
}

int solution(string word, vector<string> pages) {
	int idx = 0;

	for (string page : pages)
	{
		string stringBuffer;
		istringstream iss(page);
		bool isInMeta = false;

		while (getline(iss, stringBuffer, ' '))
		{
			if (stringBuffer == "<meta")
			{
				isInMeta = true;

				continue;
			}

			if (isInMeta
				&& stringBuffer.length() >= 7
				&& stringBuffer.substr(0, 7) == "content")
			{
				string content = "";
				bool contentStart = false;

				for (char c : stringBuffer)
				{
					if (c == '\"')
					{
						contentStart = !contentStart;

						continue;
					}

					if (contentStart)
					{
						content += c;
					}
				}

				webPages.push_back({ idx, 0, 0, 0, content });
				content2idx[content] = (idx++ + 1);

				isInMeta = false;
			}
		}
	}

	for (int i = 0; i < pages.size(); i++)
	{
		pages[i] = getLowerCase(pages[i]);
		webPages[i].basicScore = getWordCnt(pages[i], getLowerCase(word));

		vector<string> externalLinks = getExternalLinks(pages[i]);
		webPages[i].externalLinkCnt = externalLinks.size();

		for (string link : externalLinks)
		{
			if (content2idx[link])
			{
				webPages[content2idx[link] - 1].linkToMeCnt++;
			}
		}
	}

	sort(webPages.begin(), webPages.end(), cmp);

	return webPages[0].idx;
}