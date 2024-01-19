#include "include/SingleLinkedListLibrary/SingleLinkedList.hpp"
#include "src/SingleLinkedListLibrary/SingleLinkedList.cpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <forward_list>
#include <functional>
#include <iostream>

using namespace std;
using namespace DataStructuresAndAlgorithms::LinkedList;

int main()
{
    forward_list<int> fwdList(1);
    SingleLinkedList<int> sll(1);

    int i = 0, j = 0;
    for (auto iter = fwdList.begin(); iter != fwdList.end(); ++iter)
    {
        fwdList.insert_after(fwdList.cbegin(), 3);
    }

    for (auto iter = sll.GetBegin(); iter != sll.GetEnd(); ++iter)
    {
        sll.InsertAfter(sll.GetConstBegin(), ++j);
    }

    sll.EraseAfter(sll.GetConstBegin());

    for (auto& iter : fwdList)
    {
        cout << iter << ' ';
    }

    cout << endl;

    for (auto iter = sll.GetBegin(); iter != sll.GetEnd(); ++iter)
    {
        cout << *iter << ' ';
    }

    cout << endl;

    return 0;
}