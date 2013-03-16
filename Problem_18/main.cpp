#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iosfwd>
#include "node.h"
#include "tree.h"

using namespace std;

int main(int argc, char* argv[])
{
  Tree triangle;
  Node* root;

  if(argc > 1)
   root = triangle.CreateFromFile(argv[1]);
  else
    root = triangle.CreateFromFile("input_test.txt");

  triangle.printOut();
  cout << "Maximum total: " << root->m_weight << endl;
}
