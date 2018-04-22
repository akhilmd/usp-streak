#include <iostream>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;

typedef uint64_t int_type;

int main(int argc, char const *argv[])
{
	int_type K=1;
	int_type N;

	cout<<"Enter N:";
	cin>>N;

	if(N==1){
		cout<<"Not defined"<<endl;
	}
	else{
		while((N+K)%(K+1) == 0)
		{
			K++;
		}
		cout<<"K is:"<<K<<endl;
	}
	return 0;
}