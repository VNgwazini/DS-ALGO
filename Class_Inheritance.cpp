#include <iostream>
#include <string>
class TwoNumbers {
private:
	int Numbers, FirstNum, SecondNum, Sum, Diff, Prod;
public:
	TwoNumbers();
	TwoNumbers(int, int);
	void setNumbers(int, int);
	void setFirstNum(int);
	void setSecondNum(int);
	void setSum(int, int);
	void setDiff(int, int);
	void setProd(int, int);
	int getSum();
	int getDiff();
	int getProd();
};

TwoNumbers::TwoNumbers() {
	FirstNum = 0;
	SecondNum = 0;
}

TwoNumbers::TwoNumbers(int x, int y) {
	FirstNum = x;
	SecondNum = y;
}

void TwoNumbers::setSum(int x, int y) {
	FirstNum = x;
	SecondNum = y;
	Sum = x + y;
}
void TwoNumbers::setDiff(int x, int y) {
	FirstNum = x;
	SecondNum = y;
	Diff = x - y;
}
void TwoNumbers::setProd(int x, int y) {
	FirstNum = x;
	SecondNum = y;
	Prod = x*y;
}

void TwoNumbers::setNumbers(int x, int y) {
	FirstNum = x;
	SecondNum = y;
};
void TwoNumbers::setFirstNum(int x) {
	FirstNum = x;
};
void TwoNumbers::setSecondNum(int y) {
	SecondNum = y;
};

int TwoNumbers::getSum() {
	return FirstNum+SecondNum;
};
int TwoNumbers::getDiff() {
	return FirstNum-SecondNum;
};
int TwoNumbers::getProd() {
	return FirstNum*SecondNum;
};



//Math class inherits TwoNUmbers class
class Math: public TwoNumbers{
    using TwoNumbers::TwoNumbers;
};


using namespace std;

int main(){
	int value1, value2;

Math jim, alex(5, 6);

cout << "Enter Value 1:"<<endl;
cin >> value1;
cout << "Enter Value2"<<endl;
cin >> value2;


jim.setNumbers(value1, value2);
//jim.setFirstNum(70);
//jim.setSecondNum(40);
cout << jim.getSum() << " " << jim.getDiff() << " " << jim.getProd() << "\n";
cout << alex.getSum() << " " << alex.getDiff() << " " << alex.getProd() << "\n";
//system("Pause");
}

}
