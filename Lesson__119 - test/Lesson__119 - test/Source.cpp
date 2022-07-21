#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

/*Перегрузка операторов потокового ввода вывода >> <<
* Если перегрузить эти операторы, можно работать с объектами.
*
* Объекты того типа данных, для которого мы перегрузим эти операторы, мы можем как выводить в консоль, так и записывать в файл.
* Аналогично, как получать из консоли, так и получать(считывать) из файла.
*
* ostream, ofstream, ifstream, fstream связаны между собой по цепочке наследования. С помощью указателя на бвзовый класс
* fstream мы можем добраться до объектов остальных классов этой цепочки.
*
* При перегрузке оператора возвращаемое значение будет ссылка тот объект, который мы принимаем на входе(объект ostream).
* Первый принимаемый параметр - ссылка на объект ostream/его наследника. Вторым параметром мы передаем класс, для которого хотим
* перегрузить оператор << или >>(чтобы иметь возможность, к примеру, выводить наш объект на консоль).
* После отработки метода мы возаращем объект типа ostream/наследника.
* Синтаксис: ostream& operator<<(ostream& os, const Point& point) { return os }
*
* Каркас есть, логику такого оператора мы должны писать самостоятельно, исходя из задачи.
* Такую логику можно прописывать каждый раз, желая вывести объект на консоль. А можно всего один раз перегрузить оператор <<
* и все будет работать автоматически.
*
* ВАЖНО: насколько я понял, использование класса fstream в качестве сохранения/считывания данных ограничено. Либо одно, либо другое. 
* Вместе корретно не работают. Поэтому можно обойтись классами ofstream и ifstream. 
*
*/

class Point
{
public:
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Print()
	{
		cout << "X = " << x << " Y = " << y << " Z = " << z << endl;
	}
	friend ostream& operator<<(ostream& os, const Point& point);
	friend istream& operator>>(istream& is, Point& point);
	
private:
	int x;
	int y;
	int z;
};

ostream& operator<<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z; 
	return os;
}

istream& operator>>(istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string path = "test.txt";
	Point p(222, 112, 87);
	fstream fs;
	cout << p << endl;


	fs.open(path, fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		//fs << p << "\n";										

		while (!fs.eof())	//Экономим на ресурсах
		{
			Point p2;
			fs >> p2;
			if (fs.eof())
			{
				break;
			}
			cout << p2 << endl;
		}
		
	}

	fs.close();

	return 0;
}