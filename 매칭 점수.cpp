#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const string BODY_TAG_START = "<body>";

const string BODY_TAG_END = "</body>";

const string A_TAG = "<a href=\"https://";

const string CONTENT = "<meta property=\"og:url\" content=\"https://";

typedef struct
{
    int idx;
    double basicScore;
    double externalLinkCnt;
    vector<int> linkToMes;
} WebPage;

vector<WebPage> webPages;

map<string, int> content2idx;

bool cmp(pair<double, int> a, pair<double, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}

double getTotalScore(WebPage webPage)
{
    double totalScore = webPage.basicScore;
    double sum = 0.0;
    
    for (int idx : webPage.linkToMes)
    {
        sum += (webPages[idx].basicScore / webPages[idx].externalLinkCnt);
    }
    
    totalScore += sum;
    
    return totalScore;
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

string getContent(string s)
{
    int idx = s.find(CONTENT);
    idx += CONTENT.length();
    
    string result = "";
    
    for (; s[idx] != '\"'; idx++)
    {
        result += s[idx];
    }
    
    return result;
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
        string content = getContent(page);
        vector<int> linkToMes;
        
        webPages.push_back({idx++, 0.0, 0.0, linkToMes});
        content2idx[content] = idx;
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
                webPages[content2idx[link] - 1].linkToMes.push_back(i);
            }
        }
    }

    vector<pair<double, int>> v;
    
    for (WebPage webPage : webPages)
    {
        v.push_back({getTotalScore(webPage), webPage.idx});
    }
    
    sort(v.begin(), v.end(), cmp);

    return v[0].second;
}
