#include<iostream>
#include<utility>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

struct mystruct{
    int index;
    double dist;
};

typedef struct mystruct mystruct;

double cal_dist(int x, int y)
{
    return sqrt((x*x)+(y*y));
}

double min(double x, double y)
{
    if(x<y)
        return x;
    else
        return y;
}

struct Comparemystruct{
    bool operator()(mystruct& m1, mystruct& m2)
    {
        return m1.dist>m2.dist;
    }
};

//vector< pair<int,int> > min_distance(int max_steak_house, int** loc, int req_steak_house)
vector<pair<int, int> > min_distance(int max_steak_house, int **loc, int req_steak_house)
{
    int i;
    vector<pair<int,int> > v;
    double dist;//numeric_limits<double>::max();
    priority_queue<mystruct, vector<mystruct>, Comparemystruct> my_q;
    mystruct correlated_data;
    for(i=0;i<max_steak_house;i++)
    {
        dist = cal_dist(loc[i][0], loc[i][1]);
        correlated_data.index = i;
        correlated_data.dist = dist;
        if(i>req_steak_house-1)
        {
            if(dist<my_q.top().dist)
            {
                my_q.pop();
                my_q.push(correlated_data);
            }
            continue;
        }
        my_q.push(correlated_data);
    }
    cout<<my_q.size()<<endl;
    while(!my_q.empty())
    {
        correlated_data = my_q.top();
        v.push_back(make_pair(loc[correlated_data.index][0], loc[correlated_data.index][1]));
        my_q.pop();
    }
    return v;
    //return v;
}

int main()
{
    int** loc = new int*[10];
    int j=3;
    for(int i = 0; i<10; i++)
    {
        loc[i] = new int[2];
        loc[i][0] = j;
        loc[i][1] = j-1;
        j--;
    }

//    loc[0][0] = 1;

 //   int loc[][2] = {{1,1}, {0,1},{2,3},{4,5},{-1,1}};
    vector<pair<int, int> > v = min_distance(10, loc, 5);
    for(int i=0; i<v.size(); i++)
        cout << v[i].first << ", " << v[i].second << endl;

    vector<int> vect{3,2,1,4,65,58,38};
    for(int x: vect)
        cout<<x<<endl;
    sort(vect.begin(), vect.end());
    for(int x: vect)
        cout<<x<<endl;
//
//    vector<pair<int, int> > vect{{1,3},{2,4},{1,5}};
//    for(int x: vect)
//        cout<<x<<endl;
//    sort(vect.begin(), vect.end());
//    for(int x: vect)
//        cout<<x<<endl;
    if(binary_search(vect.begin(), vect.end(), 38))
        cout<<"Found\n"<<endl;
    if(!binary_search(vect.begin(), vect.end(), 39))
        cout<<"not Found\n"<<endl;

    make_heap(vect.begin(), vect.end());
    for(int x: vect)
        cout<<x<<endl;

    return 0;
}
