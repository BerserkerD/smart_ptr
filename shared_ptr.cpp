#include <iostream>
#include <memory>
using namespace std;

class Sample {
public:
	Sample() { cout << "Sample Constructor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
	void publicFn() { cout << "This is public function of class" << endl; }
};

shared_ptr<Sample> Func() {
	cout << "Enter Function" << endl;
	shared_ptr<Sample> sp(new Sample{});
	cout << "Exit Function" << endl;
	return sp;
}

int main() {
    //1. valid declaration
    shared_ptr<int> p; // 未初始化

    //2. 
	shared_ptr<Sample> sp1(new Sample{});
	sp1->publicFn();

    //3. 可以将shared_ptr作为函数返回值返回
    shared_ptr<Sample> retSp = Func();

    //4. make_shared<>()
    //使用 make_shared 比使用 new 进行初始化快
    shared_ptr<Sample> sp2 = make_shared<Sample>();

    //5. Using shared_ptr<> for Arrays
    shared_ptr<int> sp(new int[10]); // delete 时只会析构一个元素
    shared_ptr<int> sp(new int[10], default_delete<int[]>()); // 会 delete 所有元素


	return 0;
}
