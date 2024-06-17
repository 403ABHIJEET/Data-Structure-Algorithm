#include<iostream>
#include<queue>
using namespace std;

struct comp {
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2) {
        return p1.first < p2.first;
    }
};

int main() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    for(int i=0; i<10; i++)
        pq.push({i,i+2});
    
    while(!pq.empty()) {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}