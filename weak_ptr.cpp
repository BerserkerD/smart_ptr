#include <iostream>
#include <memory>
using namespace std;

class Sample {
public:
	Sample() { cout << "Cons.." << endl; }
	~Sample() { cout << "Dest.." << endl; }
};

weak_ptr<Sample> func() {
	shared_ptr<Sample> Sp = make_shared<Sample>();
	return Sp;
}

int main() {
	shared_ptr<Sample> sp = make_shared<Sample>();
	cout << sp.use_count() << endl; // Prints 1
	weak_ptr<Sample> wp = sp;
	cout << sp.use_count() << endl; // Still Prints 1
	return 0;

    weak_ptr<Sample> Wp = func();
	cout << "End of Main" << endl;
	return 0;
}
