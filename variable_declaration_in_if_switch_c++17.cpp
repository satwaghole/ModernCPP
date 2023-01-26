#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// programe for variable declaration in if/swicth statements

int main()
{
	
	vector<string> str = { "abc",
													"xyz",
													"pqr",
													"lmn"};
/*  The find algorithm will return an iterator pointing to the matched string.
Now, if again we want to replace another string with some other string in the
same vector, then for this, follow the same approach as shown above, and as
you will repeat the same code to just have to change the name of the iterator
 to something else. As declaring more than two iterators with the same name in
  the same scope will give a compilation error. The name changing option will
	work but if there are several strings that need to be replaced, but this
	approach is not efficient.
*/

	std::vector<string>::iterator it1 = std::find( str.begin(), str.end(), "abc");
	std::vector<string>::iterator it2 = std::find( str.begin(), str.end(), "pqr");
	if(it1 != str.end())
				*it1 = "$$$";
				
	if(it2 != str.end())
				*it2 = "***";

	for(auto i: str)
		cout<<i<<" "<<"\n";
		
		
 /***********************************************************************/
 // C++ 17 way to resolve above issue - also works with C++20
 
 vector<string> mystr = { "abc",
													"xyz",
													"pqr",
													"lmn"};
													
/* Now the scope of the iterator “it” is within the if statement itself,
 and the same iterator name can be used to replace other strings too
*/
 if(std::vector<string>::iterator it = find(mystr.begin(), mystr.end(), "abc");
 																 it != mystr.end())  // note the if statement
 {
		*it = "C++17Rocks";
 }
 
 for(auto i: mystr)
		cout<<i<<" "<<"\n";
		
	return 0;
}
