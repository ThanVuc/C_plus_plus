#include<iostream>
using namespace std;

int main(){
	int i = 0;
	do {
		cout << i++<<" ";
	} while (i < 10);
	cout << "\n";
	while (i < 10) {
		cout << i++ << " ";
	}
	return 0;
}