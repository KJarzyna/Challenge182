#include <iostream>
#include "columns.h"

int main()
{
	columns text;

	text.OpenFileToRead("c182e-input.txt");
	text.TransformToColumns();

	getchar();
	return 0;
}