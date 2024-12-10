#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

struct TrieNode 
{
    int count;
    
    TrieNode* children[26];
    
    TrieNode() : count(0) 
    {
        for (int i = 0; i < 26; i++) 
        {
            children[i] = nullptr;
        }
    }
    
    ~TrieNode() 
    {
        for (int i = 0; i < 26; i++)
        {
            if (children[i]) 
            {
                delete children[i];
            }
        }
    }
};

class Trie 
{
public:
    TrieNode* root;
    
    Trie() 
    {
        root = new TrieNode();
    }
    
    ~Trie() 
    {
        delete root;
    }
    
    void insert(const string& word) 
    {
        TrieNode* node = root;
        
        for (char c : word)
        {
            int idx = c - 'a';
            
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
            }
            
            node = node->children[idx];
            node->count++;
        }
    }

    int countKeyStrokes(const string& word)
    {
        TrieNode* node = root;
        int keystrokes = 0;
        
        for (char c : word) 
        {
            int idx = c - 'a';
            node = node->children[idx];
            keystrokes++;
            
            if (node->count == 1) 
            {
                break; // 더 이상 다른 단어와 공통 접두사가 없음
            }
        }
        
        return keystrokes;
    }
};

int solution(vector<string> words) {
    Trie trie;
    
    for (const string& word : words) 
    {
        trie.insert(word);
    }
    
    int totalKeystrokes = 0;
    
    for (const string& word : words) 
    {
        totalKeystrokes += trie.countKeyStrokes(word);
    }
    
    return totalKeystrokes;
}
