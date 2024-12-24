#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
// 7 âàğ -> 17

class EncryptClass
{
private:
	string alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß .";
	static const int ROWS = 5;
	static const int COLS = 7;

	vector<vector<char>> table1;
	vector<vector<char>> table2;

	void generateTables()
	{
		vector<char> characters(alphabet.begin(), alphabet.end());
		random_shuffle(characters.begin(), characters.end());

		vector<vector<char>> table1(ROWS, vector<char>(COLS, ' '));
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
			{
				table1[i][j] = characters[i * COLS + j];
			}
		}
		this->table1 = table1;

		random_shuffle(characters.begin(), characters.end());

		vector<vector<char>> table2(ROWS, vector<char>(COLS, ' '));
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
			{
				table2[i][j] = characters[i * COLS + j];
			}
		}
		this->table2 = table2;
	}

	pair<int, int> findPosition(const vector<vector<char>>& table, char c)
	{
		for (int i = 0; i < ROWS; ++i) 
		{
			for (int j = 0; j < COLS; ++j) 
			{
				if (table[i][j] == c) 
				{
					return { i, j };
				}
			}
		}
		throw runtime_error("Character not found in table.");
	}

public:

	EncryptClass()
	{
		generateTables();
	}

	string encrypt(const string& text) 
	{
		string encryptedText;
		for (char c : text)
		{
			pair<int, int> pos1 = findPosition(table1, c);
			char encryptedChar = table2[pos1.first][pos1.second];
			encryptedText += encryptedChar;
		}
		return encryptedText;
	}

	string decrypt(const string& encryptedMessage) 
	{
		string decryptedText;
		for (char c : encryptedMessage) 
		{
			pair<int, int> pos2 = findPosition(table2, c);
			char decryptedChar = table1[pos2.first][pos2.second];
			decryptedText += decryptedChar;
		}
		return decryptedText;
	}
};

int main()
{
	srand(time(0));
	system("chcp 1251");
	system("cls");

	EncryptClass a;
	string text = "ÇÈÌÍßß ÑÒÓÆÀ";

	string encryptedText = a.encrypt(text);
	cout << "Çàøèôğîâàííûé òåêñò: " << encryptedText << endl;
	string decryptedText = a.decrypt(encryptedText);
	cout << "Ğàñøèôğîâàííûé òåêñò: " << decryptedText << endl;
}