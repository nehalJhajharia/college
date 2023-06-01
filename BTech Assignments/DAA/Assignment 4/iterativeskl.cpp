#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to create skyline
vector<pair<int, int> > createSkyline(vector<vector<int> > &buildings)
{
	int N = buildings.size(); // Number of buildings

	// Store the left and right wall positions of the buildings
	vector<pair<int, int> > wall;

	// Building structure parameters
	int left = 0;
	int height = 0;
	int right = 0;
	for (int i = 0; i < N; i++) 
	{
		left = buildings[i][0];
		height = buildings[i][2];
		right = buildings[i][1];

		wall.push_back({left, -height});
		wall.push_back(make_pair(right, height));
	}

	// Sort the walls in ascending order
	sort(wall.begin(), wall.end());

	vector<pair<int, int> > skyline;

	// Initialize a multiset to keep left wall heights sorted
	multiset<int> leftWallHeight = {0};

	// Current max height among leftWallHeights
	int top = 0;

	// Traverse through the sorted walls
	for (auto w : wall) 
	{
		if (w.second < 0) // If left wall is found
		{
			// Insert the height
			leftWallHeight.insert(-w.second);
		}

		else // If right wall is found
		{
			// Remove the height
			leftWallHeight.erase(leftWallHeight.find(w.second));
		}

		// Mark a skyline point if top changes
		// .rbegin():reverse iterator
		if (*leftWallHeight.rbegin() != top) 
		{
			top = *leftWallHeight.rbegin();
			skyline.push_back(
				make_pair(w.first, top));
		}
	}

	return skyline;
}

// Function to print the output skyline
void printSkyline(vector<vector<int> > &buildings)
{
	vector<pair<int, int> > skyline = createSkyline(buildings);

	cout << "Skyline for given buildings: " << endl;
	cout << "{ ";
	for (auto it:skyline) 
	{
		cout << "{" << it.first << ", " << it.second << "} ";
	}
	cout << "}" << endl;
}

int main()
{
	vector<vector<int> > buildings;

	buildings = {{33, 41, 5}, 
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

	printSkyline(buildings);

	return 0;
}
// clang++ -std=c++17 iterativeskl.cpp
