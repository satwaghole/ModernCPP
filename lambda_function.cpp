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
	
	
	/* code to demonstrate lambda function taking a variable outside its scope in
	   capture block, and expecting latest changed value, so we are using reference 
	   otherwise value will not change
	   
	   If we want all ouside variable accessible in lamda function we can use = inside
	   [] capture block. e.g [=] Note:- this is copy of all the varibles inside lamda
	   
	   If we want values should get reflecled into the outside code, we can use & inside
	   lamda, e.g [&] Note: this will create references
	*/
	   
	int a{10};
		
	auto lamda_func = [&a]()->void{
	cout<<"\n "<<a;
	};
	
	for(int i=0;i< 5 ; i++)
	{
		lamda_func();
		a++;
	}

	
	
}
