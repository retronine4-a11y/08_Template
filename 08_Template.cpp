#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Array
{
private:
    T* arr;
    int size;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    Array(int s)
    {
        size = s;
        arr = new T[size];
    }

    Array(initializer_list<T> list)
    {
        size = list.size();
        arr = new T[size];

        int i = 0;
        for (T value : list)
        {
            arr[i] = value;
            i++;
        }
    }

    Array(const Array& other)
    {
        size = other.size;
        arr = new T[size];

        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    ~Array()
    {
        delete[] arr;
    }

    void Fill()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element " << i << ": ";
            cin >> arr[i];
        }
    }

    void FillRandom()
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 100;
    }

    void Show()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void Add(T value)
    {
        T* temp = new T[size + 1];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;
    }

    void DeleteIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        T* temp = new T[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != index)
            {
                temp[j] = arr[i];
                j++;
            }
        }

        delete[] arr;
        arr = temp;
        size--;
    }

    void DeleteValue(T value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                DeleteIndex(i);
                return;
            }
        }
    }

    void SortAscending()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void SortDescending()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    T Min()
    {
        T min = arr[0];

        for (int i = 1; i < size; i++)
            if (arr[i] < min)
                min = arr[i];

        return min;
    }

    T Max()
    {
        T max = arr[0];

        for (int i = 1; i < size; i++)
            if (arr[i] > max)
                max = arr[i];

        return max;
    }

    double Average()
    {
        if (size == 0)
            return 0;

        double sum = 0;

        for (int i = 0; i < size; i++)
            sum += arr[i];

        return sum / size;
    }

    int GetSize()
    {
        return size;
    }

    T& operator[](int index)
    {
        return arr[index];
    }

    void operator()(T value)
    {
        for (int i = 0; i < size; i++)
            arr[i] += value;
    }
};

template <typename T>
T FindMax(Array<T>& a)
{
    if (a.GetSize() == 0)
        return T();

    T max = a[0];

    for (int i = 1; i < a.GetSize(); i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

template <typename T>
T FindMin(Array<T>& a)
{
    if (a.GetSize() == 0)
        return T();

    T min = a[0];

    for (int i = 1; i < a.GetSize(); i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

template <typename T>
void Sort(Array<T>& a)
{
    for (int i = 0; i < a.GetSize() - 1; i++)
    {
        for (int j = 0; j < a.GetSize() - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int BinarySearch(Array<T>& a, T value)
{
    int left = 0;
    int right = a.GetSize() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (a[mid] == value)
            return mid;

        if (a[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

template <typename T>
void Replace(Array<T>& a, int index, T value)
{
    if (index >= 0 && index < a.GetSize())
        a[index] = value;
}

int main()
{
    Array<int> a = { 8, 3, 10, 1, 6, 4 };

    cout << "Array: ";
    a.Show();

    cout << "Maximum: " << FindMax(a) << endl;
    cout << "Minimum: " << FindMin(a) << endl;

    Sort(a);

    cout << "Sorted array: ";
    a.Show();

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    int index = BinarySearch(a, value);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    int pos, newValue;

    cout << "Enter index to replace: ";
    cin >> pos;

    cout << "Enter new value: ";
    cin >> newValue;

    Replace(a, pos, newValue);

    cout << "After replacement: ";
    a.Show();

    a.Add(20);

    cout << "After adding: ";
    a.Show();

    a.DeleteValue(3);

    cout << "After deleting 3: ";
    a.Show();

    cout << "Average: " << a.Average() << endl;

    Array<double> b = { 2.5, 1.2, 4.8, 3.1 };

    cout << "Double array: ";
    b.Show();

    Sort(b);

    cout << "Sorted double array: ";
    b.Show();
}