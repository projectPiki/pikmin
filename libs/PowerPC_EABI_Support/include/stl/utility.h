#ifndef _STD_PAIR_H
#define _STD_PAIR_H

namespace std {
template <typename T1, typename T2>
struct pair {
	T1 first;
	T2 second;
};

template <>
struct pair<f32, f32> {
	pair()
	    : first(0.0f)
	    , second(0.0f) { };
	f32 first;
	f32 second;
};
} // namespace std

#endif
