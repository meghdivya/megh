#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class lru {
    const int max_size = 4;
    unordered_map<int, list<int>::iterator> map_entry;
    list<int> deq;

public:
    lru() {};
    void refer(int key) {
        if (map_entry.find(key) == map_entry.end()) {
            if (deq.size() == max_size) {
                int last = deq.back();
                cout<<"Element popped as queue is full : " << last << endl;
                deq.pop_back();
                map_entry.erase(last);
            }
        }
        else {
            deq.erase(map_entry[key]);
        }
        deq.push_front(key);
        map_entry[key] = deq.begin();
        //cout<<"iter key: "<<deq.begin();
    }

    void display() {
        cout<< "Max size of LRU is "<< max_size << endl;
        cout<<"current size of cache "<<deq.size()<<endl;
        cout<<"[";
        for (auto it=deq.begin(); it!=deq.end(); ++it) {
            cout<<*it<<", ";
        }
        cout<<"]";
    }
    void display_map() {
        cout<<"\n------Displaying map contents ---------"<<endl;
        for (auto it=map_entry.begin(); it!=map_entry.end(); ++it) {
            cout<<*(it->second)<<", ";
        }
        cout<<"\n------Displaying map contents End ---------"<<endl;
    }
};

int main()
{
    lru test_lru;
    int item;
    while(1) {
        cout<<"Enter item to cache\n"<<endl;
        cin >> item;
        test_lru.refer(item);
        test_lru.display();
        test_lru.display_map();
    }
    return 0;
    
}
