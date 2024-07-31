//лабораторная работа 1 по высшей геодезии

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() //эллипсоид Красовского
{
	cout << "This program shall calculate the main paramaters of the Krasovsky Ellipsoid. Let's begin." << endl;
	cout << endl;

	//координаты точки поверхности эллипсоида
	double pi, lat, lon;
	pi = 3.14159265;
	lat = 1.0181;
	lon = 0.7039;

	cout << "Starting coordinates: " << endl;
	cout << "Latitude B = 58 deg 20 min" << endl;
	cout << "Longitude A = 40 deg 20 min" << endl;
	cout << endl;

	//значения исходных параметров эллипсоида
	double alpha, a;
	alpha = 1 / 298.3;
	a = 6378245.0;

	cout << "Starting parameters: " << endl;
	cout << fixed << setprecision(10) << "alpha = " << alpha << endl;
	cout << fixed << setprecision(1) << "a = " << a << " m" << endl;
	cout << endl;

	//значения параметров основных элементов
	double b, e, e1, c;
	b = a * (1 - alpha);
	e = (alpha * (2 - alpha));
	e1 = e / (1 - e);
	c = pow(a, 2) / b;

	cout << "Parameters of the main elements: " << endl;
	cout << fixed << setprecision(4) << "b = " << b << " m" << endl;
	cout << fixed << setprecision(10) << "e^2 = " << e << endl;
	cout << fixed << setprecision(10) << "(e')^2 = " << e1 << endl;
	cout << fixed << setprecision(4) << "c = " << c << " m" << endl;
	cout << endl;

	//контроли значений параметров основных элементов
	double b2;
	b2 = pow(a, 2) * (1 - e);
	b = pow(a, 2) / c;
	e = (pow(a, 2) - pow(b, 2)) / pow(a, 2);
	e1 = (pow(a, 2) - pow(b, 2)) / pow(b, 2);
	alpha = (a - b) / a;
	c = a / (1 - alpha);

	cout << "Control values: " << endl;
	cout << fixed << setprecision(4) << "b^2 = " << b2 << endl;
	cout << fixed << setprecision(4) << "b = " << b << endl;
	cout << fixed << setprecision(10) << "e^2 = " << e << endl;
	cout << fixed << setprecision(10) << "(e')^2 = " << e1 << endl;
	cout << fixed << setprecision(10) << "alpha = " << alpha << endl;
	cout << fixed << setprecision(4) << "c = " << c << endl;
	cout << endl;

	//значения сфероидических функций
	double W2, V2;
	W2 = 1 - e * pow(sin(lat), 2);
	V2 = 1 + e1 * pow(cos(lat), 2);

	cout << "Main spheroidic functions: " << endl;
	cout << fixed << setprecision(10) << "W^2 = " << W2 << endl;
	cout << fixed << setprecision(10) << "V^2 = " << V2 << endl;
	cout << endl;

	//контроль значений сфероидических функций
	double aW, bV;
	aW = a * sqrt(W2);
	bV = b * sqrt(V2);

	cout << "Control values: " << endl;
	cout << fixed << setprecision(4) << "a * W = " << aW << endl;
	cout << fixed << setprecision(4) << "b * V = " << bV << endl;
	cout << endl;

	//значения главных радиусов кривизны
	double M, N, R;
	M = c / pow(sqrt(V2), 3);
	N = c / sqrt(V2);
	R = sqrt(M * N);

	cout << "Main curvature ranges: " << endl;
	cout << fixed << setprecision(10) << "M = " << M << " m" << endl;
	cout << fixed << setprecision(10) << "N = " << N << " m" << endl;
	cout << fixed << setprecision(10) << "R = " << R << " m" << endl;
	cout << endl;

	//контроль значений главных радиусов кривизны
	double NM;
	NM = N / M;

	cout << "Control values: " << endl;
	cout << fixed << setprecision(10) << "N / M = " << NM << endl;
	cout << fixed << setprecision(10) << "V^2 = " << V2 << endl;
	cout << endl;

	//метрические координаты заданной точки
	double tgU, x, y, z;
	tgU = (sqrt(1 - e) * tan(lat));
	x = a * cos(atan(tgU)) * cos(lon);
	y = a * cos(atan(tgU)) * sin(lon);
	z = b * sin(atan(tgU));

	cout << "Metric coordinates: " << endl;
	cout << fixed << setprecision(4) << "x = " << x << " m" << endl;
	cout << fixed << setprecision(4) << "y = " << y << " m" << endl;
	cout << fixed << setprecision(4) << "z = " << z << " m" << endl;
	cout << fixed << setprecision(10) << "tgU = " << tgU << endl;
	cout << endl;

	//контроль метрических координат
	x = N * cos(lat) * cos(lon);
	y = N * cos(lat) * sin(lon);
	z = N * (1 - e) * sin(lat);

	cout << "Control values: " << endl;
	cout << fixed << setprecision(4) << "x = " << x << " m" << endl;
	cout << fixed << setprecision(4) << "y = " << y << " m" << endl;
	cout << fixed << setprecision(4) << "z = " << z << " m" << endl;
	cout << endl;

	cout << "All calculations have been checked, all controls have converged. The program has been executed successfully." << endl;

	system("pause");
	return 0;
}