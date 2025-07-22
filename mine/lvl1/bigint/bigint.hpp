#pragma once


#include <iostream>
#include <algorithm>

class bigint{
	private:
		std::string str;
	public:
		bigint() : str("0") {};
		bigint(unsigned int num) : str(std::to_string(num)) {};
		bigint(const bigint &obj) : str(obj.str) {} ;

		std::string add_stings(std::string first, std::string second) const
		{
			int carry = 0;
			int i = first.size() - 1;
			int j = second.size() - 1;
			int res = 0;
			std::string str;

			while (i >= 0 || j >= 0 || carry)
			{
				res =  (i >= 0 ? (first[i] - '0') : 0)  + (j >= 0 ? (second[j] - '0') : 0) + carry;
				carry = res / 10;
				str.push_back(res % 10 + '0');
				i--;
				j--;
			}
			std::reverse(str.begin(), str.end());
			return str;
		}
		bigint operator+(const bigint &obj) const
		{
			return bigint(atoi(add_stings(this->str, obj.str).c_str()));
		}
		friend std::ostream &operator<<(std::ostream &os, const bigint &obj)
		{
			os << obj.str;
			return os;
		}
};
