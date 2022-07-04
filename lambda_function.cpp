#include <bits/stdc++.h>

using namespace std;

int main()
{
	/* demonstration of the lamda function */
	auto my_lamda_func = []()->void{
	cout<<"\n Hello world";
	};
	
	my_lamda_func();   // calling lamda function
	/* OR */
	
	[]()->void{
	cout<<"\n Hello world";
	}();              // alternatively () at the end of the lamda function also call it, so no need to give name to lamda function 
	
	
	auto result = [](double a,double b){
	return (a+b);
	}(12.34, 56.78);
	
	cout<<"\n addistion is = "<<result;
}
