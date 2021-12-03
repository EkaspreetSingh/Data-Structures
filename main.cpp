#include <iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
//    1--2--6     4--7
//    | \  /
//    5---3
    vector<vector<int>> graph;
    vector<int>edges;
    graph.push_back(edges);

    edges.push_back(2);         //1
    edges.push_back(3);
    edges.push_back(5);
    graph.push_back(edges);
    edges.clear();

    edges.push_back(1);         //2
    edges.push_back(6);
    graph.push_back(edges);
    edges.clear();

    edges.push_back(6);         //3
    edges.push_back(5);
    edges.push_back(1);
    graph.push_back(edges);
    edges.clear();

    edges.push_back(7);         //4
    graph.push_back(edges);
    edges.clear();

    edges.push_back(3);         //5
    edges.push_back(1);
    graph.push_back(edges);
    edges.clear();

    edges.push_back(3);         //6
    edges.push_back(2);
    graph.push_back(edges);
    edges.clear();

    edges.push_back(4);         //7
    graph.push_back(edges);
    edges.clear();

    stack<int> stk;
    vector<int> done(7,0);

    for(int i=1; i<7; i++)
    {
        if(done[i] != 1) {
            stk.push(i);
            done[i] = 1;
            while(!stk.empty())
            {
                int i= stk.top();
                printf(" %d",i);
                stk.pop();

                for(int j=0; j<graph[i].size(); j++)
                {
                    if(done[graph[i][j]] != 1)
                    {
                        stk.push(graph[i][j]);
                        done[graph[i][j]] = 1;
                    }
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
