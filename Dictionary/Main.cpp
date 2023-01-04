#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>

using namespace std;
bool pred(const pair< string, int >& a, const pair< string, int >& b)
{
	return a.second < b.second;
}

int main()
{
	string str, Song = "text.txt", Song_form = "formated_dictionary.txt", Song_form_amount = "frequency_dictionary.txt";

	fstream fs;
	map<string, int> mp;

	const char symbols[] = { ',', '?', '\0' };

	try
	{
		fs.open(Song, fstream::in | fstream::out | fstream::app);

		while (!fs.eof())
		{
			str = "";
			fs >> str;
			for (int i = 0; i < strlen(symbols); ++i)
			{
				str.erase(remove(str.begin(), str.end(), symbols[i]), str.end());
			}
			++mp[str];
		}

		fs.close();
	}
	catch (const fstream::failure& ex)
	{
		cout << ex.code();
	}

	try
	{
		fs.open(Song_form_amount, fstream::in | fstream::out);

		cout << " =================================\n";
		cout << " ||       Word         || Amount||\n";
		cout << " =================================\n";

		vector< pair< string, int > > vec(mp.begin(), mp.end());
		sort(vec.rbegin(), vec.rend(), pred);
		for (auto p : vec)
		{
			fs << p.first << "\t" << p.second << "\n";
			cout << left << " ||" << setw(20) << p.first << "|| " << setw(5) << p.second << " || " << endl;
			cout << " =================================\n";
		}
		fs.close();
	}

	catch (const fstream::failure& ex)
	{
		cout << ex.code();
	}

}