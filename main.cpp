////////////////////Todo Management System/////////////
///////////////////////////Header Files////////////////
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <cstddef>
#include <conio.h>

using namespace std;

/////////////////Function Declaration/////////////////
void cpascode();
/////////////////////class item///////////////////////
class Item
{
public:
	Item();
	Item(string);
	~Item();

	string text();
	void done();
	bool is_done();

	bool operator==(Item&);

private:
	string _text;
	bool _done;

	string str_tolower(string);
};
///////////////////////
Item::Item()
{
	_text = "";
	_done = false;
}

Item::Item(string item)
{
	int startf = item.find("false");
	int startt = item.find("true");
	string str;

	if (startf > -1 && startt == -1) // item has false
	{
		str = item.substr(0, startf - 1);
		_done = false;
	} else if (startt > -1 && startf == -1) { // item has true
		str = item.substr(0, startt - 1);
		_done = true;
	} else if (startf == -1 && startt == -1) { // item is user input (no true or false)
		str = item;
		_done = false;
	}

	_text = str;
}

Item::~Item()
{
	// do nothing
}

string Item::text()
{
	return _text;
}

void Item::done()
{
	_done = true;
}

bool Item::is_done()
{
	return _done;
}

string Item::str_tolower(string str)
{
	string temp = str;
	for (int i = 0; i < temp.size(); ++i)
		temp[i] = tolower(temp[i]);
	return temp;
}

bool Item::operator==(Item& other)
{
	bool text_equal = str_tolower(_text) == str_tolower(other.text());
	bool done_equal = _done == other.is_done();
	return text_equal && done_equal;
}
/////////////////////class TodoList//////////////////
class TodoList
{
public:
	TodoList();
	TodoList(const char*);
	~TodoList();

	void read();
	void display();
	void create();
	void save();
	void add();
	void clear();
	void check();

	int get_count();

private:
	const char* filename;
	vector<Item> list;
};

////////////////////////////////////////

TodoList::TodoList()
{
	filename = nullptr;
}

TodoList::TodoList(const char* filename)
{
	this->filename = filename;
}

TodoList::~TodoList()
{
	// do nothing
}

void TodoList::read()
{
	fstream fs(filename, fstream::in);
	string line;

	list.clear();

	while(getline(fs, line))
	{
		if (line == "") continue;
		Item item(line);
		list.push_back(item);
	}

	fs.close();
}

void TodoList::display()
{
	cout << "Your todo list: " << endl << endl;

	const int W = 40;
	cout << "   " << setw(W) << left << "TASK" << "DONE" << endl;
	cout << "   " << setw(W) << left << "----" << "----" << endl;
	for (int i = 0; i < list.size(); ++i)
	cout << i + 1 << ") " << setw(W) << left << list[i].text() << (list[i].is_done() ? "Done" : "" ) << endl;
}

void TodoList::create()
{
	bool is_finished = false;
	int count = 1;
	string task;

	list.clear();

	while(!is_finished)
	{
		cout << count << ": ";

		getline(cin, task);
		if (task == "") is_finished = true;

		Item item(task);
		list.push_back(item);
		count++;
	}
}

void TodoList::save()
{
	fstream fs(filename, fstream::out);

	for (Item item : list)
	{
		if (item.text().empty()) continue;
		fs << item.text() << " " << (item.is_done() ? "true" : "false") << endl;
	}

	fs.close();
}

int TodoList::get_count()
{
	return list.size();
}

void TodoList::add()
{
	int index = list.size();
	while (true)
	{
		cout << ++index << " : ";

		string task;
		getline(cin, task);
		if (task == "") break;

		Item item(task);
		list.push_back(item);
	}

	save();
}

void TodoList::clear()
{
	list.clear();
	remove(filename);
}

void TodoList::check()
{
	cout << "Enter number of task: ";

	string choice;
	getline(cin, choice);

	if (choice.empty()) return;
	for (char c : choice) if (isalpha(c)) return;

	int index = stoi(choice) - 1;
	if (index > list.size()) return;
	list[index].done();

	save();
}
////////////////menu function//////////////
void menu()
{
    TodoList tasks("list.txt");

	while(1)
	{
		tasks.read();

		if (tasks.get_count() > 0)
		{
			tasks.display();
			cout << endl;

			cout << "1)  Add  Item" << endl;
			cout << "2) Clear Item" << endl;
			cout << "3) Check Item" << endl;
			cout << "4) for Checking Password or Create password   :\n\n";
			cout << "Choice : ";

			string choice;
			getline(cin, choice);

			if (choice == "1")
			{
				tasks.add();
			} else if (choice == "2") {
				tasks.clear();
			} else if (choice == "3") {
				tasks.check();
			} else if (choice == "4") {
                cpascode();
			}   else {
				break;
			}

		} else {
			cout << "Created a new list .." << endl;
			tasks.create();

			cout << endl;
			tasks.display();

			tasks.save();
		}
	}
}
//////////////password functions/////////////
void cpascode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\tEnter The New password ";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\n\your Password has been saved : ";
    getch();
    system("cls");
    menu();
}

void pascode()
{
    system("cls");
    char p1[50],p2[50];


    system("color Fc");

     ifstream in("password.txt");
     {
         cin.sync();

         cout<<"\n\n\n\n\n\n\n\t\t\tEnter the Password: ";
         cin.getline(p1,50);
         in.getline(p2,50);
         if(strcmp(p2,p1)==0)

         {
             system("cls");
             menu();
         }
         else
        {

            cout<<"\n\n\t\t\tIncorrect Password Please Try Again\n";
            Sleep(999);
            pascode();
        }
     }
     in.close();
}


/////////////////////main////////////////////////
int main(int argc, char const *argv[])
{
    pascode();
    system("pause");


	return 0;
}
