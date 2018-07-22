#pragma once
// T is placeholder "type"
template <typename T>
T max(T const& t1, T const& t2)
{
	// immidiate if operator
	return t1 < t2 ? t2 : t1;
}


