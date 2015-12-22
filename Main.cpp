// Dijkstra's Algorithm
// Written to C++ by Martyr2
// Dream In Code

#include <iostream>
using namespace std;

// http://www.coderslexicon.com/dijkstras-algorithm-for-c/

// Define the levels of the graph
const int KOTA = 5;

// Prototype for our Dijkstra function
void Dijkstra(int *, int *, int[KOTA][KOTA]);

int main() {

	// Define a multidimensional array of lengths between points
	// Those designated -1 means no path exists beween those two points.
	// Think of this as a numeric table showing relationships.

	int L[KOTA][KOTA] = {
			/*     A   B   C   D   E  */
			/*A*/{0,  6,  6,  3, 999}, 
			/*B*/{999, 0, 999,  2,  4}, 
			/*C*/{999, 999, 0,  5,  1}, 
			/*D*/{999, 999, 999, 0,  4},
			/*E*/{999, 999, 999, 999, 0} 			
			};

	// An array to hold vertexes and full path distances
	int Vertexes[KOTA];
	int Dist[KOTA];

	// First we just set our vertexes to a count up to the number of
	// levels. Here we label vertexes 0 through 7 (thus 8 levels)
	for (int i = 0; i < KOTA; i++) {
		Vertexes[i] = i;
	}

	// Our first vertex is a starting vertex, so set it to one
	// and its distance will be 0.
	Vertexes[0] = -1;
	Dist[0] = 0;

	// Set the distances according to our levels array defined above.
	// Dist array keeps track of the legs and adds to them as we move through
	// paths of the graph
	for (int i = 1; i < KOTA; i++) {
		Dist[i] = L[0][i];
	}

	// Ok, lets start at level 1 and move to level 7
	// Each time we call our function to evaluate the following...

	// 1. What paths are available to us (we use the vertexes closes to our point)
	// 2. How far are they away?
	// 3. Take whichever is shortest path with the least cost.

	for (int curlevel = 1; curlevel < KOTA; curlevel++) {
		Dijkstra(Vertexes, Dist, L);
		cout << "Level " << curlevel << endl;

		// Just to show what the current distances are for each path as we
		// loop through the vertexs and evaluate.
		for (int i = 0; i < KOTA; i++) {
			cout << Dist[i] << " ";
		}
		cout << endl;

		// Show which vertexs have yet to be visted (-1 means visited)
		for (int i = 0; i < KOTA; i++) {
			cout <<Vertexes[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

// Dijkstra implements the algorithm for checking the vertexs and their
// relative path distances in relation to where we are in the graph.
void Dijkstra(int *Vertexes, int *Dist, int L[KOTA][KOTA]) {
	int minValue = 32767;
	int minNode = 0;

	// Loop through the vertexs to see if they have been visited
	// If they haven't, check their distance and see if it is smaller than
	// our current shortest distance. If so, set the new shortest distance
	// to minValue and label the node as the shortest
	for (int i = 0; i < KOTA; i++) {
		if (Vertexes[i] == -1) { continue; }
		if (Dist[i] > 0 && Dist[i] < minValue) {
			minValue = Dist[i];
			minNode = i;
		}
	}

	// Mark the new shortest distance vertex as visited
	Vertexes[minNode] = -1;

	// Add the distance to the overall path distance from start
	// to destination. The result is a list of values at the end which will
	// show the shortest paths between any two nodes. 
	for (int i = 0; i < KOTA; i++) {
		if (L[minNode][i] < 0) { continue; }
		if (Dist[i] < 0) {
			Dist[i] = minValue + L[minNode][i];
			continue;
		}
		if ((Dist[minNode] + L[minNode][i]) < Dist[i]) {
			Dist[i] = minValue + L[minNode][i];
		}
	}
}
