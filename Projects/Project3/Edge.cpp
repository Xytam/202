 #include <iostream>
#include <vector>
#include <cmath>
#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge(Vertex *v1, Vertex *v2)
{
	if(v1!=NULL && v2!=NULL)
	{
		SetV1(v1);
		SetV2(v2);
		m_vertexArray[0]=v1;
		m_vertexArray[1]=v2;
	}
	else
		cout <<"Invalid Vertices";
}

Vertex* Edge:: GetV1() const
{
	return m_vertexArray[0];
}

Vertex* Edge:: GetV2() const
{
	return m_vertexArray[1];
}

void Edge:: SetV1(Vertex *v)
{
	m_v1=v;
	m_vertexArray[0]=v;
}

void Edge:: SetV2(Vertex *v)
{
	m_v2=v;
	m_vertexArray[1]=v;
}

ostream& operator <<(ostream &sout, const Edge&e)
{
	sout << "ID: " << e.GetV1()->GetID() << " <--> ID: " << e.GetV2()->GetID();
	return sout;
}
