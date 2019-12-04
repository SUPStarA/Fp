#include "Fp.h"
#include <utility>
Fp Fp :: operator + (Fp other) {
	assert(other._p == _p, "Diffrent p");
	return Fp(_p, other._val + _val - (other._val + _val > _p) * _p);
}

Fp Fp :: operator + (int x) {
	return (*this) + Fp(_p, x);
}

Fp operator + (int a, Fp b) {
	return Fp(a, b._p) + b;
}

template <typename T>
Fp& Fp :: operator += (T other) {
	(*this) = (*this) + other;
}



Fp Fp :: operator * (Fp other) {
	assert(other._p == _p, "Diffrent p");
	return Fp(_p, other._val * _val % _p);
}

Fp Fp :: operator * (int x) {
	return (*this) * Fp(_p, x);
}

Fp operator * (int a, Fp b) {
	return Fp(a, b._p) * b;
}

template <typename T>
Fp& Fp :: operator *= (T other) {
	(*this) = (*this) * other;
}



Fp Fp :: operator - (Fp other) {
	assert(other._p == _p, "Diffrent p");
	return Fp(_p, _val - other._val + (_val  - other._val > _p) * _p);
}

Fp Fp :: operator - (int x) {
	return (*this) - Fp(_p, x);
}

Fp operator - (int a, Fp b) {
	return Fp(a, b._p) - b;
}

template <typename T>
Fp& Fp :: operator -= (T other) {
	(*this) = (*this) - other;
}

Fp binpow(Fp a, int n) {
	Fp ans(a._p, 1);
	while (n) {
		if (n & 1) {
			ans._val *= a._val;
			ans._val %= a._p;
		}
		n >>= 1;
	}
	return ans;
}

int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

Fp Fp::Inv() {
	if (_inv != 0) return _inv;
	return _inv = binpow((*this), _p - 2)._val;
}

Fp Fp :: operator / (Fp other) {
	assert(other._p == _p, "Diffrent p");
	assert(gcd(_val, _p) == 1 && gcd(other._val, _p) == 1, "Diffrent p");
	return (*this) * other.Inv();
}

Fp Fp :: operator / (int x) {
	return (*this) / Fp(_p, x);
}

Fp operator / (int a, Fp b) {
	return Fp(a, b._p) / b;
}

template <typename T>
Fp& Fp :: operator /= (T other) {
	(*this) = (*this) / other;
}