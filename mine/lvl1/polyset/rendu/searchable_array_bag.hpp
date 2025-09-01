#pragma once

#include "searchable_bag.hpp"
#include "array_bag.hpp"
#include <iostream>

class searchable_array_bag : public array_bag , public searchable_bag {
    public:
        searchable_array_bag() : array_bag(){}
        searchable_array_bag(const searchable_array_bag &obj) : array_bag(obj) {}
        searchable_array_bag &operator=(const searchable_array_bag &obj)
        {
            array_bag::operator=(obj);
            return (*this);
        }
        ~searchable_array_bag(){}
        bool has(int a) const
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->data[i] == a)
                    return true;
            }
            return false;
        }

};