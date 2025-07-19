#pragma once


#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2() : x(0) , y(0) {}
		vect2(int nx, int ny) : x(nx) , y(ny) {}
		vect2(const vect2 &obj)
		{
			*this = obj;
		}
		
		vect2 &operator=(const vect2 &obj)
		{
			if (this != &obj)
			{
				this->x = obj.x;
				this->y = obj.y;
			}
			return *this;
		}

		int& operator[](int i)
		{
			return (i == 0) ? this->x : this->y;
		}
		int operator[](int i) const
		{
			return (i == 0) ? this->x : this->y;
		}


		// ----------------------------------


		vect2 &operator++()
		{
			this->x++;
			this->y++;
			return (*this);
		}
		vect2 operator++(int)
		{
			vect2 tmp(*this);
			this->x++;
			this->y++;
			return (tmp);
		}

		vect2 &operator--()
		{
			this->x--;
			this->y--;
			return (*this);
		}
		vect2 operator--(int)
		{
			vect2 tmp(*this);
			this->x--;
			this->y--;
			return (tmp);
		}
		
		// ---------------------

		vect2 &operator+=(const vect2 &obj)
		{
			this->x += obj.x;
			this->y += obj.y;
			return (*this);
		}

		vect2 &operator-=(const vect2 &obj)
		{
			this->x -= obj.x;
			this->y -= obj.y;
			return (*this);
		}

		vect2 operator+(const vect2 &obj) const
		{
			return vect2(this->x + obj.x, this->y + obj.y);
		}

		vect2 operator-(const vect2 &obj)
		{
			return vect2(this->x - obj.x, this->y - obj.y);
		}

		vect2 operator*(int num) const
		{
			return vect2(this->x * num, this->y * num);
		}

		vect2 &operator*=(int num)
		{
			this->x *= num;
			this->y *= num;
			return (*this);
		}

		friend vect2 operator*(int num, const vect2 &obj)
		{
			return vect2(obj.x * num, obj.y * num);
		}

		vect2 &operator-()
		{
			this->x = -this->x;
			this->y = -this->y;
			return (*this);
		}

		bool operator==(const vect2 &obj)
		{
			return (this == &obj);
		}
		bool operator!=(const vect2 &obj)
		{
			return (this != &obj);
		}
};

std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}