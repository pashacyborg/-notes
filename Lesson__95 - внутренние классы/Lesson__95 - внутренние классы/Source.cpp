#include <iostream>
#include <string>

using namespace std;

/*¬нутренний класс используют дл€ потребностей внешнего класса. ѕрелесть внутренних классов в том, что 
в программе может быть несколько классов с похожим названием.  огда мы вызываем внутренний класс записью 
им€_внешнего_класса::им€_внутреннего мы точно понимаем с каким классом имеем дело(с тем, который произошел
конкретно от этого внешнего класса). 
¬идимость класса Pixel зависит от того, в какой секции класса Image он находитс€. 
*/

class Image
{
private:
	class Pixel
	{
	private:
		int r;
		int g;
		int b;

	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}

		string GetInfo()
		{
			return "Pixel: r = " + to_string(r) + ", g = " + to_string(g) + ", b = " + to_string(b);
		}
	};

	static const int SIZE = 5;
	Pixel pixels[SIZE]
	{
		Pixel(10, 10, 10),
		Pixel(5, 12, 15),
		Pixel(15, 122, 255),
		Pixel(4, 12, 8),
		Pixel(5, 12, 10)
	};


public:
	class Pixel2
	{
	private:
		int r2;
		int g2;
		int b2;

	public:		//“от же класс, но в public секции
		Pixel2(int r2, int g2, int b2)
		{
			this->r2 = r2;
			this->g2 = g2;
			this->b2 = b2;
		}

		string GetInfo2()
		{
			return "Pixel: r2 = " + to_string(r2) + ", g2 = " + to_string(g2) + ", b2 = " + to_string(b2);
		}
	};

	Pixel2 pixels2[SIZE]
	{
		Pixel2(10, 10, 10),
		Pixel2(5, 12, 15),
		Pixel2(15, 122, 255),
		Pixel2(4, 12, 8),
		Pixel2(5, 12, 10)
	};

	void PrintInfoPixels()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "#" << i << " " << pixels[i].GetInfo() << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Image img;
	img.PrintInfoPixels();

	Image::Pixel2 pixel2(10, 20, 30);	//≈сли внутренний класс находитс€ в public
	cout << pixel2.GetInfo2() << endl;

	return 0;
}