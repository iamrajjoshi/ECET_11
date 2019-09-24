//Lab 1_2
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include<iostream>
#include<string>
using namespace std;

class Invoice {
private:
	string description;
	string partNumber;
	int quantity;
	double price;

public:
	Invoice(string, string, int, double);
	string getDescription();
	void setDescription(string);
	string getPartNumber();
	void setPartNumber(string);
	int getQuantity();
	void setQuantity(int);
	double getPrice();
	void setPrice(double);
	double getInvoiceAmount();
};

Invoice::Invoice(string description, string partNumber, int quantity, double price) {
	setDescription(description);
	setPartNumber(partNumber);
	setQuantity(quantity);
	setPrice(price);
}

string Invoice::getDescription() {
	return description;
}

void Invoice::setDescription(string description) {
	this->description = description;
}

string Invoice::getPartNumber() {
	return partNumber;
}

void Invoice::setPartNumber(string partNumber) {
	this->partNumber = partNumber;
}

int Invoice::getQuantity() {
	return quantity;
}

void Invoice::setQuantity(int quantity) {
	this->quantity = (quantity < 0) ? 0 : quantity;
}

double Invoice::getPrice() {
	return price;
}

void Invoice::setPrice(double price) {
	this->price = (price < 0) ? 0 : price;
}

double Invoice::getInvoiceAmount() {
	return price * quantity;
}


int main() {
	string description;
	string partNumber;
	int quantity;
	double price;

	cout << "Enter part description: ";
	getline(cin, description);

	cout << "Enter part number: ";
	cin >> partNumber;

	cout << "Enter quantity: ";
	cin >> quantity;

	cout << "Enter price per item: ";
	cin >> price;

	Invoice inv = Invoice(description, partNumber, quantity, price);

	while (true) {
		char choice;
		cout << endl << "Would you like to (m)odify the invoice, (g)et a property, or (e)xit? ";
		cin >> choice;

		switch (choice) {
		case 'e':
			return 0;
			break;

		case 'm':
			cout << endl << "Would you like to modify the (d)escription, (p)art number, (q)uantity, p(r)ice per item, or (a)ll? ";
			cin >> choice;

			switch (choice) {
			case 'd':
				cout << "Enter new item description: ";
				cin.ignore();
				getline(cin, description);
				inv.setDescription(description);
				break;

			case 'p':
				cout << "Enter new part number: ";
				cin >> partNumber;
				inv.setPartNumber(partNumber);
				break;

			case 'r':
				cout << "Enter new price per item: ";
				cin >> price;
				inv.setPrice(price);
				break;

			case 'q':
				cout << "Enter new quantity: ";
				cin >> quantity;
				inv.setQuantity(quantity);
				break;
			case 'a':
				cout << "Enter new item description: ";
				cin.ignore();
				getline(cin, description);
				inv.setDescription(description);
				cout << "Enter new part number: ";
				cin >> partNumber;
				inv.setPartNumber(partNumber);
				cout << "Enter new price per item: ";
				cin >> price;
				inv.setPrice(price);
				cout << "Enter new quantity: ";
				cin >> quantity;
				inv.setQuantity(quantity);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
			}
			break;

		case 'g':
			cout << endl << "Would you like to get the (d)escription, (p)art number, (q)uantity, p(r)ice per item, (i)nvoice amount, or (a)ll? ";
			cin >> choice;
			cout << endl;

			switch (choice) {
			case 'd':
				cout << "Item description: " << inv.getDescription() << endl;
				break;

			case 'p':
				cout << "Part number: " << inv.getPartNumber() << endl;
				break;

			case 'r':
				cout << "Price per item: $" << inv.getPrice() << endl;
				break;

			case 'q':
				cout << "Quantity: " << inv.getQuantity() << endl;
				break;

			case 'i':
				cout << "Invoice amount: $" << inv.getInvoiceAmount() << endl;
				break;

			case 'a':
				cout << "Item description: " << inv.getDescription() << endl;
				cout << "Part number: " << inv.getPartNumber() << endl;
				cout << "Price per item: $" << inv.getPrice() << endl;
				cout << "Quantity: " << inv.getQuantity() << endl;
				cout << "Invoice amount: $" << inv.getInvoiceAmount() << endl;
				break;

			default:
				cout << "Invalid choice. Please try again." << endl;
			}
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return 0;
}

