#pragma warning (disable: 4996);
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include<vector>
#include "Function.h"

using namespace std;

enum enOption { Quick_Withdraw = 1, Normal_Withdraw = 2, Deposit = 3, Check_Balance = 4, Logout = 5 };

enum enQuickWithdraw { Withdraw_20 = 1, Withdraw_50 = 2, Withdraw_100 = 3, Withdraw_200 = 4, Withdraw_400 = 5, Withdraw_600 = 6, Withdraw_800 = 7, Withdraw_1000 = 8, Withdraw_Exit = 9 };

struct stClient
{
	string name, accounNumber, pinCode, phone;
	double accountBalance;
};

const string clientsFile = "Clients.txt";

void BackToMainMenue();
void ShowMainMenue();
void QuickWithdrawScreen();
void Login();

stClient currentClient;

vector<string> SpiltFunction(string line, string separator)
{
	vector<string> vClient;
	short pos = 0;
	string sWord = "";

	while ((pos = line.find(separator)) != std::string::npos)
	{
		sWord = line.substr(0, pos);

		if (sWord != separator)
		{
			vClient.push_back(sWord);
		}

		line = line.erase(0, pos + separator.length());
	}

	if (line != separator)
	{
		vClient.push_back(line);
	}

	return vClient;
}

stClient ConvertLineToRecord(string line)
{
	vector<string> vClient;
	stClient clientData;

	vClient = SpiltFunction(line, "#//#");

	clientData.accounNumber = vClient[0];
	clientData.pinCode = vClient[1];
	clientData.name = vClient[2];
	clientData.phone = vClient[3];
	clientData.accountBalance = stod(vClient[4]);

	return clientData;
}

vector<stClient> LoadDataFromFile(string fileName)
{
	fstream clientFile;
	vector<stClient> vClient;

	clientFile.open(fileName, ios::in);

	if (clientFile.is_open())
	{
		string line;
		stClient clientData;

		while (getline(clientFile, line))
		{
			clientData = ConvertLineToRecord(line);
			vClient.push_back(clientData);
		}

		clientFile.close();
	}
	return vClient;
}

bool CheckLogin(string accountNumber, string pinCode)
{
	vector<stClient> vClient = LoadDataFromFile(clientsFile);

	for (stClient& cData : vClient)
	{
		if (cData.accounNumber == accountNumber && cData.pinCode == pinCode)
		{
			currentClient = cData;

			return true;
		}
	}
	return false;
}

void CheckBalance()
{
	cout << "\n-----------------------------------------------\n";
	cout << "\t\tCheck Balance Screen";
	cout << "\n-----------------------------------------------\n";

	cout << "\nYour Balance is : " << ::currentClient.accountBalance;
}

string ConvertRecordToLine(stClient clientData)
{
	string line = "";

	line += clientData.accounNumber + "#//#";
	line += clientData.pinCode + "#//#";
	line += clientData.name + "#//#";
	line += clientData.phone + "#//#";
	line += to_string(clientData.accountBalance);

	return line;
}

void SaveClientData(vector<stClient>& vClient)
{
	fstream clientFile;

	clientFile.open(clientsFile, ios::out);

	if (clientFile.is_open())
	{
		string line;

		for (stClient& cData : vClient)
		{
			line = ConvertRecordToLine(cData);
			clientFile << line << endl;
		}

		clientFile.close();
	}
}

