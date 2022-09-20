#include <iostream>
#include <fstream> 
#include <queue> 
#include "ArgumentManager.h"
using namespace std;  

void BFS(int **graph, int SIZE, int source, int destination, ofstream &output) {
  int curr_vertices; 
  queue<int>q; 
  bool * visited = new bool[SIZE]; 
  for(int i = 0; i < SIZE; i++) {
    visited[i] = false; 
  } 
  q.push(source); 
  while(!q.empty()) {
    curr_vertices = q.front(); 
    q.pop();  
    if(!visited[curr_vertices]) {  
      visited[curr_vertices] = true; 
      if(curr_vertices == destination) {
      output << "true\n";
      return; 
    }
    }  
    for(int i = 0; i < SIZE; i++) {
      if(graph[curr_vertices][i] == 1 && visited[i] == false) {
        q.push(i); 
      } 
    }
  }  
  output << "false\n"; 
}
int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  string infilename = am.get("input"); //get the filename of argument name "input"
  string outfilename = am.get("output"); //get the filename of argument name "output"
  ifstream input(infilename);
  ofstream output(outfilename); 
  int SIZE, source, destination; 
  int num1, num2; 
  input >> SIZE >> source >> destination; 

  int **graph = new int*[SIZE];
  for(int pos = 0; pos < SIZE; pos++) {
    graph[pos] = new int[SIZE]; 
  }
  for(int v = 0; v < SIZE; v++) {
    for(int e = 0; e < SIZE; e++) {
      graph[v][e] = 0; 
    }
  } 
  while(input >> num1 >> num2) {
    graph[num1][num2] = 1; 
    graph[num2][num1] = 1;
  }  
  BFS(graph, SIZE, source, destination, output); 
}