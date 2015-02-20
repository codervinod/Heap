//
//  Heap.h
//  Heap
//
//  Created by Vinod Gupta on 2/20/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#ifndef Heap_Heap_h
#define Heap_Heap_h

#include <vector>
#include <math.h>

template <class T>
class Heap
{
public:
    Heap() {}
    virtual ~Heap() {}
    
    void Heapify(int i);
    
    void Insert(T val)
    {
        _heap.push_back(val);
        int pos = (int)_heap.size()-1;
        while(pos > 0)
        {
            int parent = getParentIndex(pos);
            if(_heap[parent] > _heap[pos])
            {
                int tmp = _heap[parent];
                _heap[parent] = _heap[pos];
                _heap[pos] = tmp;
            }
            pos = parent;
        }
    }
    
    
    T DelMin();
    
    T min()
    {
        if(_heap.empty())
            throw "Heap is empty";
        
        return _heap[0];
    }
    
private:
    int getParentIndex(int i) {return floor(i/2);}
    int getLeftChild(int i) {return i*2;}
    int getRightChild(int i) {return (i*2) + 1;}
    std::vector<T> _heap;
};

#endif
