#include <iostream>
#include <fstream>

const char* fileTxt = "points.txt";
const char* fileBin = "points.bat";

struct Point
{
	int x;
	int y;
};

void createPointArr(Point *& arr, int size)
{
	arr = new(std::nothrow) Point[size];
	if (!arr)
	{
		std::cerr << "Not enough memory!\n";
		return;
	}
}

void initializePointArr(Point *& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i].x;
		std::cin >> arr[i].y;
	}
}

void printPointArr(Point *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Point[" << i << "] = ";
		std::cout << "(" << arr[i].x << ", " << arr[i].y << ")\n";
	}
}

double getDistance(const Point& p1, const Point& p2)
{
	int deltaX = p1.x - p2.x;
	int deltaY = p1.y - p2.y;

	double result = sqrt(deltaX * deltaX + deltaY * deltaY);
	return result;
}

int64_t getFileSize(const char* fileName)
{
	std::ifstream in(fileName, std::ios::ate | std::ios::binary);
	if (!in.is_open())
	{
		std::cerr << "Cannot open file " << fileName << " for reading!";
		return 0;
	}

	int64_t size = in.tellg();
	in.close();
	return size;
}

void writePoints(Point* arr, int size, const char* fileName)
{
	std::ofstream os;
	os.open(fileName, std::ios::trunc);
	if (!os.good())
	{
		std::cerr << "Cannot open file " << fileName << " for writing!\n";
		return;
	}

	os << size << "\n";
	for (int i = 0; i < size; i++)
	{
		os << arr[i].x << ' ' << arr[i].y << ' ';
	}

	os.close();
}

Point* readPoints(int& size, const char* fileName)
{
	std::ifstream is;
	is.open(fileName);
	if (!is.good())
	{
		std::cerr << "Cannot open file " << fileName << " for reading!\n";
		return nullptr;
	}

	is >> size;
	Point* points;
	createPointArr(points, size);
	for (int i = 0; i < size; i++)
	{
		is >> points[i].x >> points[i].y;
	}

	is.close();

	return points;
}

void serialization(Point* arr, int size, const char* fileName)
{
	std::ofstream os(fileName, std::ios::binary | std::ios::trunc);
	if (!os.is_open())
	{
		std::cerr << "Cannot open file " << fileName << " for writing!\n";
		return;
	}

	for (int i = 0; i < size; i++)
	{
		os.write((const char*)&arr[i], sizeof(Point));
	}

	os.close();
}

Point* deserialization(int& size, const char* fileName)
{
	std::ifstream in(fileName, std::ios::binary);
	if (!in.is_open())
	{
		std::cerr << "Cannot open file " << fileName << " for reading!\n";
		return  nullptr;
	}

	// get the size of the array
	size = getFileSize(fileName) / sizeof(Point);

	Point* arr;
	createPointArr(arr, size);
	for (int i = 0; i < size; i++)
	{
		in.read((char*)& arr[i], sizeof(Point));
	}
	in.close();
	return arr;
}

int main()
{
	Point* points;
	int size = 3;
	std::cout << "Enter " << size << " points\n";
	
	createPointArr(points, size);
	initializePointArr(points, size);
	printPointArr(points, size);
	std::cout << "The distance between first two points is: " << 
		getDistance(points[0], points[1]) << "\n";

	// write Data
	writePoints(points, size, fileTxt);

	// read Data
	readPoints(size, fileTxt);

	serialization(points, size, fileBin);
	deserialization(size, fileBin);

	delete[] points;
	return 0;
}