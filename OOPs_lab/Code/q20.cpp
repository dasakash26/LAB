#include <iostream>
using namespace std;

class IntArray
{
    int size;
    int *arr;

public:
    // constructor
    IntArray(int size) : size(size)
    {
        arr = new int[size];
    };
    // copy constructor
    IntArray(const IntArray &nums)
    {
        size = nums.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = nums.arr[i];
        }
    }
    // access elements
    int &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            cerr << "Index out of bounds." << endl;
            exit(1);
        }
        return arr[index];
    }
    // add
    IntArray operator+(const IntArray &nums) const
    {
        int m = max(size, nums.size);
        int n = min(size, nums.size);
        IntArray result(m);
        for (int i = 0; i < n; i++)
        {
            result.arr[i] = arr[i] + nums.arr[i];
        }
        if (size > nums.size)
        {
            for (int i = n; i < m; i++)
            {
                result.arr[i] = arr[i];
            }
        }
        else if (size < nums.size)
        {
            for (int i = n; i < m; i++)
            {
                result.arr[i] = nums.arr[i];
            }
        }
        return result;
    }
    // reverse
    IntArray rev()
    {
        for (int i = 0; i < (float)(size - 1) / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
        return *this;
    }
    // sort
    IntArray sort()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return *this;
    }
    // destructor
    ~IntArray()
    {
        delete[] arr;
    }
    // print
    void disp() const
    {
        cout << '[';
        for (int i = 0; i < size; i++)
        {
            cout << ' ' << arr[i];
            if (i == size - 1)
            {
                cout << " ]" << endl;
            }
            else
            {
                cout << ',';
            }
        }
        cout << endl;
    }
};

int main()
{
    IntArray nums(6);
    for (int i = 0; i < 6; i++)
    {
        nums[i] = i + 1;
    }

    cout << "innitial array : " << endl;
    cout << "nums :";
    nums.disp();

    cout << "copy cons : " << endl;
    cout << "nums1 :";
    IntArray nums1(nums);
    nums1.disp();

    cout << "nums + nums1 " << endl;
    cout << "nums2 :";
    IntArray nums2 = nums + nums1;
    nums2.disp();

    cout << "reversed array : " << endl;
    cout << "nums2 : ";
    nums2.rev().disp();

    cout << "sorted array : " << endl;
    cout << "nums2 : ";
    nums2.rev().disp();
}