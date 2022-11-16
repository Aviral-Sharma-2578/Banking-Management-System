#include <iostream>
#include <string>
using namespace std;


class bank
{
private:
	string name;
	int Account_no;
	double balance;


public:

	void OpenAccount() {
		cout << "Enter account number: ";
		cin >> Account_no;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter intial balance: ";
		cin >> balance;
	}

public:
	double getBal(int a) {
		return balance;
	}

	void setBal(int bal) {
		balance = bal;
	}

	void deposit(double amount)
	{
		balance += amount;
	}

	void withdraw(double amount)
	{
		balance -= amount;
	}

	int search(int a) {
		if (a == Account_no) {
			return 1;
		}
		return 0;
	}

	void details(int a) {
		if (a == Account_no) {
			cout << "Your current account balance is: " << balance << endl;
		}
	}

};

int main()
{
	bank X[3];
	int i = 0; int j = 0; int check = 0;

	for (int i = 0; i < 3; i++) {
		X[i].OpenAccount();
		cout << endl;
	}

	int ano;
	cout << endl;
	cout << "Enter account number: ";
	cin >> ano;
	int num;
	


	do {

		cout << endl << "Enter code for desired action: " << endl;
		cout << "Deposit: 1 \nWithdraw: 2\nTransfer: 3\nCheck balance of any user: 4\nExit: 5\n\n";

		cin >> num;

		switch (num)
		{
		case 1:
			cout << "Enter the amount: ";
			double amount;
			cin >> amount;
			cout << endl;
			for (int i = 0; i < 3; i++)
			{
				if (X[i].search(ano))
				{
					X[i].deposit(amount);
					X[i].details(ano);
					check = 1;
					break;
				}
			}
			if (!check) cout << "You may have entered invalid account number: ";
			break;

		case 2:
			cout << "Enter the amount: ";
			cin >> amount;
			cout << endl;
			for (int i = 0; i < 3; i++)
			{
				if (X[i].search(ano))
				{
					X[i].withdraw(amount);
					X[i].details(ano);
					check = 1;
					break;
				}
			}
			if (!check) cout << "You may have entered invalid account number: ";
			break;

		case 3:
			cout << "Enter the amount you want to transfer: ";
			cin >> amount;
			cout << "Enter account number of receiver: ";
			int AccNo;
			cin >> AccNo;
			cout << endl;
			while (i < 3)
			{
				if (X[i].search(ano))
				{
					bank sender = X[i];
					break;
				}
				i++;
			}
			while (j < 3)
			{
				if (X[j].search(AccNo))
				{
					bank receiver = X[j];
					check = 1;
					break;
				}
				j++;
			}
			X[i].withdraw(amount);
			X[j].deposit(amount);
			X[i].details(ano);
			if (!check) cout << "You may have entered invalid account number of receiver: ";
			break;


		case 4:
			cout << "Enter account number: ";
			cin >> ano;
			for (int i = 0; i < 3; i++) {
				if (X[i].search(ano))
				{
					cout << "User's current account balance is: " << X[i].getBal(ano) << endl;
					check = 1;
					break;
				}
			}
			if (!check) cout << "You may have entered invalid account number: ";
			break;

		case 5:
			cout << "Session terminated";
			break;

		default:
			cout << "Enter valid code!";
			break;
		}

	} while (num != 5);
	return 0;
}



