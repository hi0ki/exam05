#pragma once

#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag &bag;
    public:
        set(searchable_bag &obj) : bag(obj) {}
        ~set()
        {
            bag.clear();
        }
        void insert (int a) 
        {
            if (!bag.has(a))
                bag.insert(a);
        }
        void insert (int *arr, int size) 
        {
            for (int i = 0; i < size; i++)
            {
                if (!bag.has(arr[i]))
                    bag.insert(arr[i]);
            }
        }
        void print() const 
        {
            bag.print();
        }
        void clear() 
        {
            bag.clear();
        }

        bool has(int a) const
        {
            return (bag.has(a));
        }
        searchable_bag &get_bag()
        {
            return (this->bag);
        }
};