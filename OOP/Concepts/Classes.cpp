//#include<iostream>
//#include<ctime>
//using namespace std;
//
//class ComplexNumber {
//
//private:
//
//	int real;
//	int imaginary;
//
//public:
//
//	ComplexNumber(int, int);  //With Default Arguments
//	~ComplexNumber(); //Destructor which Does Nothing
//	void Input();
//	void Output();
//	bool IsEqual(ComplexNumber);
//	ComplexNumber Conjugate();
//	ComplexNumber Add(ComplexNumber);
//	ComplexNumber Subtract(ComplexNumber);
//	ComplexNumber Multiplication(ComplexNumber);
//	float Magnitude();
//
//};
//
//ComplexNumber::ComplexNumber(int real, int imaginary) {
//
//	this->real = real;
//	this->imaginary = imaginary;
//}
//
//ComplexNumber::~ComplexNumber() {
//
//}
//
//void ComplexNumber :: Input() {
//
//	cout << "Real Part: ";
//	cin >> real;
//	cout << "Imaginary Part: ";
//	cin >> imaginary;
//
//}
//
//void ComplexNumber::Output() {
//
//	if(imaginary>=0)
//	cout << real << "+" << imaginary << "i" << endl;
//	else if(imaginary<0)
//	cout << real << imaginary << "i" << endl;
//
//}
//
//bool ComplexNumber::IsEqual(ComplexNumber a) {
//
//	//if (real != a.real) return false;
//	//if (imaginary != a.imaginary) return false;
//
//	//return true;
//
//	return real == a.real && imaginary == a.imaginary;
//
//}
//
//ComplexNumber ComplexNumber::Conjugate() {
//
//	//ComplexNumber C3(0,0);
//
//	//C3.real = real;
//	//C3.imaginary = imaginary * (-1);
//	// 
//	//return C3;
//	
//	return ComplexNumber(real, imaginary * (-1));
//
//}
//
//ComplexNumber ComplexNumber::Add(ComplexNumber b) {
//
//	//ComplexNumber Sum(0, 0);
//	//Sum.real = real + b.real;
//	//Sum.imaginary = imaginary + b.imaginary;
//	// 
//	//return Sum;
//
//	return ComplexNumber(real + b.real, imaginary + b.imaginary);
//
//}
//
//ComplexNumber ComplexNumber::Subtract(ComplexNumber a) {
//
//	//ComplexNumber difference(0, 0);
//	//difference.real = real - a.real;
//	//difference.imaginary = imaginary - a.imaginary;
//	// 
//	//return difference;
//
//	return ComplexNumber(real - a.real, imaginary - a.imaginary);
//
//}
//
//ComplexNumber ComplexNumber::Multiplication(ComplexNumber a) {
//
//	//ComplexNumber Product(0, 0);
//	//Product.real = (((real) * (a.real)) - ((imaginary) * (a.imaginary)));
//	//Product.imaginary = (((real) * (a.imaginary)) + ((imaginary) * (a.real)));
//
//	//return Product;
//
//	return ComplexNumber((((real) * (a.real)) - ((imaginary) * (a.imaginary))), (((real) * (a.imaginary)) + ((imaginary) * (a.real))));
//
//}
//
//float ComplexNumber::Magnitude() {
//
//	/*float Magnitude = pow((pow(real, 2) + pow(imaginary, 2)), 0.5);
//
//	return Magnitude;*/
//
//	return pow((pow(real, 2) + pow(imaginary, 2)), 0.5);
//
//}
//
//int main() {
//
//	ComplexNumber C1(0,0), C2(0,0),Sum(0,0), Product(0,0), Difference(0,0);   //Initializing the Complex Numbers as 0 
//	float Magnitude;
//	
//	cout << "------------Complex Number 1------------\n";
//	C1.Input();
//	cout << "\n------------Complex Number 2------------\n";
//	C2.Input();
//
//	cout << "\nComplex Number 1: ";
//	C1.Output();
//	cout << "\nComplex Number 2: ";
//	C2.Output();
//
//	bool flag = C1.IsEqual(C2);
//	if (flag == true) cout << "\nComplex No. 1 is equal to Complex No. 2\n";
//	else if (flag == false) cout << "\nComplex No. 1 is Not Equal to Complex No. 2\n";
//
//	C1 = C1.Conjugate();
//	C2 = C2.Conjugate();
//	cout << "\nConjugate of Complex No. 1: ";
//	C1.Output();
//	cout << "\nConjugate of Complex No. 2: ";
//	C2.Output();
//
//	C1 = C1.Conjugate();
//	C2 = C2.Conjugate();
//
//	Sum=C1.Add(C2);
//	cout << "\nComplex No.1 + Complex No.2 = ";
//	Sum.Output();
//
//	Difference = C1.Subtract(C2);
//	cout << "\nComplex No.1 - Complex No.2 = ";
//	Difference.Output();
//
//	Product = C1.Multiplication(C2);
//	cout << "\nComplex No.1 * Complex No.2 = ";
//	Product.Output();
//
//	Magnitude = C1.Magnitude();
//	cout << "\nMagnitude of Complex No.1: " << Magnitude;
//	Magnitude = C2.Magnitude();
//	cout << "\nMagnitude of Complex No.2: " << Magnitude;
//	
//	
//	cout << endl;
//	return 0;
//	
//}
