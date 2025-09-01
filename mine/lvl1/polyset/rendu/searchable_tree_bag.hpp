#pragma once

#include "searchable_bag.hpp"
#include "tree_bag.hpp"
#include <iostream>

class searchable_tree_bag : public tree_bag , public searchable_bag
{
    public:
        searchable_tree_bag() : tree_bag(){}
        searchable_tree_bag(const searchable_tree_bag &obj) : tree_bag(obj){}
        searchable_tree_bag &operator=(const searchable_tree_bag &obj){
            tree_bag::operator=(obj);
            return (*this);
        }

        bool has(int a) const
        {
            node *courent = this->tree;
            while (courent)
            {
                if (a == courent->value)
                    return true;
                if (a < courent->value)
                    courent = courent->l;
                else
                    courent = courent->r;
            }
            return false;
        }
};