/*
PROG: mst
LANG: C++
*/
// Our file input/output headers
#include <fstream>
#include <iostream>

// Used for std::precision (look at main())
#include <iomanip>

// http://www.cplusplus.com/reference/vector/vector/
#include <vector>
// http://www.cplusplus.com/reference/queue/priority_queue/
#include <queue>

// This will store and adjacent node and the distance to that node.
class State {
  size_t _node;
  double _dist;
public:
  State( size_t aNode, double aDist ) : _node{aNode}, _dist{aDist} {}
  inline size_t node() const { return _node; }
  inline double dist() const { return _dist; }
};

//Overload operator<
bool operator< (const State& lhs, const State& rhs){ return lhs.dist() > rhs.dist();}

/* A wrapper for our vector of vectors which represents an
 * adjacency list. Why didn't we just go with the list of vectors?
 * Notice that once the AdjacencyList is constructed, it contains
 * the data, which is private, and this data is not modifiable by
 * people using the class- better than using a potentially edit-able
 * vector of vectors out in the open.
 */
class AdjacencyList {
  std::vector< std::vector<State> > _vert;
  AdjacencyList() = delete;
public:
  AdjacencyList( std::istream &input );
  inline size_t size() const { return _vert.size(); }
  inline const std::vector<State>& vert( size_t node ) const { return _vert[node]; }
  void print();
};

AdjacencyList::AdjacencyList( std::istream &input ) : _vert{} {
  size_t nNodes; size_t nEdges; input >> nNodes >> nEdges;
  _vert.resize( nNodes );

  for( size_t e = 0; e < nEdges; ++e ) {
    size_t v, w; double weight;
    input >> v >> w >> weight;
    // Add this edge to both the v and w lists
    _vert[v].push_back( State{ w, weight } );
    _vert[w].push_back( State{ v, weight } );
  }
}

void AdjacencyList::print() {
  for( size_t i = 0; i < _vert.size(); ++i ) {
    std::cout << i << ": ";
    for( auto state : _vert[i] ) {
      std::cout << "(" << state.node() << ", " << state.dist() << ") ";
    }
    std::cout << "\n";
  }
}

/* The function which computes the minimum spanning tree of the graph.
 * Your job is to implement this!
 */
double prim( const AdjacencyList &adj ) {
  double weight = 0.0;
  // Suggested starting point:
  std::priority_queue<State> pq;
  //   NOTE: you will need to overload a operator<
  //   for State objects, since priority_queue<> requires that
  //   its members be comparable!
  pq.push( State{ 0, 0.0 } );
  bool *visited = new bool[adj.size()];
  
  //for (int i = 0 ; i<adj.size();i++ ){
    //visited[i]=false;
    //std::cout << visited[i] <<"\n";
  //}
  visited[pq.top().node()]=true;
  //
  while( !pq.empty() ) {
  //    you'll want to pop off the front
  //    element in the priority queue and
  //    then add its neighbors.
  //    Check out http://cplusplus.com
  //    and the suggested resource in the
  //    problem statement!
    
    //pq.pop();
    
    
    int v=pq.top().node();
    visited[v]=true;
    std::cout << v <<"\n";
    pq.pop();
    for( size_t i = 0; i < adj.vert(v).size(); ++i ){
        if (visited[adj.vert(v)[i].node()]==false) {
            pq.push(adj.vert(v)[i]);
            //std::cout << pq.top().node() <<"\n";
        }
      
    }
    if (visited[pq.top().node()]==false){
      weight = weight + pq.top().dist();
    }
    

    
    
    
    
    //pq.pop();
    //std::cout << pq.top().node() <<"\n";
    
    //std::cout << weight <<"\n";
  }

  return weight;
}

int main() {
  std::ifstream input{ "mst.in" };
  std::ofstream output{ "mst.out" };

  if( input.is_open() ) {
    auto adj = AdjacencyList{ input };
    adj.print();
    //output << adj.vert(State{ 0, 0.0 }.node()).size();
    // So that we print 10 fixed digits of precision
    output << std::fixed << std::setprecision( 8 );
    output << prim( adj ) << "\n";
  } else {
    std::cerr << "Could not open mst.in\n";
    return 1;
  }
  
  return 0;
}