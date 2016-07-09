#include "matrix.hpp"

using namespace std;

int main()
{
	int sizeX,sizeY;
	cout << "Matrix" << endl;
	cin >> sizeX >> sizeY;

	Matrix m(sizeX,sizeY);
	m.init();

	for(int y=0;y<sizeY;y++){
		for(int x=0;x<sizeX;x++){
			cout<<(char)('a'+m.getElement(x,y)%26);
		}
		cout <<endl;
	}


	return 0;
}
