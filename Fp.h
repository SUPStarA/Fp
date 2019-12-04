#pragma once
#include <assert.h>
class Fp
{
public:
	Fp(int _p, int _val = 0) : _p(_p), _val(_val), _inv(0) { assert(_p == 0, "p cant be zero"); }

	Fp operator + (Fp other);

	Fp operator + (int other);

	friend Fp operator + (int a, Fp b);

	template <typename T>
	Fp& operator += (T other);

	Fp operator - (Fp other);

	Fp operator - (int other);

	friend Fp operator - (int a, Fp b);

	template <typename T>
	Fp& operator -= (T other);

	Fp operator * (Fp other);

	Fp operator * (int other);

	friend Fp operator * (int a, Fp b);

	template <typename T>
	Fp& operator *= (T other);

	Fp operator / (Fp other);

	Fp operator / (int other);

	friend Fp operator / (int a, Fp b);

	template <typename T>
	Fp& operator /= (T other);

	friend Fp binpow(Fp a, int n);

	Fp Inv();

private:
	const int _p;
	int _val;
	int _inv;
};