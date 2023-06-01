#include <vector>
#include <iostream>
#include <deque>
using namespace std;


int optimalMiss = 0;
// Function to check whether a page exists
// in a frame or not
bool search(int key, vector<int>& fr)
{
	for (int i = 0; i < fr.size(); i++)
		if (fr[i] == key)
			return true;
	return false;
}

// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int>& fr, int pn, int index)
{
	// Store the index of pages which are going
	// to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (fr[i] == pg[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		// If a page is never referenced in future,
		// return it.
		if (j == pn)
			return i;
	}

	// If all of the frames were not in future,
	// return any of them, we return 0. Otherwise
	// we return res.
	return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
	// Create an array for given number of
	// frames and initialize it as empty.
	vector<int> fr;

	// Traverse through page reference array
	// and check for miss and hit.
	int hit = 0;
	for (int i = 0; i < pn; i++) {
		// Page found in a frame : HIT
		if (search(pg[i], fr)) {
			hit++;
			continue;
		}

		// Page not found in a frame : MISS
		// If there is space available in frames.
		if (fr.size() < fn)
			fr.push_back(pg[i]);

		// Find the page to be replaced.
		else {
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
	}
	cout << "No. of hits (Optimal) = " << hit << endl;
	cout << "No. of misses (Optimal) = " << pn - hit << endl;
	optimalMiss = pn - hit;
}

int main()
{
	int fn;
	int n;
	cout << "Enter number of frames \n";
	cin >> fn;
	cout << "Enter number of sequence numbers (>10) \n";
	cin >> n;
	if (n<10)
	{
		cout << "Restart with more sequence numbers \n";
		return 0;
	}
	int pg[n];
	cout << "Enter the sequence numbers \n";
	int maxno = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> pg[i];
		maxno = max(maxno,pg[i]);
	}
	if (fn >= maxno)
	{
		cout << "Total number of frames should be less than highest sequence number \n";
		return 0;
	}
	optimalPage(pg, n, fn);
	deque<int> q(fn);
	int count = 0;
	int page_faults=0;
	deque<int>::iterator itr;
	q.clear();
	for(int j = 0; j < n; j++)
	{
		int i = pg[j];
		// Insert it into set if not present
		// already which represents page fault
		itr = find(q.begin(),q.end(),i);
		if(!(itr != q.end()))
		{
			++page_faults;
			if(q.size() == fn)
			{
				q.erase(q.begin());
				q.push_back(i);
			}
			else
			{
				q.push_back(i);
			}
		}
		else
		{
		// Remove the indexes page
			q.erase(itr);
		// insert the current page
			q.push_back(i);        
		}
	}
	cout << "No. of hits (LRU) = " << n - page_faults << endl;
	cout << "No. of misses (LRU) = " << page_faults << endl;
	if (optimalMiss > page_faults)
		cout << "No. of page faults in Optimal is more in this case \n";
	else
		cout << "No. of page faults in LRU is more in this case \n";
	return 0;
}

