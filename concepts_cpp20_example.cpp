#include <bits/stdc++.h>

using namespace std;

/* sample code to use concepts */

/* using conecpts to force function to work only on integer values */
template <typename T>
requires std::integral<T>
T add(T a, T b)
{
	return a+b;
}

/* OR alternate way */
template <std::integral T>
T add1(T a, T b)
{
	return a+b;
}

/* OR another alternate way */
auto add2(std::integral auto a, std::integral auto b)
{
	return a+b;
}

/* OR another another alternate way */
template<typename T>
T add3(T a,T b) requires std::integral<T>
{
	return a+b;
}

int main()
{
	cout<<"\n "<<add(10,20);
	
	cout<<"\n "<<add1(20,20);
	
	cout<<"\n "<<add2(20,20);
	
	cout<<"\n"<<add3(30,20);
	
}
