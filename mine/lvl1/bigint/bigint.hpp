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
			if (num == 0)
				var.push_back(0);
				
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
			this->var = obj.var;
			return (*this);
		}
		void print_var() const
		{
			for (int i = 0; i < this->var.size() ; i++)
			{
				std::cout << this->var[i];
			}	
		}

		friend std::ostream &operator<< (std::ostream &out, const bigint &obj)
		{
			for (int i = 0; i < obj.var.size() ; i++)
			{
				std::cout <<  obj.var[i];
			}
			return out;
		}

		std::deque<int> add_numbers(const bigint f_obj, const bigint &s_obj) const
		{
			int carry = 0;
			int result = 0;
			int i = s_obj.var.size() - 1;
			int j = f_obj.var.size() - 1;
			std::deque<int> res;

			while (i >= 0 || j >= 0 || carry)
			{
				result = (j < 0 ? 0 : f_obj.var[j]) + (i < 0 ? 0 : s_obj.var[i]) + carry;
				carry = result / 10;
				res.push_front(result % 10);
				i--;
				j--;
			}

			return (res); 
		}


		bigint operator+(const bigint &obj) const
		{
			bigint new_obj;

			new_obj.var.pop_back();
			new_obj.var = add_numbers(*this, obj);

			return new_obj;
		}

		bigint &operator+=(const bigint &obj)
		{
			this->var = add_numbers(*this, obj);

			return *this;
		}

		bigint operator++(int)
		{
			bigint tmp(*this);

			this->var = add_numbers(*this, bigint(1));

			return (tmp);
		}
		bigint &operator++()
		{
			this->var = add_numbers(*this, bigint(1));
			return (*this);
		}




		bool operator<(const bigint &obj) const
		{
			if (this->var.size() < obj.var.size())
				return true;
			else if (this->var.size() > obj.var.size())
				return false;

			for (int i = 0; i < this->var.size(); i++)
			{
				if (this->var[i] < obj.var[i])
					return true;
			}
			return false;
		}
		
		bool operator<=(const bigint &obj) const
		{
			if (this->var.size() < obj.var.size())
				return true;
			else if (this->var.size() > obj.var.size())
				return false;

			for (int i = 0; i < this->var.size(); i++)
			{
				if (this->var[i] < obj.var[i])
					return true;
			}
			return true;
		}

		bool operator>(const bigint &obj) const
		{
			return !(*this < obj);
		}
		bool operator>=(const bigint &obj) const
		{
			return !(*this < obj);
		}

		bool operator==(const bigint &obj) const
		{
			return ((*this <= obj) && (*this >= obj));
		}
		bool operator!=(const bigint &obj) const
		{
			return !(*this == obj);
		}

	bigint operator<<(int shift) const {
		bigint copy(*this);
		if (var.size() == 1 && var[0] == 0)
			return copy;
		for (int i = 0; i < shift; ++i)
			copy.var.push_back(0);
		return copy;
	}
	bigint operator>>(int shift) const {
		bigint copy(*this);
		for (int i = 0; i < shift; ++i) {
			if (!copy.var.empty())
				copy.var.pop_back();
			else {
				copy.var.push_front(0);
				break;
			}
		}
		return copy;
	}

	bigint operator<<(const bigint &shift) const {
		bigint copy(*this);
		if (var.size() == 1 && var[0] == 0)
			return copy;
		for (bigint i = 0; i < shift; ++i)
			copy.var.push_back(0);
		return copy;
	}
	bigint operator>>(const bigint shift) const {
		bigint copy(*this);
		for (bigint i = 0; i < shift; ++i) {
			if (!copy.var.empty())
				copy.var.pop_back();
			else {
				copy.var.push_front(0);
				break;
			}
		}
		return copy;
	}





		
};

