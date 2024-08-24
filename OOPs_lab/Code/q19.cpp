#include <iostream>
using namespace std;

#define nl cout << '\n'
class Vector
{

    int *arr;
    int len;

public:
    // constructor
    Vector(int len)
    {
        this->len = len;
        arr = new int[len];
    }

    // copy constructor
    Vector(const Vector &v)
    {
        len = v.len;
        arr = new int[len];
        for (int i = 0; i < len; i++)
        {
            arr[i] = v.arr[i];
        }
    }

    // destructor
    ~Vector()
    {
        delete[] arr;
    }

    // basic operators
    Vector operator+(const Vector &v) const
    {
        int m = max(len, v.len);
        int n = min(len, v.len);
        Vector result(m);
        for (int i = 0; i < n; i++)
        {
            result.arr[i] = arr[i] + v.arr[i];
        }
        if (len > v.len)
        {
            for (int i = n; i < m; i++)
            {
                result.arr[i] = arr[i];
            }
        }
        else if (len < v.len)
        {
            for (int i = n; i < m; i++)
            {
                result.arr[i] = v.arr[i];
            }
        }
        return result;
    }

    Vector operator-(const Vector &v) const
    {
        int m = max(len, v.len);
        int n = min(len, v.len);
        Vector result(m);
        for (int i = 0; i < n; i++)
        {
            result.arr[i] = arr[i] - v.arr[i];
        }
        if (len > v.len)
        {
            for (int i = n; i < m; i++)
            {
                result.arr[i] = arr[i];
            }
        }
        else if (len < v.len)
        {
            for (int i = n; i < m; i++)
            {
                result.arr[i] = -v.arr[i];
            }
        }
        return result;
    }

    bool operator==(const Vector &v) const
    {
        if (len == v.len)
        {
            for (int i = 0; i < len; i++)
            {
                if (arr[i] != v.arr[i])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Vector &v) const
    {
        if (len == v.len)
        {
            for (int i = 0; i < len; i++)
            {
                if (!(arr[i] > v.arr[i]))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(const Vector &v) const
    {
        if (len == v.len)
        {
            for (int i = 0; i < len; i++)
            {
                if (!(arr[i] < v.arr[i]))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    // Access element
    int &operator[](int index) const
    {
        if (index < 0 || index >= len)
        {
            cerr << "Index out of bounds." << endl;
            exit(1);
        }
        return arr[index];
    }
    // methods
    int size() const
    {
        return len;
    }
    void disp() const
    {
        cout << '[';
        for (int i = 0; i < len; i++)
        {
            cout << ' ' << arr[i];
            if (i == len - 1)
            {
                cout << " ]" << endl;
            }
            else
            {
                cout << ',';
            }
        }
    }
};

int main()
{
    // create objs
    Vector v1(7), v2(5);
    for (int i = 0; i < v2.size(); i++)
    {
        v1[i] = 2 * i;
        v2[i] = 2 * i + 1;
    }
    v1[5] = 99, v1[6] = 66;

    // add
    Vector v3 = v1 + v2;
    cout << "v1 :";
    v1.disp();
    cout << "v2 :";
    v2.disp();
    cout << "v3 (v1+v2) :";
    v3.disp();
    nl;

    // sub
    cout << "v4 (v2-v1) :";
    Vector v4 = v2 - v1;
    v4.disp();
    nl;

    // eql
    Vector v5(5), v6(5);
    for (int i = 0; i < v5.size(); i++)
    {
        v5[i] = v6[i] = i;
    }
    cout << "v5 :";
    v5.disp();
    cout << "v6 :";
    v6.disp();
    cout << "v5 == v6: " << (v5 == v6) << endl;
    nl;

    // greater than less than
    Vector v7(5), v8(5);
    for (int i = 0; i < v7.size(); i++)
    {
        v7[i] = i;
        v8[i] = i + 1;
    }
    // v7[3]=69;
    cout << "v7 :";
    v7.disp();
    cout << "v8 :";
    v8.disp();
    cout << "v8 > v7: " << (v8 > v7) << endl;
    cout << "v7 < v8: " << (v7 < v8) << endl;
    nl;

    return 0;
}