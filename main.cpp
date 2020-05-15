#include <iostream>
#include "List.h"

using namespace std;

int main(){
    /*int array[] = {1,2,3,4,5};
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
    return 0;*/

    typedef ForwardListNode<int> forward_node_t;
    typedef DoubleListNode<int> double_node_t;
    typedef CircularListNode<int> circular_node_t;
    
    /*List<forward_node_t> list_t;

    list_t.push_back(2);
    list_t.push_back(5);
    list_t.push_back(7);
    list_t.push_back(8);
    std::cout<<list_t;
    std::cout<<list_t.pop_back()<<endl;*/

    /*List<double_node_t> list1_t;
    list1_t.push_back(3);
    list1_t.push_back(2);
    list1_t.push_back(1);
    list1_t.push_back(6);
    std::cout<<list1_t;
    std::cout<<list1_t.pop_back()<<endl;
    cout<<"ok";*/


    List<circular_node_t> list2_t;
    list2_t.push_back(3);
    list2_t.push_back(2);
    list2_t.push_back(1);
    list2_t.push_back(6);
    std::cout<<list2_t;
    std::cout<<list2_t.pop_back()<<endl;
    cout<<"ok";
};
