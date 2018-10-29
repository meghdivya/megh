#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<map>
using namespace std;

class Graph
{
    private:
        int V;
        list<int> *adj;
    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }
        void addEdge(int v, int w);
        void BFS(int s, bool visited[]);
        Graph getTranspose();
        bool isConnected();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::BFS(int s, bool visited[])
{
    list<int> q;
    list<int>::iterator i;
    visited[s] = true;
    q.push_back(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
bool Graph::isConnected()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    BFS(0, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;
    Graph gr = getTranspose();
    for(int i = 0; i < V; i++)
        visited[i] = false;
    gr.BFS(0, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;
    return true;
}

int main()
{
    int T,N,ai;
    cin >>T;
    vector<int> v;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int i=0; i<N; i++)
        {
            cin>>ai;
            v.push_back(ai);
        }
        Graph g(v.size());
        
        int j =0;
        int v_index = -1;
        for(int i=0; i<v.size()-1; i++)
        {
            for(j = i+1; j<v.size();j++)
            {
                if(__gcd(v[i], v[j]) == 1) 
                {
                    g.addEdge(i, j);
                }
            }
        }

        if(g.isConnected())
        {
            cout<<"0"<<endl;
            for(int i=0; i<v.size(); i++)
                cout<<v[i]<<" ";
        }
        else
        {
            cout<<"1"<<endl;
            if(v[0] !=47) 
            {
                v[0] = 47;
            }
            else
            {
                v[0] = 2;
            }
            for(int i=0; i<v.size(); i++)
                cout<<v[i]<<" ";
        }
        v.clear();
    }
    return 0;
}
