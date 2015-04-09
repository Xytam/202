/*****************************************
 ** File:    Proj1.cpp
 ** Project: CMSC 202 Project 1, "Spring" 2015
 ** Author:  John Horvers
 ** Date:    02/26/2015
 ** Section: 11 19
 ** E-mail:  horvers1@gl.umbc.edu 
 **
 **   This file contains the main driver program for Project 1.
 ** This program reads the number of vertices and the actualy edges
 ** of the graph in and determines if it is connected or not
 ** 
 ***********************************************/
#include <iostream>
#include "proj1.h"
using namespace std;

int main()
{
  int newGraph [MAX_VERTICES][MAX_VERTICES];
  int vertexAmount=0;
  bool doneReadingEdges=false;
  cout << "How many vertices? ";
  if(cin >> vertexAmount and vertexAmount <= MAX_VERTICES and vertexAmount > 0)
    {
      InitializeGraph(newGraph,vertexAmount);
      while(doneReadingEdges==false)
	{
	  cout <<"Please enter the vertex and 0 0 to exit\n";
	  int vertexA,vertexB;
	  cin >> vertexA >> vertexB;
	  if(vertexA==0 and vertexB==0)
	    {
	      doneReadingEdges=true;
	    }
	  else if(vertexA<=vertexAmount and vertexB<=vertexAmount and vertexA>=0 and vertexB>=0)
	    {
	      CreateEdge(newGraph,vertexAmount,vertexA,vertexB);
	    }
	  else
	    cout << "Please enter a valid edge... \n";
	}
      for(int i=0;i<vertexAmount;i++)
	{
	  for(int j=0;j<vertexAmount;j++)
	    cout << newGraph[i][j];
	  cout << "\n";
	}
      if(IsConnected(newGraph,vertexAmount)==true)
	cout << "Connected!\n";
      else
	cout <<"Disconnected!\n";

      return 0;

    }
  else
    {
      cout<<"Please enter a proper amount of vertices \n";
      return 0;
    }
}

void InitializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int size)
// Initialize the (i,j) entries of the array to zero for
// 0 <= i, j < size.
{
  for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
	{
	  graph[i][j]=0;
	}
    }
}
bool RemoveEdge(int graph[MAX_VERTICES][MAX_VERTICES], int size, int u, int v)
// Remove the edge between vertices u and v.
// Return false if there was no edge connecting u and v
// or if the specified vertices are invalid.
// Return true if there was an edge connecting u and v and
// it was removed.
{
  if(IsEdge(graph,size,u,v))
    {
      graph[u-1][v-1]=0;
      graph[v-1][u-1]=0;
      return true;
    }
  else
    return false;
}


bool CreateEdge(int graph[MAX_VERTICES][MAX_VERTICES], int size, int u, int v)
// Create an edge between vertices u and v.
// Return false if there was already an edge connecting u and v
// or if the specified vertices are invalid.
// Return true if there was not an edge connecting u and v and
// it was created.
{
  if(IsEdge(graph,size,u,v))
    return false;
  else if((u<0) or (v<0) or (u>size) or (v>size))
    return false;
  else
    {
      graph[u-1][v-1]=1;
      graph[v-1][u-1]=1;
      return true;
    }
}

bool IsEdge(int graph[MAX_VERTICES][MAX_VERTICES], int size, int u, int v)
// Return true if there is an edge connecting u and v;
// false otherwise.
{
  if(graph[u-1][v-1]==0 and graph[v-1][u-1]==0)
    return false;
  else
    return true;
}


bool IsConnected(int graph[MAX_VERTICES][MAX_VERTICES], int size)
//Determines if a graph is connected
{
  for(int i=1;i<size;i++)
    {
      int onesCounter=0;
      for(int k=0;k<=i;k++)
	{
	  if(graph[i-k][i]==1 or graph[i][i-k]==1)
	    {
	      onesCounter++;
	    }
	}
      if(onesCounter==0)
	return false;
    }
  return true;
}
