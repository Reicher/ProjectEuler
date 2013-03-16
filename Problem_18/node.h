#pragma once

class Node
{
public:
   Node(long v, long num, long depth) : m_value(v), m_weight(v), m_num(num), m_depth(depth)
                                      , m_pParent1(NULL) , m_pParent2(NULL), m_pChild1(NULL), m_pChild2(NULL)
   {};

   void setParents(Node* p1, Node* p2)
   { m_pParent1 = p1; m_pParent2 = p2;}

   void setChildren(Node* c1, Node* c2)
   { m_pChild1 = c1; m_pChild2 = c2;}

   bool isRoot(){return (m_pParent1 == NULL && m_pParent2 == NULL);}
   bool isLeaf(){return (m_pChild1 == NULL && m_pChild2 == NULL);}
   void addWeight(long w){this->m_weight += w;}

   long m_value, m_weight, m_num, m_depth;
   Node *m_pParent1, *m_pParent2, *m_pChild1, *m_pChild2;
};
