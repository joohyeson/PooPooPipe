#pragma once
#include <iostream>

namespace Mathematics {
	template <typename T>
	struct Vector2 {
		//==============================================Components============================================
		T x;
		T y;
		//=============================================Constructor============================================
		Vector2();
		Vector2(const T& p_XValue, const T& p_YValue);
		//==============================================Addition==============================================
		Vector2<T> &Add(const Vector2<T> &p_Vector);
		//=============================================Subtraction============================================
		Vector2<T> &Subtract(const Vector2<T> &p_Vector);
		//============================================Multiplication==========================================
		Vector2<T> &Multiply(const Vector2<T> &p_Vector);
		//===============================================Division=============================================
		Vector2<T> &Divide(const Vector2<T> &p_Vector);
		//=========================================+= Operator Override=======================================
		Vector2<T> &operator+=(const Vector2<T> &p_Vector);
		//=========================================-= Operator Override=======================================
		Vector2<T> &operator-=(const Vector2<T> &p_Vector);
		//=========================================*= Operator Override=======================================
		Vector2<T> &operator*=(const Vector2<T> &p_Vector);
		//=========================================/= Operator Override=======================================
		Vector2<T> &operator/=(const Vector2<T> &p_Vector);
		//=========================================== Operator Override=======================================
		bool operator==(const Vector2<T> &p_Vector);
		//=========================================!= Operator Override=======================================
		bool operator!=(const Vector2<T>&p_Vector);
		//==========================================+ Operator Override=======================================
		friend Vector2<T> operator+(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//==========================================- Operator Override=======================================
		friend Vector2<T> operator-(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//==========================================* Operator Override=======================================
		friend Vector2<T> operator*(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//==========================================/ Operator Override=======================================
		friend Vector2<T> operator/(Vector2<T> p_LValue, const Vector2<T>&p_RValue);
		//=========================================<< Operator Override=======================================
		friend std::ostream &operator<<(std::ostream &p_Stream, const Vector2<T>&p_Vector);
};
}
namespace Mathematics {
	//=============================================Constructor============================================
	template <typename T>
	Vector2<T>::Vector2() {
		x = 0.0f;
		y = 0.0f;
	}
	template <typename T>
	Vector2<T>::Vector2(const T& p_XValue, const T& p_YValue) {
		this->x = p_XValue;
		this->y = p_YValue;
	}
	//==============================================Addition==============================================
	template <typename T>
	Vector2<T>& Vector2<T>::Add(const Vector2<T>& p_Vector) {
		x += p_Vector.x;
		y += p_Vector.y;
		return *this;
	}
	//=============================================Subtraction============================================
	template <typename T>
	Vector2<T>& Vector2<T>::Subtract(const Vector2<T>& p_Vector) {
		x -= p_Vector.x;
		y -= p_Vector.y;
		return *this;
	}
	//============================================Multiplication==========================================
	template <typename T>
	Vector2<T>& Vector2<T>::Multiply(const Vector2<T>& p_Vector) {
		x *= p_Vector.x;
		y *= p_Vector.y;
		return *this;
	}
	//===============================================Division=============================================
	template <typename T>
	Vector2<T>& Vector2<T>::Divide(const Vector2<T>& p_Vector) {
		x /= p_Vector.x;
		y /= p_Vector.y;
		return *this;
	}
	//=========================================+= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& p_Vector) {
		return Add(p_Vector);
	}
	//=========================================-= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& p_Vector) {
		return Subtract(p_Vector);
	}
	//=========================================*= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& p_Vector) {
		return Multiply(p_Vector);
	}
	//=========================================/= Operator Override=======================================
	template <typename T>
	Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& p_Vector) {
		return Divide(p_Vector);
	}
	//=========================================== Operator Override=======================================
	template <typename T>
	bool Vector2<T>::operator==(const Vector2<T>& p_Vector) {
		return (x == p_Vector.x && y == p_Vector.y);
	}
	//=========================================!= Operator Override=======================================
	template <typename T>
	bool Vector2<T>::operator!=(const Vector2<T>& p_Vector) {
		return !(*this == p_Vector);
	}
	//==========================================+ Operator Override=======================================
	template <typename T>
	Vector2<T> operator+(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Add(p_RValue);
	}
	//==========================================- Operator Override=======================================
	template <typename T>
	Vector2<T> operator-(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Subtract(p_RValue);
	}
	//==========================================* Operator Override=======================================
	template <typename T>
	Vector2<T> operator*(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Multiply(p_RValue);
	}
	//==========================================/ Operator Override=======================================
	template <typename T>
	Vector2<T> operator/(Vector2<T> p_LValue, const Vector2<T>& p_RValue) {
		return p_LValue.Divide(p_RValue);
	}
	//=========================================<< Operator Override=======================================
	template <typename T>
	std::ostream& operator<<(std::ostream& p_Stream, const Vector2<T>& p_Vector) {
		p_Stream << "[Vector2<T>] (" << p_Vector.x << ", " << p_Vector.y << ")";
		return p_Stream;
	}
}