#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

	// string input, operation, color, transfOper;
	// int vertices, angle, N;
	// double cx, cy;

	// while (getline(cin, input)) {
	// istringstream stringstream(input);
	// stringstream >> operation;
	// if (operation.compare("POLYGON") == 0) {
	// stringstream >> color >> vertices;
	// }

	// else if (operation.compare("CIRCLE") == 0) {
	// stringstream >> color;
	// }

	// else if (operation.compare("TRANSF") == 0) {
	// stringstream >> transfOper;
	// if (transfOper.compare("SCA") == 0) {
	// stringstream >> cx >> cy;
	// }
	// else if (transfOper.compare("ROT") == 0) {
	// stringstream >> angle;
	// }
	// else if (transfOper.compare("TRA") == 0) {
	// stringstream >> cx >> cy;
	// }
	// }

	// else if (operation.compare("GROUP") == 0) {
	// stringstream >> N;
	// }
	// else if (operation.compare("COPY") == 0) {

	// }
	// else if (operation.compare("SHOW") == 0) {

	// }
	// }

	int a = 5;
	cout << "<xml version =\"1.0\" encoding =\"UTF-8\"?>\n";
	cout << "<svg xmlns =\"http://www.w3.org/2000/svg\"width=\"100\"height=\"100\">\n";
	cout << "<path d =\"M 0 0 L 100 0 L 100 100 L 0 100\" fill =\"#0000ff\">\n";
	cout << "< path d =\"M 100 50 L 50 0 L 0 50 L 50 100\" fill =\"#0000ff\">\n";
	cout << "< path d =\"M 100 50 L 25 93.3 L 25 6.7\" fill =\"#ff0000\">\n";
	cout << "< rect x =\"0\" y =\"0\" width =\"100\" height =\"100\"\n";
	cout << " stroke =\"#999999\" fill =\"none\" stroke - width =\"1\">\n";
	cout << "< / svg >\n";
	return 0;
}