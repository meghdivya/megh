#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class lru{
	list<int> dq;
	unordered_map<int, list<int>::iterator> ma;
	int csize;
	public:
	lru(int size)
	{
		csize = size;
	}
	void refer(int referre);
	void display();

};

void lru::refer(int x)
{
	if(ma.find(x) == ma.end())
	{
		if(csize == dq.size())
		{
			int last = dq.back();
			dq.pop_back();
			ma.erase(last);
		}
	}
	else
	{
		dq.erase(ma[x]);
	}
	dq.push_front(x);
	ma[x] = dq.begin();
}

void lru::display()
{
	for(auto it = dq.begin(); it!=dq.end(); ++it)
		cout<<*it<<" ";
}

int main()
{
	lru cache = lru(3);
	cache.refer(3);
	cache.refer(4);
	cache.refer(4);
	cache.refer(5);
	cache.refer(4);
	cache.display();
	return 0;
}
