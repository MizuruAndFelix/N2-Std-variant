#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>
using namespace std;

variant <int, string, vector<int>> get_variant() {
	srand(time(nullptr));
	int random_variable = rand() % 3;

	variant<int, string, vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "It's just a regular string";
		break;
	case 2:
		result = vector<int>{1,2,3,4,5};
		break;
	default:
		break;
	}
	return result;
}

int main(){
	if (holds_alternative<int>(get_variant()) == 1)
	{
		cout << get<int>(get_variant()) * 2 << endl; //Если в результате функции содержится int, 
	}                                                //то вывести число, умноженное на 2.
	else if (holds_alternative<string>(get_variant()) == 1)
	{
		cout << get<string>(get_variant()) << endl; //Если в результате функции содержится строка,
	}                                               // то просто вывести её в консоль.
	else if (holds_alternative<vector<int>>(get_variant()) == 1)
	{
		vector<int> myVector = get<vector<int>>(get_variant()); 
		for_each(myVector.begin(), myVector.end(), [](const int& n) { cout << n << ' '; }); //Если в результате 
	}                                  //функции содержится вектор чисел, то вывести все его элементы в консоль.
	else
	{
		cout << "No such data type" << endl;
	};



	std::cout << "\n-TEST END-\n";
};