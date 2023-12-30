#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
 
const int MAX = 50 + 1;

const string EMPTY = "EMPTY";

string board[MAX][MAX];
map<pair<int, int>, pair<int, int>> coord2coord;

void print()
{
    for (int y = 1; y <= 4; y++)
    {
        for (int x = 1; x <= 4; x++)
        {
            cout << board[y][x] << " ";
        }
        
        cout << "\n";
    }
    
    cout << "\n";
}

void init()
{
    for (int y = 0; y < MAX; y++)
    {
        for (int x = 0; x < MAX; x++)
        {
            coord2coord[{y, x}] = {y, x};
            board[y][x] = EMPTY;
        }
    }
}

bool isNumber(string s)
{
    for (char c : s)
    {
        if (!(c >= '0' && c <= '9'))
        {
            return false;
        }
    }
    
    return true;
}

void updateBoard(string prev, string cur)
{
    for (int y = 0; y < MAX; y++)
    {
        for (int x = 0; x < MAX; x++)
        {
            if (board[y][x] == prev)
            {
                board[y][x] = cur;
            }
        }
    }
}

void merge(pair<int, int> root, pair<int, int> root2)
{
    string value = board[root.first][root.second];
    string value2 = board[root2.first][root2.second];
    
    for (int y = 0; y < MAX; y++)
    {
        for (int x = 0; x < MAX; x++)
        {
            if (coord2coord[{y, x}] == root2)
            {
                coord2coord[{y, x}] = root;
            }
        }
    }
    
    if (value2 != EMPTY && value == EMPTY)
    {
        board[root.first][root.second] = value2;
    }
    else
    {
        board[root2.first][root2.second] = value;
    }
}

void unmerge(pair<int, int> root)
{
    for (int y = 0; y < MAX; y++)
    {
        for (int x = 0; x < MAX; x++)
        {
            if (coord2coord[{y, x}] == root) 
            {
                coord2coord[{y, x}] = {y, x};
                board[y][x] = EMPTY;
            }
        }
    }
}

pair<int, int> findRoot(int r, int c)
{
    return coord2coord[{r, c}];
}
 
vector<string> solution(vector<string> commands) {
    init();
    vector<string> answer;
 
    for (string command : commands)
    {
        vector<string> v;
        stringstream ss(command);
        string s;
        
        while (ss >> s)
        {
            v.push_back(s);
        }
        
        int r, c, r2, c2;
        string value, value2, mergeValue;
        string op = v[0];
 
        if (op == "UPDATE") 
        {         
            if (v.size() == 4)
            {
                r = stoi(v[1]);
                c = stoi(v[2]);
                value = v[3];
                
                pair<int, int> root = findRoot(r, c);
                board[root.first][root.second] = value;
            }
            else 
            {
                value = v[1];
                value2 = v[2];
                
                updateBoard(value, value2);
            }
        }
        else if (op == "MERGE") 
        {
            r = stoi(v[1]);
            c = stoi(v[2]);
            r2 = stoi(v[3]);
            c2 = stoi(v[4]);
            
            pair<int, int> root = findRoot(r, c);
            pair<int, int> root2 = findRoot(r2, c2);
            
            if (root == root2)
            {
                continue;
            }
            
            merge(root, root2);
        }
        else if (op == "UNMERGE") 
        {
            r = stoi(v[1]);
            c = stoi(v[2]);
            
            pair<int, int> root = findRoot(r, c);
            string s = board[root.first][root.second];
            unmerge(root);
            board[r][c] = s;
        }
        else 
        {
            r = stoi(v[1]);
            c = stoi(v[2]);
            
            pair<int, int> root = findRoot(r, c);
            answer.push_back(board[root.first][root.second]);
        }
        
        // cout << command << "\n";
        // print();
    }
 
    return answer;
}
