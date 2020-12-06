#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

vector<int> list;

void CoutAll()
{
    for (auto num : list)
    {
        cout << setw(8) << num;
    }
    cout << endl;
}

void Swap(int index1, int index2)
{
    int mid = list[index1];
    list[index1] = list[index2];
    list[index2] = mid;
}

void Generate()
{
    ifstream inFile("input.txt");
    while (inFile.good())
    {
        int num;
        inFile >> num;
        list.push_back(num);
    }
}

void Output()
{
    ofstream outFile("output.txt");
    for (auto num : list)
    {
        outFile << setw(8) << num;
    }
}

void SimpleInsert()
{
    int size = list.size();
    for (int i = 0; i < size; ++i)
    {
        int num = list[i], pos = -1;
        for (int j = i - 1; j >= 0; --j)
        {
            if (num < list[j])
            {
                pos = j;
            }
        }
        if (pos != -1)
        {
            list.erase(list.begin() + i);
            list.insert(list.begin() + pos, num);
        }
    }
}

void Bubble()
{
    int size = list.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (list[j] > list[j + 1])
            {
                Swap(j, j + 1);
            }
        }
    }
}

void Select()
{
    int size = list.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for (int j = i; j < size; ++j)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }
        Swap(i, min);
    }
}

void Shaker()
{
    int size = list.size();
    int left = 0, right = size - 1;
    while (right >= left)
    {
        for (int i = left; i < right; ++i)
        {
            if (list[i] > list[i + 1])
            {
                Swap(i, i + 1);
            }
        }
        --right;
        for (int j = right; j > left; --j)
        {
            if (list[j] < list[j - 1])
            {
                Swap(j, j - 1);
            }
        }
        ++left;
    }
}

void BinInsert()
{
    vector<int> list2;
    list2.push_back(list[0]);
    list.erase(list.begin());
    int size = list.size();
    for (int i = 0; i < size; ++i)
    {
        int pos = -1, num = list[0], begin = 0, end = list2.size() - 1, mid;
        list.erase(list.begin());
        while (begin <= end && pos == -1)
        {
            mid = (begin + end) / 2;
            if (num > list2[mid])
            {
                begin = mid + 1;
            }
            else if (num < list2[mid])
            {
                end = mid - 1;
            }
            else
            {
                pos = mid;
            }
        }
        pos = mid;
        pos += num > list2[mid] ? 1 : 0;
        list2.insert(list2.begin() + pos, num);
    }
    list = list2;
}