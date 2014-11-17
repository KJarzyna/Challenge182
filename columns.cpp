#include "columns.h"
#include <sstream>

void columns::OpenFileToRead(string filepath)
{
	file.open(filepath);

	if (file.good())
	{
		cout << "FIle opened successfuly!" << endl;
		FileIsOpen = true;
	}

	else 
	{
		cout << "Cannot open file!" << endl;
		FileIsOpen = false;
	}
}

void columns::GetInput()
{
	if(FileIsOpen)
	{
		file >> numberOfColumns >> widthOfColumn >> numberOfSpaces;
	}
}

void columns::TransformToColumns()
{
	if(FileIsOpen)
	{
		GetInput();

		unsigned int space_pos = 0;
		unsigned int start = 0;
		unsigned int numberOfWords = 0;
		string line;
		string new_line;
		string full_file;

		while(!file.eof())
		{
			getline(file,line);
			full_file += line;
		}


		for(int n=full_file.size()-2;n>0;n--)
		{
			if(full_file[n]=='.')
			{
				if(full_file[n+1]!=' ')
				{
					full_file.insert(n+1," ");
				}
			}
		}

		numberOfLines = 0;

		while(space_pos!=string::npos)
		{
			line = full_file.substr(start, widthOfColumn+1);
			space_pos = line.rfind(' ');
			new_line = full_file.substr(start,space_pos);
			start += space_pos + 1;
			numberOfLines++;
		}

		start = 0;

		for(int k=0;k<numberOfColumns;k++)
		{
			for(int n=0;n<numberOfLines/numberOfColumns;n++)
			{
			line = full_file.substr(start, widthOfColumn+1);
			space_pos = line.rfind(' ');
			new_line = full_file.substr(start,space_pos);
			row.push_back(new_line);
			start += space_pos + 1;
			}

			formattedtext.push_back(row);
			row.clear();
		}

		WriteToFile();

		file.close();
	}
}

void columns::WriteToFile()
{
	ofstream new_file("transformed_text.txt");

	for(int i=0;i<numberOfLines/numberOfColumns;i++)
	{
		for(int j=0;j<numberOfColumns;j++)
		{
			AddSpaceBetween(i, j);
			new_file << formattedtext[j][i] << space_between;
		}

		new_file << endl;

	}

	new_file.close();
}

void columns::AddSpaceBetween(int i, int j)
{
	space_between = "";
			if(formattedtext[j][i].size()<widthOfColumn)
			{
				for(int n = 0; n<(widthOfColumn - formattedtext[j][i].size()); n++)
				{
					space_between += " ";
				}


				for(int n=0;n<numberOfSpaces;n++)
				{
					space_between += ' ';
				}
			}
			else
				for(int n=0;n<numberOfSpaces;n++)
				{
					space_between += ' ';
				}
}



	//for(int k=0;k<numberOfColumns;k++)
	//{
	//	for(int n=0;n<numberOfLines;n++)
	//	{
	//		line = full_file.substr(start, widthOfColumn+1);
	//		space_pos = line.rfind(' ');
	//		new_line = full_file.substr(start,space_pos);
	//		row.push_back(new_line);
	//		start += space_pos + 1;
	//	}

	//	formattedtext.push_back(row);
	//	row.clear();
	//}