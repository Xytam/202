#include "Edge.h"
#include "Graph.h"
#include "Matrix.h"
#include "Vertex.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool myfn(int i, int j)
{
	return i<j;
}

int main()
{
	Graph newGraph;

	string loadedFile = "";
	char selection;

	do
	{	
		if(loadedFile=="")
			cout << "No file loaded\n";
		else
			cout << "\n--------------------------------------\n" <<loadedFile << " loaded.\n--------------------------------------";
		
		cout << "\nChoose and action from the following menu: \n \n";
		cout << "l - load a graph data file\n";
		cout << "v - list the vertices of the loaded graph\n";
		cout << "e - list the edges of the loaded graph\n";
		cout << "c - list the connected component of a specific vertex\n";
		cout << "q - quit\n\n";
		cout << "Selection: ";
		cin >> selection;
		switch(selection)
		{
			case 'l':
			{
				//
				string loadFileName;
				cout <<"Graph file name: ";
				cin >> loadFileName;
				if(newGraph.LoadFromFile(loadFileName))
				{
					cout << "The graph file "<< loadFileName << " loaded successfully!\n\n";
					loadedFile=loadFileName;
				}
				else
					cout << "Invalid file name!\n";
				break;
			}
			case 'v':
			{
				cout << "Vertices: \n";
				vector <Vertex*> tempVector = newGraph.GetVertices();
				for(int i=0;i<newGraph.GetNumVertices();i++)
					cout << *tempVector[i] << "\n";
				break;
			}
			case 'e':
			{
				cout << "Edges: \n";
				vector<Edge*> tempEdgeVector = newGraph.GetEdges();
				for(int k=0;k<newGraph.GetNumEdges();k++)
					cout << *tempEdgeVector[k] << "\n";
				break;
			}
			case 'c':
			{
				vector < int > lowestValues;
				for(int i=0; i<newGraph.GetNumEdges(); i++)
				{	
					Edge tempEdge = *newGraph.GetEdges()[i];
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



				cout << "Enter the vertex ID: ";
				int vertexEntered;
				cin >> vertexEntered;
				if(vertexEntered < idSubtractor)
					cout << "Vertex with ID " << vertexEntered << " not found.\n";
				else
				{
					cout << "\nConnected component of vertex with ID " << vertexEntered << ":\n";
					Vertex* tempVertex = newGraph.GetVertices()[vertexEntered-idSubtractor];
					vector <Vertex*> tempVector = newGraph.GetConnectedComponent(tempVertex);
					for(int i=0; i<tempVector.size();i++)
					{
						cout << *tempVector[i] <<"\n";
					}
				}
				break;
			}
			case 'q':
			{
				cout << "Quitting...\n";
				break;
			}
			default:
			{
				cout << "Your selection was invalid. Please try again.\n";
			}
		}
	}while(selection!='q');	
}