#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Heap
{
    vector<long long> h;

    Heap(vector<long long> v)
    {
        int n = v.size();
        h.assign(n, 0);
        for (int i = v.size() - 1; i >= 0; --i)
        {
            shift_down(i, n);
        }
    }

    void shift_up(int i) //inside repair
    {
        while ((i > 1) && (h[i] > h[i / 2]))
        {
            swap(h[i], h[i / 2]);
            i /= 2;
        }
    }

    void shift_down(int i, int n)
    {
        while ((2 * i + 1) < n)
        {
            if (h[2 * i] > h[2 * i + 1])
            {
                swap(h[i], h[2 * i]);
                i *= 2;
            }
            else
            {
                swap(h[i], h[2 * i + 1]);
                i = i * 2 + 1;
            }
        }
    }

    void increase(int i, long long new_x)
    {
        if (new_x < h[i])
        {
            cout << "You try to increase an element! New value should be more than previous one!" << endl;
            return;
        }
        h[i] = new_x;
        shift_up(i);
    }

    void decrease(int i, long long new_x)
    {
        if (new_x > h[i])
        {
            cout << "You try to decrease an element! New value should be less than previous one!" << endl;
            return;
        }
        h[i] = new_x;
        shift_down(i, h.size());
    }

    void remove(int i, int n)
    {
        h[i] = h[n - 1];
        h.pop_back();
        --n;
        shift_up(i);
        shift_down(i, n);
    }

    void insert(int new_x)
    {
        h.push_back(new_x);
        shift_up(h.size() - 1);
    }

    long long take_max()
    {
        long long res = h[1];
        remove(1, h.size());
        return res;
    }

    void pyramid_sort()
    {
        for (int i = 1; i <= h.size(); ++i)
        {
            int num = h.size();
            swap(h[1], h[num - 1]);
            --num;
            shift_down(1, num);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    Heap h(v);
    
    return 0;
}