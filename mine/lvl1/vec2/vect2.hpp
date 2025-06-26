#pragma ones

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2() : x(0), y(0) {};
		vect2(int v1, int v2) : x(v1), y(v2) {} ;

		vect2(const vect2 &obj) {
			if (this != &obj)
				*this = obj;
		};

		vect2 &operator=(const vect2 &obj)
		{
			this->x = obj.x;
			this->y = obj.y;
			return *this;
		};

		int operator[](int i)
		{
			return (i == 0) ? x : y;
		};
		int operator[](int i) const
		{
			return (i == 0) ? x : y;
		};

		vect2 &operator++()
		{
			this->x += 1;
			this->y += 1;
			return *this;
		}
		vect2 operator++(int)
		{
			vect2 tmp = *this; // 1. Make a copy of the current state
			this->x += 1;
			this->y += 1;      // 2. Increment the original object
			return tmp;        // 3. Return the copy of the OLD state
		};

		vect2 &operator--()
		{
			this->x -= 1;
			this->y -= 1;
			return *this;
		}
		vect2 operator--(int)
		{
			vect2 tmp(*this);
			this->x -= 1;
			this->y -= 1;
			return tmp;
		}

	};
	
std::ostream &operator<<(std::ostream &out, const vect2 &obj)
{
	out << "{" << obj[0] << ", " << obj[1] << "}";
	return out;
}