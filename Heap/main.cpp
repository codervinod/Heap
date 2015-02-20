//
//  main.cpp
//  Heap
//
//  Created by Vinod Gupta on 2/20/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>
#include "Heap.h"
#include <string>
#include <vector>


using namespace std;

int main(int argc, const char * argv[]) {
    
    Heap<int> myHeap;
    try {
        //std::cout<<"Min element in heap="<<myHeap.min()<<std::endl;
        
        myHeap.Insert(53);
        myHeap.Insert(30);
        myHeap.Insert(23);
        myHeap.Insert(20);
        myHeap.Insert(18);
        myHeap.Insert(2);
        myHeap.Insert(57);
        myHeap.Insert(21);
        myHeap.Insert(15);
        
        cout<<"first heap:"<<endl;
        while(!myHeap.empty())
        {
            cout<<myHeap.DelMin()<<"\t";
        }
        cout<<std::endl;
        
        vector<int> ar = {3,4,12,39,34,21,64,19,51,42};
        
        Heap<int> myHeap2(ar);
        
        cout<<"second heap:"<<endl;
        while(!myHeap2.empty())
        {
            cout<<myHeap2.DelMin()<<"\t";
        }
        cout<<endl;
        
        
    } catch (const char *err) {
        std::cout<<"Caught error "<<err<<std::endl;
    }
    
    return 0;
}
