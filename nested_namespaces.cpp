#include <iostream>

using namespace std;

// before c++17
namespace a
{
	namespace b
	{
		 namespace c
		 {
				class sample{
					
						public:
								void show()
								{
									
								}
				};
		 	
		 }
	}
}

//after c++17
//This makes the code less error-prone as there is no need to pay attention to several levels of braces.
namespace x::y::z
{
		class newsample
		{
			
		};
}

int main()
{
	a::b::c::sample s1;  // before c++17
	
	x::y::z::newsample s2;  // after c++17
	
}
