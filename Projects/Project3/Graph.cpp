#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Graph::Graph()
{ /* nothing to do */ }

Graph::Graph(vector<Vertex *> vertices, vector<Edge *> edges) :
  m_vertices(vertices), m_edges(edges)
{
  for (int i = 0; i < vertices.size(); i++)
    if (vertices[i] == NULL) {
      cerr << "Error: Graph constructor expects non-null vertices." << endl;
      exit(1);
    }
  
  for (int i = 0; i < edges.size(); i++)
    if (edges[i]->GetV1() == NULL || edges[i]->GetV2() == NULL) {
      cerr << "Error: Graph constructor expects edges with non-null vertices." << endl;
      exit(1);
    }
}      

bool Graph::LoadFromFile(string fileName) {
  int numVertices;
  int v1, v2;
  vector<Vertex*> vertices;
  vector<Edge*> edges;
  ifstream dataFile;
      
  /* Set exception flags for file input stream */ 

  dataFile.exceptions(ios::failbit | ios::badbit);

  try {
  
    dataFile.open(fileName.c_str());
    dataFile >> numVertices;

    for ( int i = 0; i < numVertices; i++ )
      vertices.push_back( new Vertex() );

    dataFile >> v1 >> v2;
  
    while ( v1 > 0 && v2 > 0 ) {
      if (v1 <= numVertices && v2 <= numVertices )
	edges.push_back( new Edge(vertices[v1-1], vertices[v2-1]) );
      dataFile >> v1 >> v2;
    }

    

    dataFile.close();
  }
  catch (exception e) {
    return false;
  }
  m_vertices = vertices;
  m_edges = edges;

  return true;
}

int Graph:: GetNumVertices() const
{
	return m_vertices.size();
}  

int Graph:: GetNumEdges() const
{
	return m_edges.size();
}

vector<Vertex *> Graph:: GetVertices() const
{
	return m_vertices;
}
vector<Edge *> Graph:: GetEdges() const
{
	return m_edges;
}
Matrix Graph:: GetAdjacencyMatrix() const
{
	Matrix testMatrix(m_vertices.size(),m_vertices.size());
	for(int diag = 0; diag< m_vertices.size();diag++)
	{
		testMatrix.Set(diag,diag,1);
	}

	vector < int > lowestValues;
	for(int i=0; i<m_edges.size(); i++)
	{
		Edge tempEdge = *m_edges[i];
		Vertex* tempVertex1 = tempEdge.GetV1();
		Vertex* tempVertex2 = tempEdge.GetV2();
		lowestValues.push_back(tempVertex1->GetID());
		lowestValues.push_back(tempVertex2->GetID());
		
	}
	int idSubtractor=lowestValues[0];
	for(int j=0; j<lowestValues.size();j++)
	{
		if(lowestValues[j]<idSubtractor)
			idSubtractor=lowestValues[j];
	}
	for(int k=0;k<lowestValues.size();k++)
	{
		lowestValues[k]-=idSubtractor;
	}
	for(int m = 0; m<lowestValues.size();m++)
	{
		if(m%2==0 || m==0)
		{
			testMatrix.Set(lowestValues[m],lowestValues[m+1],1);
			testMatrix.Set(lowestValues[m+1],lowestValues[m],1);
		}
	}
	
	return testMatrix;
}
vector<Vertex *> Graph:: GetConnectedComponent(Vertex *v) const
{
	vector<Vertex *> connectedComponents;
	vector<double> IDVector;
	vector<double> productOne;
	vector<double> productTwo;	
	int IDNumber = v->GetID();


	vector < int > lowestValues;
	for(int i=0; i<m_edges.size(); i++)
	{
		Edge tempEdge = *m_edges[i];
		Vertex* tempVertex1 = tempEdge.GetV1();
		Vertex* tempVertex2 = tempEdge.GetV2();
		lowestValues.push_back(tempVertex1->GetID());
		lowestValues.push_back(tempVertex2->GetID());
		
	}
	int idSubtractor=lowestValues[0];
	for(int j=0; j<lowestValues.size();j++)
	{
		if(lowestValues[j]<idSubtractor)
			idSubtractor=lowestValues[j];
	}




	for(int i=idSubtractor;i<idSubtractor+m_vertices.size();i++)
	{
		if(i==IDNumber)
			IDVector.push_back(1);
		else
			IDVector.push_back(0);
	}
	productOne = GetAdjacencyMatrix().Matvec(IDVector);
	productTwo = GetAdjacencyMatrix().Matvec(productOne);
	for(int m=0;m<productOne.size();m++)
	{
		if(productTwo[m]!=0)
			productTwo[m]=1;
	}
	while(productOne!=productTwo)
	{
		productOne=productTwo;
		productTwo=GetAdjacencyMatrix().Matvec(productOne);
		for(int m=0;m<productOne.size();m++)
		{
			if(productTwo[m]!=0)
				productTwo[m]=1;
		}
	}

	for(int j=0;j<m_vertices.size();j++)
	{
		if(productTwo[j]!=0)
			connectedComponents.push_back(GetVertices()[j]);
	}
	return connectedComponents;
	
}