#include <iostream>
#include <vector>

using namespace std;

int	main(void) {

	// testing size vs capacity
	{
		vector<int>	v1 (100, 100);

		cout << "size: " << v1.size() << endl;
		cout << "capacity: " << v1.capacity() << endl;
	}
	
	return (0);
}