void ChooseWithdrawOption(enQuickWithdraw option, vector<stClient>& vClient)
{
	string answer = "n";

	for (stClient& clientData : vClient)
	{
		if (clientData.accounNumber == currentClient.accounNumber && clientData.pinCode == currentClient.pinCode)
		{
			switch (option)
			{
			case::Withdraw_20:
			{
				if (clientData.accountBalance >= ::Withdraw_20)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 20;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case::Withdraw_50:
			{
				if (clientData.accountBalance >= ::Withdraw_50)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 50;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case::Withdraw_100:
			{
				if (clientData.accountBalance >= ::Withdraw_100)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 100;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case ::Withdraw_200:
			{
				if (clientData.accountBalance >= ::Withdraw_200)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 200;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case ::Withdraw_400:
			{
				if (clientData.accountBalance >= ::Withdraw_400)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 400;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case ::Withdraw_800:
			{
				if (clientData.accountBalance >= ::Withdraw_800)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 800;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case::Withdraw_1000:
			{
				if (clientData.accountBalance >= ::Withdraw_1000)
				{
					cout << "\nAre you sure you want to perform this transaction? Y/N?";
					cin >> answer;

					if (answer == "y" || answer == "Y")
					{
						clientData.accountBalance -= 1000;
						SaveClientData(vClient);
						cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
						currentClient = clientData;
					}
				}
				else
				{
					cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
					system("pause");
					void QuickWithdrawScreen();
				}
				break;
			}
			case ::Withdraw_Exit:
			{
				ShowMainMenue();
				break;
			}
			}
		}
	}
}

void ReadWithdraw()
{
	short withdrawOption = 0;

	cout << "\nYour Balance is : " << currentClient.accountBalance << endl;
	
	while (withdrawOption<1||withdrawOption>9)
	{
		cout << "\nChoose what to do from [1] to [8]: ";
		cin >> withdrawOption;
	}

	vector<stClient> vClient = LoadDataFromFile(clientsFile);

	ChooseWithdrawOption((enQuickWithdraw)withdrawOption, vClient);
}

void QuickWithdrawScreen()
{
	cout << "\n-----------------------------------------------\n";
	cout << "\t\tQuick Withdraw Screen";
	cout << "\n-----------------------------------------------\n";
	cout << "\t[1] 20\t\t[2] 50\n";
	cout << "\t[3] 100\t\t[4] 200\n";
	cout << "\t[5] 400\t\t[6] 600\n";
	cout << "\t[7] 800\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "\n-----------------------------------------------\n";

	ReadWithdraw();
}

void NormalWithdrawScreen()
{
	vector<stClient> vClient = LoadDataFromFile(clientsFile);

	string answer = "n";
	int normalWithdraw = 0;
	bool end = false;

	cout << "\n-----------------------------------------------\n";
	cout << "\t\tNormal Withdraw Screen";
	cout << "\n-----------------------------------------------\n";

	cout << "\nYour Balance is : " << ::currentClient.accountBalance<<"\n";

	do
	{
		cout << "\nEnter an amount multiply of 5's? ";
		cin >> normalWithdraw;

		if (normalWithdraw % 5 == 0)
		{
			for (stClient& clientData : vClient)
			{
				if (clientData.accounNumber == currentClient.accounNumber && clientData.pinCode == currentClient.pinCode)
				{
					if (clientData.accountBalance >= normalWithdraw)
					{
						cout << "\nAre you sure you want to perform this transaction? Y/N?";
						cin >> answer;

						if (answer == "y" || answer == "Y")
						{
							clientData.accountBalance -= normalWithdraw;
							SaveClientData(vClient);
							cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
							currentClient = clientData;

						}
					}
					else
					{
						cout << "\n\nThe amount exceeds you balance, Make another choice.\n";
						system("pause");
						system("cls");
						NormalWithdrawScreen();
					}
				}
			}
		}
		else
		{
			end = true;
		}
	} while (end);
}

void DepositScreen()
{
	vector<stClient> vClient = LoadDataFromFile(clientsFile);

	string answer = "n";
	int deposit = 0;

	cout << "\n-----------------------------------------------\n";
	cout << "\t\tDeposit Screen";
	cout << "\n-----------------------------------------------\n";

	cout << "\nYour Balance is : " << ::currentClient.accountBalance << "\n";
	
	cout << "\nEnter a positive Deposit Amount? ";
	cin >> deposit;

	while (deposit<0)
	{
		cout << "\nEnter a positive Deposit Amount? ";
		cin >> deposit;
	}
	for (stClient& clientData : vClient)
	{
		if (clientData.accounNumber == currentClient.accounNumber && clientData.pinCode == currentClient.pinCode)
		{

			cout << "\nAre you sure you want to perform this transaction? Y/N?";
			cin >> answer;

			if (answer == "y" || answer == "Y")
			{
				clientData.accountBalance += deposit;
				SaveClientData(vClient);
				cout << "\nDone Successfully, New Balance is: " << clientData.accountBalance << endl;
				currentClient = clientData;
			}
		}
	}

}

void RunOption(enOption Option)
{
	switch (Option)
	{

	case ::Quick_Withdraw:
	{
		system("cls");
		QuickWithdrawScreen();
		BackToMainMenue();
		break;
	}
	case ::Normal_Withdraw:
	{
		system("cls");
	    NormalWithdrawScreen();
		BackToMainMenue();
		break;
	}
	case ::Deposit:
	{
		system("cls");
		DepositScreen();
		BackToMainMenue();
		break;
	}
	case ::Check_Balance:
	{
		system("cls");
		CheckBalance();
		BackToMainMenue();
		break;
	}
	case ::Logout:
	{
		system("cls");
		Login();
	}

	}
}

void ReadMainMenueOption()
{
	short answer = 0;

	cout << "\nChoose what do you want to do? [1 to 5]? ";
	cin >> answer;

	RunOption((enOption)answer);
}

void ShowMainMenue()
{
	cout << "\n-----------------------------------------------\n";
	cout << "\t\tATM Main Menue Screen";
	cout << "\n-----------------------------------------------\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "\n-----------------------------------------------\n";

	ReadMainMenueOption();
}

void BackToMainMenue()
{
	cout << "\n\nPlease press any key to go back to Main Menue......";

	system("pause>0");

	system("cls");

	ShowMainMenue();
}

void Login()
{
	bool checkLogin = false;

	system("cls");

	cout << "\n-----------------------------------------------\n";
	cout << "\t\tLogin Screen";
	cout << "\n-----------------------------------------------\n";

	do
	{
		if (checkLogin)
		{
			cout << "\nInvalid userNumber/pinCode!\n\n";
		}
		string accountNumber = Function::ReadString("Enter accountNumber? ");

		string pinCode = Function::ReadString("\nEnter pinCode? ");

		if (!CheckLogin(accountNumber, pinCode))
		{
			checkLogin = true;
		}
		else
		{
			checkLogin = false;
		}

	} while (checkLogin);

	system("cls");
	ShowMainMenue();
}

int main()
{
	Login();

	system("pause>0");
}