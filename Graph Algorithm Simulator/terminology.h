void show_terms()
{
	COLOR_DBLUE;
	class_SHAPE.FILLED_RECT(0,0,WIDTH,HEIGHT);
	string STR[30];
	int head[50]={0};
	STR[1].assign("BFS: BREADTH FIRST SEARCH"); head[1]=1;
	STR[2].assign("Bfs is an graph searching algorithm That begins at the root node and explores all the neighboring nodes.");
	STR[3].assign("Then for each of those nearest nodes, it explores their unexplored neighbor nodes, and so on, until it finds the goal.(wiki)");
	STR[4].assign("DFS: DEPTH FIRST SEARCH"); head[4]=1;
	STR[5].assign("Depth-first search (DFS) is an algorithm for traversing or searching a tree, tree structure, or graph. ");
	STR[6].assign("One starts at the root (selecting some node as the root in the graph case) and explores as far as possible along each branch before backtracking.(wiki)");
	STR[7].assign("MST: Minimum Spanning Tree"); head[7]=1;
	STR[8].assign("Given a connected, undirected graph, a spanning tree of that graph is a subgraph which is a tree and connects all the vertices together.");
	STR[9].assign("A MST is then a spanning tree with weight less than or equal to the weight of every other spanning tree.(wiki)");
	STR[10].assign("SSSP: Single Source Shortest Path"); head[10]=1;
	STR[11].assign("APSP: All pair Shortest Path"); head[11]=1;
	STR[12].assign("Dijkstra's Algorithm:"); head[12]=1;
    STR[13].assign("It is a graph search algorithm that solves the single-source shortest path problem"); 
    STR[14].assign("for a graph with nonnegative edge path costs, producing a shortest path tree."); 
    STR[15].assign("Euler Path:"); head[15]=1;
    STR[16].assign("An Eulerian trail is a trail in a graph which visits every edge exactly once.");
    STR[17].assign("Bellman Ford's algorithm(negative cycle finding):"); head[17]=1;
    STR[18].assign("The Bellman–Ford algorithm computes single-source shortest paths in a weighted digraph");
	int down=0;
	for(int i=1; ;i++)
	{
		if(!STR[i].size()) break;
		
		if(head[i]){ COLOR_BROWN;down+=10; class_SHAPE.TEXT(60,HEIGHT-55-down,STR[i],font_large);}
		else{COLOR_WHITE;class_SHAPE.TEXT(60,HEIGHT-55-down,STR[i],font_medium);}
		down+=20;
		
	}
	
	
}
