#include"URLmethods.h"
using namespace std;

int main()
{
	string fileName;
	cout << "Enter filename" << endl;
	cin >> fileName;
	while (!checkExtension(fileName))
	{
		cout << "Enter correct Filename" << endl;
		cin >> fileName;
	}
	readFromFile(fileName);
	/*cout << endl;
	cout << "Enter a word to search" << endl;
	cin >> fileName;
	cout << "-----------------------------------" << endl;
	cout << endl;
	searchWord(fileName);
	cout << endl;
	cout << "-----------------------------------" << endl;*/

	//////////////////////////////////////////////////
	
	traverseBST();
	cout << endl;
	cout << "Enter a word to delete" << endl;
       cin >> fileName;
	deleteWord(fileName);
	traverseBST();
	cout << endl;
	cout << "Enter a word to insert" << endl;
	cin >> fileName;
	InsertWord(fileName);
	traverseBST();


}
