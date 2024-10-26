#include <iostream>
#include <memory>
using namespace std;

class Sample {
public:
	Sample() { cout << "Sample Constuctor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
};

unique_ptr<Sample> Func() {
	cout << "Enter Function" << endl;
	unique_ptr<Sample> up(new Sample{});
	cout << "Exit Function" << endl;
	return up;
}

int main() {

    //1. 不允许赋值运算符
    unique_ptr<int> up1(new int());
    //unique_ptr<int> up2 = up1;

    //2. tranfer ownership using move()
    unique_ptr<int> up2(new int);
	// After this line, up1 will no longer hold any reference to the
	// memory created. Its lifetime is owned by up2
	unique_ptr<int> up3 = move(up2);

    //3. 也可以作为函数返回值使用
    unique_ptr<Sample> retup = Func();

    //编译器会显示的加上move语句
    /*unique_ptr<Sample> Func() {
        unique_ptr<Sample> up(new Sample{});
        return move(up);
    }*/

    //4. 尽量使用 make_unique<>() 而不是 new
    unique_ptr<Sample> up4 = make_unique<Sample>();

    //5. 对于数组
    unique_ptr<int[]> sp = make_unique<int[]>(10);

    return 0;

}