// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// ll V;
// // int main(int argc, char const *argv[])
// // {
// // 	ll n,m;
// // 	cin>>n>>m;

// // 	ll i=m;

// // 	std::map<ll, std::map<ll, ll> > g;

// // 	while(i--)
// // 	{
// // 		ll a,b;
// // 		bool num;
// // 		cin>>a>>b>>num;
// // 		if(num)
// // 		{
// // 			ll c;
// // 			cin>>c;
// // 			g[a][b]=c;
// // 			g[b][a]=c;
// // 		}
// // 		else
// // 			g[a][b]=0;
// // 	}


// // 	ll co=0;



// // 	for(ll i=1;i<=n;i++)
// // 	{
// // 		ll cc=INT_MAX,ce=1;
// // 		bool d=0;
// // 		for(auto e:g[i])
// // 		{
// // 			// cout<<e.second<<endl;
// // 			if(cc > e.second)
// // 			{
// // 				d=1;
// // 				// cout<<"here "<<cc<<endl;
// // 				cc=e.second;
// // 				// cout<<"here1 "<<cc<<endl;
// // 				ce=e.first;
// // 			}

// // 		}

// // 		if(d)
// // 		{
// // 			co+=cc;
// // 			// cout<<"here2 "<<cc<<endl;
// // 			g[i][ce]=0;
// // 			g[ce][i]=0;
			
// // 		}
// // 	}

// // 	cout<<co<<endl;
// // 	return 0;
// // }

 
// // Number of vertices in the graph
 
// // A utility function to find the vertex with minimum key value, from
// // the set of vertices not yet included in MST
// ll minKey(ll key[], bool mstSet[])
// {
//    // Initialize min value
//    ll min = INT_MAX, min_index;
 
//    for (ll v = 1; v <= V; v++)
//      if (mstSet[v] == false && key[v] < min)
//          min = key[v], min_index = v;
 
//    return min_index;
// }
 
// // A utility function to prll the constructed MST stored in parent[]
// void printMST(ll parent[], ll n, std::map<ll, std::map<ll, ll> > graph)
// {
//    printf("Edge   Weight\n");
//    for (ll i = 2; i <= V; i++)
//       printf("%lld - %lld    %lld \n", parent[i], i, graph[i][parent[i]]);
// }
 
// // Function to construct and print MST for a graph represented using adjacency
// // matrix representation
// void primMST(std::map<ll, std::map<ll, ll> >  graph)
// {
//      ll parent[V]; // Array to store constructed MST
//      ll key[V];   // Key values used to pick minimum weight edge in cut
//      bool mstSet[V];  // To represent set of vertices not yet included in MST
 
//      // Initialize all keys as INFINITE
//      for (ll i = 1; i <= V; i++)
//         key[i] = INT_MAX, mstSet[i] = false;
 
//      // Always include first 1st vertex in MST.
//      key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
//      parent[0] = -1; // First node is always root of MST 
 
//      // The MST will have V vertices
//      for (ll count = 1; count < V; count++)
//      {
//         // Pick the minimum key vertex from the set of vertices
//         // not yet included in MST
//         ll u = minKey(key, mstSet);
 
//         // Add the picked vertex to the MST Set
//         mstSet[u] = true;
 
//         // Update key value and parent index of the adjacent vertices of
//         // the picked vertex. Consider only those vertices which are not yet
//         // included in MST
//         for (ll v = 0; v < V; v++)
 
//            // graph[u][v] is non zero only for adjacent vertices of m
//            // mstSet[v] is false for vertices not yet included in MST
//            // Update the key only if graph[u][v] is smaller than key[v]
//           if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
//              parent[v]  = u, key[v] = graph[u][v];
//      }
 
//      // print the constructed MST
//      printMST(parent, V, graph);
// }
 
 
// // driver program to test above function
// int main()
// {
//    /* Let us create the following graph
//           2    3
//       (0)--(1)--(2)
//        |   / \   |
//       6| 8/   \5 |7
//        | /     \ |
//       (3)-------(4)
//             9          */
   
// 	ll n,m;
// 	cin>>n>>m;
// 	V=n;

// 	ll i=m;

// 	std::map<ll, std::map<ll, ll> > g;

// 	while(i--)
// 	{
// 		ll a,b;
// 		bool num;
// 		cin>>a>>b>>num;
// 		if(num)
// 		{
// 			ll c;
// 			cin>>c;
// 			g[a][b]=c;
// 			g[b][a]=c;
// 		}
// 		else
// 			g[a][b]=0;
// 	}




//     // Print the solution
//     primMST(g);
 
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef long long int ll;

// iPair ==>  Integer Pair
typedef pair<ll, ll> iPair;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    ll V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<ll, ll> > *adj;
    std::map<ll, std::map<ll, ll> > gr;
 
public:
    Graph(ll V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(ll u, ll v, ll w);
 
    // Prll MST using Prim's algorithm
    ll primMST();
};
 
// Allocates memory for adjacency list
Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(ll u, ll v, ll w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    gr[u][v] = w;
    gr[v][u] = w;
    
}
 
// Prlls shortest paths from src to all other vertices
ll Graph::primMST()
{
    // Create a priority queue to store vertices that
    // are being preinMST. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    ll src = 0; // Taking vertex 0 as source
 
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<ll> key(V, INF);
 
    // To store parent array which in turn store MST
    vector<ll> parent(V, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        ll u = pq.top().second;
        pq.pop();
 
        inMST[u] = true;  // Include vertex in MST
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<ll, ll> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            ll v = (*i).first;
            ll weight = (*i).second;
 
            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    // Prll edges of MST using parent array
    ll c=0;
    for (ll i = 1; i < V; ++i)
        // printf("%lld - %lld\n", parent[i], i);
        c+=gr[i][parent[i]];
    return c;

}
 
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    
	ll n,m;
	cin>>n>>m;
	ll V=n;

	ll i=m;


    Graph g(V);

	for(ll i=0;i<m;i++)
	{
		ll a,b;
		bool k;
		ll c=0;

		cin>>a>>b>>k;
		if(k)
			cin>>c;


		g.addEdge(a-1, b-1, c);
		
	}

 
    //  making above shown graph

    cout<<g.primMST()<<endl;
 
    return 0;
}