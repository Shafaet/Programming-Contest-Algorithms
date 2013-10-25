    <CGraph Simulator, A simple graph algorithm simulator>
    Copyright (C) <2010-11>  <Shafaet Ashraf>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.




**Graph Algorithm Simulator**
-------------------------------

**Features**
-------------------------------
    Draw graphs with straight lines using drawing tools
    Load graphs from file. Save graphs for using later
    Autosave the graph after every change
    Move the nodes in your desired position
    Color the nodes,change level as you like
    Make your graph a wheel ,a ring or a bipartite graph automatically
    Make complement graph,complete graph in a single click
    Simulate common graph algorithms. See the next slide for algorithm related info
    Update cost of the edges
    Delete node or edges



**Supported Algorithms**
-------------------------------

	Kruskal’s minimum spanning tree:

	Simulate kruskal’s algorithm for finding mst and see how it works

	Depth First Search:

	“Cgraph Simulator” will simulate the dfs with colored line and will show you what actually happens when the algorithm runs.

	Breadth First Search:

	Run bfs and find single source shortest path(SSSP). Our simulator will show you exactly how it works

	Dijkstra:

	If the graph is weighted BFS won’t work. Simulate dijikstra to find SSSP.

	Floyed warshall:

	Our simulator will use floyed warshall to find apsp. As it is a complicated algorithm It wont visualize the simulation.

	Bellman ford:

	Find Negative weight cycle using this. This algorithm has resemblance to dijkstra.

	Optimal Graph Coloring

	Color the nodes in optimal way using backtrack and see how it works
	Finding Euler Circuit and path using backtrack

	Use backtrack to find euler circuit and path

	Limitation:

	The Simulator doesnt Support Directed graph yet.


**How to Run**
-----------------------

**Linux**
Install needed packages:

Ubuntu:
sudo apt-get install g++ geany
sudo apt-get install freeglut3 freeglut3-dev

Fedora:
yum install g++ freeglut-devel geany

Now compile main.cpp using following parameters:
-lglut -lGL -lGLU

**Windows**
Sorry, not supported yet.

Done!


**Author**
-----------------------
Shafaet Ashraf

Student,

Computer Science and Engineering, University of Dhaka, 

Bangladesh

This software was written as 1st year academic project in 2010.


