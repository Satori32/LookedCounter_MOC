#include <iostream>
#include <cstdint>


template<class T>
struct LookedCounter {
	T C = 0;
	T One = 1;
	typedef T Type;
};

template<class T>
bool ConstructLookedCounter(LookedCounter<T>& In,const T& OneValue) {
	In.C = 0;
	In.One = OneValue;
	return true;
}

template<class T>
T Look(LookedCounter<T> In) {
	In.C += In.One;
	return In.C;
}

template<class T>
T Snoop(LookedCounter<T>& In) {
	return In.C;
}

template<class T>
bool Set(LookedCounter<T>& In,const T& Count,const T& One) {
	In.C = Count;
	In.One = One;

	return true;
}
template<class T>
bool Reset(LookedCounter<T>& In) {
	In.C = 0;
	In.One = T(1);
}
template<class T>
T Add(LookedCounter<T>& In, T Add) {
	In.C += Add;
	return In.C;
}

int main() {
	typedef std::uintmax_t Type;
	LookedCounter<Type> LC;

	ConstructLookedCounter<Type>(LC, 1);

	Look(LC);
	Look(LC);
	Look(LC);

	Snoop(LC);
}