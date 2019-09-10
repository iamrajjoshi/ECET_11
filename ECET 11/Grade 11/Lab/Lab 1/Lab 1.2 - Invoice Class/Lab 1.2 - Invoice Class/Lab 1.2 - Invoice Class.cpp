#include<iostream>
#include<string>
using namespace std;

class Invoice {
private:
	string description;
	int partNumber;
	int quantity;
	double price;

public:
	Invoice(string, int, int, double);
	string getDescription();
	void setDescription(string);
	int getPartNumber();
	void setPartNumber(int);
	int getQuantity();
	void setQuantity(int);
	double getPrice();
	void setPrice(double);
	double getInvoiceAmount();
};

Invoice::Invoice(string description, int partNumber, int quantity, double price) {
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

int Invoice::getPartNumber() {
	return partNumber;
}

void Invoice::setPartNumber(int partNumber) {
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
	int partNumber;
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
		cout << "Would you like to (m)odify the invoice, (g)et a property, or (e)xit?" << endl;
		cin >> choice;

		switch (choice) {
		case 'e':
			return 0;
			break;

		case 'm':
			cout << "Would you like to modify the (d)escription, (p)art number, (q)uantity, or p(r)ice per item?" << endl;
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

			default:
				cout << "Invalid choice. Please try again." << endl;
			}
			break;

		case 'g':
			cout << "Would you like to get the (d)escription, (p)art number, (q)uantity, p(r)ice per item, or (i)nvoice amount?" << endl;
			cin >> choice;
			choice = tolower(choice);
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