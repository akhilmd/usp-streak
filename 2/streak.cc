#include <iostream>
#include <cstdint>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

typedef uint64_t int_type;

int_type get_streak(int_type N)
{
	int_type K=1;
	if(N==1)
	{
		cout<<"Not defined"<<endl;
		return -1;
	}
	else if(N%2 == 0) //even number
	{
		return 1;
	}
	else // odd number, check with 2
	{
		if((N+2)%(3) != 0)
		{
			return 2;
		}
		while((N+K)%(K+1) == 0)
		{
			K++;
		}
		return K;
	}
}

void test_get_streak(int_type* N)
{
	const clock_t begin_time = clock();
	cout<<"N[i]\t\t\t"<<"K\n";
	for (int_type i = 0; i < 1000000; ++i)
	{
		int_type res = get_streak(N[i]);
		cout<<N[i]<<"\t"<<res<<endl;
	}
	
	cout<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds"<<endl;

}

int main(int argc, char const *argv[])
{
	int_type N=atoi(argv[1]);
	// int_type* N = new int_type[1000000];
	int_type j = 0;

	// for (int_type i = 3; i < 2000003; i=i+2)
	// {
	// 	N[j] = i;
	// 	j++;
	// }
	int res = get_streak(N);
	if(res!=-1)
		cout<<res<<endl;
	return 0;
}