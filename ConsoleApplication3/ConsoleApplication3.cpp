#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <conio.h>
#include <filesystem>
#include <vector>
#include <Windows.h>
using namespace std;
namespace fs = filesystem;

string filename;

string GetDir()
{
	char result[MAX_PATH];
	return string(result, GetModuleFileName(NULL, result, MAX_PATH));
}
string path = GetDir();

static void FileSelection()
{
	
	cout << "Enter thy scroll moniker:" << endl;
	cin >> filename;
	cout << endl;
	filename = filename + ".txt";
}

static void WriteInFile()
{
	FileSelection();
	ofstream operatedfile(filename);
	string inputtext;
	if (!operatedfile.is_open())
	{
		cerr << "Scroll hath failed to unveil" << endl;
	}
	cout << "Write mode, enter 'I hath finished' to finish your creation" << endl;
	while (true)
	{
		getline(cin, inputtext);
		if (inputtext == "I hath finished")
		{
			cout << "Closing file" << endl;
			break;
		}
		operatedfile << inputtext << endl;
		cout << "Text modified. \n";
	}
	operatedfile.close();
}

static void CreateFile()
{
	FileSelection();
	ofstream operatedfile(filename);
	operatedfile << "Scroll made \n";
	operatedfile.close();
}

static void ReadFile()
{
	FileSelection();
	ifstream operatedfile(filename);
	if (!operatedfile.is_open())
	{
		cerr << "Scroll hath failed to unveil" << endl;
	}
	cout << "Read mode" << endl;
	string displayText;
	while (getline(operatedfile, displayText))
	{
		cout << displayText << endl;
	}
	operatedfile.close();
}

static void DisplayFiles()
{
	cout << "Scrolls in giveth compartment: " << endl;
	for (const auto& entry : fs::directory_iterator(path))
		cout << entry.path() << endl;
}

void FileOperations()
{
	char selection;
	cout << "Select operation:" << endl;
	cout << "1 - Read file" << endl;
	cout << "2 - Overwrite file" << endl;

	do {
		selection = _getche();
		cout << endl;
		switch (selection)
		{
		case '0':
			FileSelection();
		case '1':
			ReadFile();
			break;
		case '2':
			WriteInFile();
			break;
		default:
			cout << "Selection error" << endl;
			break;
		}
	} while (selection != '9');

}

void menu()
{
	char opt;
		do {
			cout << "What does thy seek?" << endl;
			cout << "d - discover all scrolls in giveth compartment" << endl;
			cout << "r - read giveth scroll" << endl;
			cout << "c - create a new scroll " << endl;

			opt = _getche();
			std::cout << "\n";

			switch (opt) {
			case 'd':
				DisplayFiles();
				break;

			case 'r':
				ReadFile();
				break;

			case 'c':
				WriteInFile();
				break;

			default:

				break;
			}

		} while (opt != '0');
}
int main()
{
	menu();
	return 0;
}