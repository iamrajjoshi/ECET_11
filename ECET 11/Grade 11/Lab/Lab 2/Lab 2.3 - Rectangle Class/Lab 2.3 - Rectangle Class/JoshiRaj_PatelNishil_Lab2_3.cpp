//Lab 2_3
//Raj Joshi & Nishil Patel
//Written by Nishil Patel
//Edited by Raj Joshi

#include <iostream>
#include<cmath>
using namespace std;

class Rectangle
{
	int coord[8];
	float length, width;
	int corn[2];
	char filler = '*';
	bool validCoords(int[8]);
	void setCoords(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
public:
	Rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
	void draw();
	void setFillCharacter(char);
	void scale(float);
	bool valid = false;
	bool isSquare();
	float area();
	float getLength();
	float getWidth();
};

float Rectangle::area() { return length * width; }
float Rectangle::getLength() {
	if (length > width)
		return length;
	return width;
}
float Rectangle::getWidth() {
	if (length < width)
		return length;
	return width;
}
bool Rectangle::validCoords(int temp[8])
{
	int xlow, xhigh, ylow, yhigh;
	for (int i = 0; i < 8; i++)
	{
		if (temp[i] > 20 || temp[i] < 0)
			return false;
	}

	int rep = 0;
	int other = -1;
	for (int i = 0; i < 4; i++)
	{

		int base = temp[0];
		if (temp[i] == base)
			rep++;
		else if (other == -1)
		{
			other = temp[i];
		}
		else if (temp[i] != other)
		{
			return false;
		}


	}

	if (rep != 2)
	{
		return false;
	}

	if (other > temp[0])
	{
		xhigh = other; xlow = temp[0];
	}
	else
	{
		xhigh = temp[0]; xlow = other;
	}
	rep = 0;
	other = -1;
	for (int i = 4; i < 8; i++)
	{
		int base = temp[4];
		if (temp[i] == base)
			rep++;
		else if (other == -1)
		{
			other = temp[i];
		}
		else if (temp[i] != other)
		{
			return false;
		}


	}

	if (rep != 2)
	{
		return false;
	}

	if (other > temp[4])
	{
		yhigh = other; ylow = temp[4];
	}
	else
	{
		yhigh = temp[4]; ylow = other;
	}

	corn[0] = xlow; corn[1] = yhigh;
	width = xhigh - xlow;
	length = yhigh - ylow;
	return true;
}

void Rectangle::setCoords(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
	int temparray[8] = { x1,x2,x3,x4,y1,y2,y3,y4 };
	if (validCoords(temparray))
	{
		for (int i = 0; i < 8; i++)
		{
			coord[i] = temparray[i];
			valid = true;
		}
	}


}

Rectangle::Rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
	setCoords(x1, x2, x3, x4, y1, y2, y3, y4);
}

void Rectangle::draw()
{
	for (int i = 0; i < round(length); i++)
	{
		for (int j = 0; j < round(width); j++)
		{
			cout << filler;
		}
		cout << endl;
	}
	cout << endl;
}

void Rectangle::setFillCharacter(char c)
{
	filler = c;
}
void Rectangle::scale(float f)
{
	length *= abs(f);
	width *= abs(f);
}

bool Rectangle::isSquare()
{
	return width == length;
}

int main()
{
	while (true)
	{

		bool cond;
		int x1, x2, x3, x4, y1, y2, y3, y4;
		cout << "Enter Integer Coords as: x1 y1 x2 y2 x3 y3 x4 y4\n\n";
		do
		{
			cout << "Enter Coords: ";
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
			Rectangle rect(x1, x2, x3, x4, y1, y2, y3, y4);
			cond = rect.valid;
			system("cls");
			if (!cond)
				cout << "Invalid Entry!\n\n";

		} while (!cond);

		Rectangle rect(x1, x2, x3, x4, y1, y2, y3, y4);
		while (true)
		{
			system("cls");
			cout << "Rectangle Created!" << endl << "Length: " << rect.getLength() << " Width: " << rect.getWidth();
			
			cout << " Area: " << rect.area() << endl;
			cout << "Is Square? - ";
			if (rect.isSquare())
				cout << "True" << endl;
			else
				cout << "False" << endl;
			int opt;

			cout << "\nChoose an Operation (invalid integers defualts to display):\n1)Display\n2)Scale Size\n3)Set Display Character\n4)Done! - Make a new Rectangle!";
			cout << "\nOperation: ";
			cin >> opt;
			if (opt == 4) {
				system("cls");
				break;

			}
				
			switch (opt)
			{
			case 2:
				system("cls");
				float scale;
				cout << "Scale by (decimal number, display will be rounded): ";
				cin >> scale;
				rect.scale(scale);
				break;
			case 3:
				system("cls");
				char fill;
				cout << "Fill Character: ";
				cin >> fill;
				rect.setFillCharacter(fill);
				break;
			default:
				system("cls");
				rect.draw();
				cout << endl << "Length: " << rect.getLength() << " Width: " << rect.getWidth();
				cout << " Area: " << rect.area() << endl;
				system("PAUSE");
				break;
			}

		}
	}
}