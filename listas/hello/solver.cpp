#include <iostream>

using namespace std;

int main()
{
	string name;
	while (true)
	{
		cin >> name;
		if (name == "END")
			break;
		cout << "Helo " << name << endl;
	}
}