#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef struct 
{
    int x, y, y2, type;
} Event;

bool compareEvent(const Event &a, const Event &b) 
{
    return a.x < b.x;
}

class SegmentTree 
{
private:
    vector<int> tree, count;
    
    vector<long long> lengths;
    
    vector<int> yCoords;
    
    int n;

    void buildTree(int node, int start, int end) 
    {
        if (start == end) {
            lengths[node] = yCoords[start + 1] - yCoords[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node + 1, start, mid);
            buildTree(2 * node + 2, mid + 1, end);
            lengths[node] = lengths[2 * node + 1] + lengths[2 * node + 2];
        }
    }

    void updateTree(int node, int start, int end, int l, int r, int value) 
    {
        if (r < start || l > end) 
        {
            return;
        }
        
        if (l <= start && end <= r) 
        {
            count[node] += value;
        } 
        else 
        {
            int mid = (start + end) / 2;
            updateTree(2 * node + 1, start, mid, l, r, value);
            updateTree(2 * node + 2, mid + 1, end, l, r, value);
        }
        
        if (count[node] > 0) 
        {
            tree[node] = lengths[node];
        } 
        else 
        {
            if (start == end) 
            {
                tree[node] = 0;
            } 
            else 
            {
                tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            }
        }
    }

public:
    SegmentTree(vector<int> &yCoords) : yCoords(yCoords) 
    {
        n = yCoords.size() - 1;
        tree.resize(4 * n);
        count.resize(4 * n);
        lengths.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    void update(int y, int y2, int value) 
    {
        int l = lower_bound(yCoords.begin(), yCoords.end(), y) - yCoords.begin();
        int r = lower_bound(yCoords.begin(), yCoords.end(), y2) - yCoords.begin() - 1;
        updateTree(0, 0, n - 1, l, r, value);
    }

    long long query() {
        return tree[0];
    }
};

long long solution(vector<vector<int> > rectangles) {
    vector<Event> events;
    set<int> ys;

    for (const auto &rect : rectangles) 
    {
        events.push_back({rect[0], rect[1], rect[3], 1});
        events.push_back({rect[2], rect[1], rect[3], -1});
        ys.insert(rect[1]);
        ys.insert(rect[3]);
    }

    vector<int> yCoords(ys.begin(), ys.end());
    SegmentTree segTree(yCoords);

    sort(events.begin(), events.end(), compareEvent);

    long long totalArea = 0;
    int prevX = events[0].x;

    for (const auto &event : events) 
    {
        long long width = event.x - prevX;
        long long height = segTree.query();
        
        totalArea += width * height;
        segTree.update(event.y, event.y2, event.type);
        prevX = event.x;
    }

    return totalArea;
}
