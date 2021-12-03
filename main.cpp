#include <iostream>
#include<vector>
#include<queue>

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

    queue<int> q;
    vector<int> done(7,0);

    for(int i=1; i<7; i++)
    {
        if(done[i] != 1) {
            q.push(i);
            done[i] = 1;
            while(!q.empty())
            {
                int i= q.front();
                printf(" %d",i);
                q.pop();

                for(int j=0; j<graph[i].size(); j++)
                {
                    if(done[graph[i][j]] != 1)
                    {
                        q.push(graph[i][j]);
                        done[graph[i][j]] = 1;
                    }
                }
            }
            cout<<endl;
        }
    }

//    for(int i=0; i<7; i++)
//    {
//        for(int j=0; j<graph[i].size(); j++)
//        {
//            cout<<graph[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    return 0;
}
