#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex()
{
	static int newVar;
	IDNumber=newVar;
	newVar++;
}

int Vertex:: GetID() const
{
	return IDNumber;
}

ostream& operator <<(ostream &sout, const Vertex&v)
{
	sout << "ID = " << v.GetID();
	return sout;
}