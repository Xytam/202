/*****************************************
 ** File:    proj1.h
 ** Project: CMSC 202 Project 1, "Spring" 2015
 ** Author:  John Horvers
 ** Date:    02/26/2015
 ** Section: 11 19
 ** E-mail:  horvers1@gl.umbc.edu
 **
 **   This file contains the declarations of the methods for proj1.cpp
 ***********************************************/


#ifndef proj1_h
#define proj1_h
const int MAX_VERTICES=20;
void InitializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int size);
bool RemoveEdge(int graph[MAX_VERTICES][MAX_VERTICES], int size, int u, int v);
bool CreateEdge(int graph[MAX_VERTICES][MAX_VERTICES], int size, int u, int v);
bool IsEdge(int graph[MAX_VERTICES][MAX_VERTICES], int size, int u, int v);
bool IsConnected(int graph[MAX_VERTICES][MAX_VERTICES], int size);

#endif
