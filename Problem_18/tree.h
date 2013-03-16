#pragma once

#include "node.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Tree
{
 public:
 Tree() : m_maxDepth(0){};
  
  Node* CreateFromFile(string filename)
  {
    readStrings(filename);
    createNodes();
    setRelations();
    getWeights();
    
    for(list<Node>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
      if(it->isRoot())
	return &(*it);
    
    return NULL;
  }

  void printOut()
  {
    for(int d = 0; d <= m_maxDepth; ++d)
      {
	list<Node*> level = getNodesOfDepth(d);
	for(int i = 0; i < m_maxDepth-d; ++i)
	  cout << " ";

	for(list<Node*>::iterator it = level.begin(); it != level.end(); ++it)
	  {
	    cout << (*it)->m_weight << " ";
	  }
	cout << endl;
      }
  }
   
 private:
  bool readStrings(string filename)
  {
    string line;
    ifstream myfile (filename.c_str());
    if (myfile.is_open())
      {
	while ( myfile.good() )
	  {
	    getline (myfile,line);
	    m_strings.push_back(line);
	  }
	myfile.close();
      }
    else 
      return false;
    
    return true;
  }
  
  bool createNodes()
  {
    long depth = 0;
    for(list<string>::const_iterator it = m_strings.begin(); it != m_strings.end(); ++it)
      {
	long num = 0;
	string strVal = "";
	for(unsigned int i = 0; i <= it->size(); ++i)
	  {
	    if( i == it->size() || it->at(i) == ' ')
	      {
		m_nodes.push_back(Node(atoi(strVal.c_str()), num, depth));
		strVal = "";
		++num;
	      }
	    else
	      strVal += it->at(i);
	  }
	++depth;
      }
    m_maxDepth = depth-1;
    
    cout << "last node to be added d: " << m_nodes.back().m_depth << endl;
    
    return true;
  }
  
bool setRelations()
{
  for(list<Node>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it){
    it->setChildren(getNode(it->m_num, it->m_depth+1), getNode(it->m_num+1, it->m_depth+1));
    it->setParents(getNode(it->m_num-1, it->m_depth-1), getNode(it->m_num, it->m_depth-1));
  }
  
  return true;
}

list<Node*> getNodesOfDepth(long depth)
{
  list<Node*> level;
  
  for(list<Node>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it){
    if(it->m_depth == depth)
      level.push_back(&(*it));
  }
  
  return level;
 }
 
 void getWeights()
 {
   list<Node*> level;
   cout << "maxDepth: " << m_maxDepth << endl;
   for(int i = m_maxDepth; i >= 0; --i){
     level = getNodesOfDepth(i);
     for(list<Node*>::iterator it = level.begin(); it != level.end(); ++it)
       {
	 Node* tmp = *it; 
	 (*it)->addWeight( getGreaterWeightOf(tmp->m_pChild1, tmp->m_pChild2) );
	 
	 /* cout << "Depth: " << tmp->m_depth << 
	   ", Num: " << tmp->m_num <<
	   ", Val: " << tmp->m_value <<
	   ", Child1 value: " << tmp->m_pChild1->m_weight <<  
	   ", Child2 value: " << tmp->m_pChild2->m_weight << 
	   ", weight: " << tmp->m_weight << endl;*/
       }
   }
 }
  

  Node* getNode(long num, long depth)
  {
    list<Node*> level = getNodesOfDepth(depth);
    for(list<Node*>::iterator it = level.begin(); it != level.end(); ++it)
      if((*it)->m_num == num)
	return *it;
    
    return NULL;
  }
  
  
  long getGreaterWeightOf(Node* n1, Node* n2)
  {
    if(n1 == NULL && n1 == NULL)
      return 0;
    else if(n1 == NULL){
      cout << "looked for Null node?!" << endl;
      return n2->m_weight;
    }
    else if(n2 == NULL){
      cout << "looked for Null node?!" << endl;
      return n1->m_weight;
    }
    else if(n1->m_weight > n2->m_weight)
      return n1->m_weight;
    else if(n2->m_weight > n1->m_weight)
      return n2->m_weight;
    
    return n1->m_weight;
  }

  list<Node> m_nodes;
  list<string> m_strings;
  long m_maxDepth;
};
