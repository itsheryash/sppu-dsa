
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PQ
{
public:
    string patientName;
    int priority;
};

// max heap, obvi
class heap
{
public:
    vector<PQ> pq;
    int size;

    heap()
    {

        size = -1;
    }

    void insert(string name, int priority)
    {
        PQ p;
        p.patientName = name;
        p.priority = priority;

        size++;
        int i = size;
        pq.push_back(p);

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (pq[i].priority > pq[parent].priority)
            {
                swap(pq[i], pq[parent]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletePQ()
    {
        if (size == -1)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        
        pq[0] = pq.back();
        pq.pop_back();
        size--;

        int i = 0;

        while (i < size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && (pq[left].priority > pq[i].priority) && (pq[left].priority >= pq[right].priority))
            {
                swap(pq[i], pq[left]);
                i = left;
            }
            else if (right < size && (pq[right].priority > pq[i].priority) && (pq[right].priority >= pq[left].priority))
            {
                swap(pq[i], pq[right]);
                i = right;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout<<"The priority Queue will be:- "<<endl;
        for (auto i : pq)
        {
            cout << i.patientName << " --> " << i.priority << endl;
        }
    }
};

int main()
{

    heap h;

    h.insert("fds", 1);
    h.insert("dsa", 2);
    h.insert("cn", 3);
    h.insert("dbms", 2);

    h.print();
    h.deletePQ();
    cout << endl;
    h.deletePQ();
    cout << endl;
    h.print();

    return 0;
}