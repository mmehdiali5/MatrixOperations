#include<iostream>
using namespace std;
#include"Matrix.h"
#include"CString.h"
#include"Array.h"
#include <initializer_list>

void f(Array < Array<int>> a)
{

}

int main()
{
	initializer_list<initializer_list<int>>a = { {1},{2},{3} };
	Array<Array<int>> b = a;
	f({{ 1,2 }, { 2,2 }});


	//cout << b;
	//Array<initializer_list < initializer_list<int>>> b = a;
	
	//i//nitializer_list<int>b = { 1,2,3,4 };
//	//auto p = rbegin(b);
	/*cout << *p << endl;
	p++;
	cout << *p<<endl;
	p--;
	cout << *p;
*/
	//cout << endl << b.end();
	/*Matrix<CString>a(3, 3);
	cin >> a;
	cout << a;*/

	
	/*Matrix<Matrix<int>>m(2, 2);
	for (int i = 0; i < 2; i = i + 1)
	{
		for (int j = 0; j < 2; j = j + 1)
		{
			m.at(i, j).reSize(2,2);
		}
	}
	cin >> m;
	cout << m;*/

	/*Matrix<Matrix<CString>>m3(2, 2);
	for (int i = 0; i < 2; i = i + 1)
	{
		for (int j = 0; j < 2; j = j + 1)
		{
			m3.at(i, j).reSize(2, 2);
		}
	}
	cin >> m3;
	cout << m3;*/

	/*Matrix<Array<int>>m(2,2);
	for (int i = 0; i < 2; i = i + 1)
	{
		for (int j = 0; j < 2; j = j + 1)
		{
			m.at(i, j).reSize(2);
		}
	}
	cin >> m;
	cout << m;*/

	cout << "\n\n\n\n\n\n\n";
	return 0;
}