#include <iostream>

using namespace std;

int main()
{
	//cout << "Hello World!" << endl;
	long long n;
	long long count=0;
	cin >> n;
	while (n!=1){
		if (n%2==0){
			count +=n;
			n/=2;
		}
		else
		{
			count += n+1;
			n = (n+1)/2+n;
		}
		//cout << n << ' ' << count << endl;
	}
	cout << count;
	return 0;
}

