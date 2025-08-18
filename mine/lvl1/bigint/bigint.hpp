#pragma once


#include <iostream>
#include <algorithm>
#include <deque>

class bigint{
	private:
		std::deque<int> var;
	public:
		bigint() {
			var.push_back(0);
		}
		bigint(size_t num) {
			while (num)
			{
				var.push_front(num % 10);
				num = num / 10;
			}
		}
		bigint(const bigint &obj) {
			*this = obj;
		}

		bigint &operator=(const bigint &obj)
		{
			for (int i = 0; i < obj.var.size() ; i++)
			{
				this->var.push_back(obj.var[i]);
			}
			return (*this);
		}
		void print_var()
		{
			for (int i = 0; i < this->var.size() ; i++)
			{
				std::cout << this->var[i] << std::endl;
			}	
		}
};
