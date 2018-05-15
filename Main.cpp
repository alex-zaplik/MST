#include <iostream>
#include <vector>

#include "Edge.h"
#include "Prim.h"
#include "Kruskal.h"

void print_usage()
{
	std::cerr << "Usage: -[pk]" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		print_usage();
		return 1;
	}

	unsigned int n, m;
	std::cin >> n >> m;

	unsigned int u, v;
	double w;

	std::vector<Edge> edges(m);
	for (unsigned int i = 0; i < m; i++)
	{
		std::cin >> u >> v >> w;
		edges[i] = Edge(u, v, w);
	}

	double total_weight;
	std::vector<Edge> mst;

	if (std::string(argv[1]) == "-p")
	{
		mst = Prim::mst(n, edges, total_weight);
	}
	else if (std::string(argv[1]) == "-k")
	{
		mst = Kruskal::mst(n, edges, total_weight);
	}
	else
	{
		print_usage();
		return 1;
	}

	for (unsigned int i = 0; i < mst.size(); i++)
	{
		if (mst[i].in < mst[i].out)
		{
			std::cout << mst[i].in << " " << mst[i].out << " " << mst[i].w << std::endl;
		}
		else
		{
			std::cout << mst[i].out << " " << mst[i].in << " " << mst[i].w << std::endl;
		}
	}

	std::cout << total_weight << std::endl;

	return 0;
}