#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class columns
{
public:
	void OpenFileToRead(string);
	void TransformToColumns();

private:
	fstream file;
	unsigned int numberOfSpaces, numberOfColumns, widthOfColumn, numberOfLines;
	vector<vector <string> > formattedtext;
	vector< string> row;
	string space_between;

	bool FileIsOpen;

	void GetInput();
	void WriteToFile();
	void AddSpaceBetween(int, int);

};