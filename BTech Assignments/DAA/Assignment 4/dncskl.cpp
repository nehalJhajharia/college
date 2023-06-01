#include <iostream>
using namespace std;

// A structure for building
struct Building
{
	int left;
	int right;
	int ht;
};

// A strip in skyline
class Strip
{
	int left;
	int ht;

public:
	Strip(int l = 0, int h = 0)
	{
		left = l;
		ht = h;
	}
	friend class SkyLine;
};

// Skyline: To represent Output(An array of strips)
class SkyLine
{
	Strip *arr;	  // Array of strips
	int capacity; // Capacity of strip array
	int n;		  // Actual number of strips in array

public:
	~SkyLine() { delete[] arr; }
	int count() { return n; }

	// A function to merge another skyline to this skyline
	SkyLine *Merge(SkyLine *other);

	// Constructor
	SkyLine(int cap)
	{
		capacity = cap;
		arr = new Strip[cap];
		n = 0;
	}

	// Function to add a strip 'st' to array
	void append(Strip *st)
	{
		// Check for redundant strip
		// A strip is redundant if it has same height or left as previous
		if (n > 0 && arr[n - 1].ht == st->ht)
			return;
		if (n > 0 && arr[n - 1].left == st->left)
		{
			arr[n - 1].ht = max(arr[n - 1].ht, st->ht);
			return;
		}

		arr[n] = *st;
		n++;
	}

	// Print the skyline
	void print()
	{
		cout << "{ ";
		for (int i = 0; i < n; i++)
		{
			cout << "{" << arr[i].left << ", " << arr[i].ht << "} ";
		}
		cout << "}" << endl;
	}
};

SkyLine *findSkyline(Building arr[], int l, int h)
{
	if (l == h)
	{
		SkyLine *res = new SkyLine(2);
		res->append(
			new Strip(arr[l].left, arr[l].ht));
		res->append(
			new Strip(arr[l].right, 0));
		return res;
	}

	int mid = (l + h) / 2;

	// Recursion for left and right halves and merge the two results
	SkyLine *sl = findSkyline(arr, l, mid);
	SkyLine *sr = findSkyline(arr, mid + 1, h);
	SkyLine *res = sl->Merge(sr);

	delete sl;
	delete sr;

	return res;
}

SkyLine *SkyLine::Merge(SkyLine *other)
{
	// Create a resultant skyline with capacity as sum of two skylines
	SkyLine *res = new SkyLine(
		this->n + other->n);

	// To store current heights of two skylines
	int h1 = 0;
	int h2 = 0;

	// Indices of strips in two skylines
	int i = 0;
	int j = 0;
	while (i < this->n && j < other->n)
	{
		// Compare x coordinates of left sides of two skylines
		// Put the smaller one in result
		if (this->arr[i].left < other->arr[j].left)
		{
			int x1 = this->arr[i].left;
			h1 = this->arr[i].ht;

			int maxh = max(h1, h2);

			res->append(new Strip(x1, maxh));
			i++;
		}
		else
		{
			int x2 = other->arr[j].left;
			h2 = other->arr[j].ht;
			int maxh = max(h1, h2);
			res->append(new Strip(x2, maxh));
			j++;
		}
	}

	// If there are strips left in this skyline or other skyline
	while (i < this->n)
	{
		res->append(&arr[i]);
		i++;
	}
	while (j < other->n)
	{
		res->append(&other->arr[j]);
		j++;
	}
	return res;
}

int main()
{
	Building arr[] = {{33, 41, 5},
					  {4, 9, 21},
					  {30, 36, 9},
					  {14, 18, 11},
					  {2, 12, 14},
					  {34, 43, 19},
					  {23, 25, 8},
					  {14, 21, 16},
					  {32, 37, 12},
					  {7, 16, 7},
					  {24, 27, 10}};

	int N = sizeof(arr) / sizeof(arr[0]);

	SkyLine *ptr = findSkyline(arr, 0, N - 1);
	cout << " Skyline for given buildings is : " << endl;
	ptr->print();

	return 0;
}
// clang++ -std=c++17 dncskl.cpp
