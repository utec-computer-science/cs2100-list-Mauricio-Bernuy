#include <iostream>
#include "List.h"

using namespace std;

int main(){
    int array[] = {1,2,3,4,5};
    ForwardList<int> Flost;
    ForwardList<int> Flest = array;

    ForwardList<int> Flast(10);
    ForwardList<int> Flist = Flast;
    ForwardListNode<int> *node = new ForwardListNode<int> {12};
    ForwardList<int> Flust = node;
    Flost.push_back(1);
    Flost.push_back(21);
    Flost.push_front(10);
    Flost.push_front(103);
    Flast.push_back(28);
    cout<<Flist.back()<<endl<<Flist.front()<<endl;
    cout<<Flost.pop_back()<<Flost.pop_front()<<endl;
    cout<<Flast[5]<<endl;

    Flast.remove(28);

    cout<<Flast;
    Flast.reverse();
    cout<<Flast;
    return 0;
};
