//Write a program to 0-1 Knapsack problem using the Branch and Bound method.
#include<iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Structure for Item which store weight and value
struct Item
{
	float weight;
	int value;
};

struct Node
{
	// level is the Level of node in decision tree
	// profit is Profit of nodes on path from root to this
	// node
	// bound is Upper bound of maximum profit in subtree
	int level, profit, bound;
	float weight;
};

// function to sort Items according to
// val/weight ratio
bool comparison(Item a, Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

// bound function Returns bound of profit
// in subtree rooted with u.
int bound(Node u, int n, int W, Item arr[])
{
	// if weight exceeds the knapsack capacity, return
	// 0
	if (u.weight >= W)
	{
       return 0;
	}
	// initialize bound on the profit by current profit
	int pro_bound = u.profit;

	// start including items from index 1 more to current
	// item index
	int j = u.level + 1;
	int totweight = u.weight;

	// checking bound condition and knapsack capacity
	// condition
	while ((j < n) && (totweight + arr[j].weight <= W))
	{
		totweight += arr[j].weight;
		pro_bound += arr[j].value;
		j++;
	}

	// If k is not n, include last item partially for
	// upper bound on profit
	if (j < n)
	{
       	pro_bound += (W - totweight) * arr[j].value /
						arr[j].weight;
	}
	return pro_bound;
}

int main()
{
	int W; // Weight of knapsack
	cout << "Enter weight of Knapsack: ";
	cin >> W;
	Item arr[] = {{1, 50}, {4.14, 60}, {3.98, 120}, {6, 90}, {4, 80}};
	int n = sizeof(arr) / sizeof(arr[0]);

    // Get starting timepoint
   auto start = high_resolution_clock::now();
    
	// sorting Item on basis of value per unit weight.
	sort(arr, arr + n, comparison);

	// making a queue for traversing the node
	queue<Node> Q;
	Node u, v;

	u.level = -1;
	u.profit = u.weight = 0;
	Q.push(u);

	int max_pro = 0;
	while (!Q.empty())
	{
		// Dequeue a particular node
		u = Q.front();
		Q.pop();

		if (u.level == -1)
			v.level = 0;

		// If nothing on next level
		if (u.level == n - 1)
			continue;

		v.level = u.level + 1;

		v.weight = u.weight + arr[v.level].weight;
		v.profit = u.profit + arr[v.level].value;

		// If total weight is less than W and
		// profit is more than previous profit,
		// update max_pro
		if (v.weight <= W && v.profit > max_pro)
			max_pro = v.profit;

		// Get the upper bound on profit to decide
		// whether to add v to Q or not.
		v.bound = bound(v, n, W, arr);

		// If bound value is greater than profit,
		// then only push into queue for further
		// consideration
		if (v.bound > max_pro)
			Q.push(v);

		// Follow the same thing, but Without taking
		// the item in knapsack
		v.weight = u.weight;
		v.profit = u.profit;
		v.bound = bound(v, n, W, arr);
		if (v.bound > max_pro)
			Q.push(v);
	}
	cout << "Maximum possible profit possible = "<< max_pro;
    
    // Get ending timepoint
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << "\nTime taken by function: "
         << duration.count()<< " microseconds" << endl;

	return 0;
}