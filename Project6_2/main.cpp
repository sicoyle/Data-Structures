//
// Created by Samantha Coyle 4/5/2018.
//

#include <iostream>
#include "Tree.h"
#include <stdlib.h>
#include <time.h>
#include <random>
#include <ctime>

int main() {



  Tree myTree;
  srand(time(0));

  for(int i = 0; i < 1000; i++)
  {
      int value = rand() % (2000 + 1);
      myTree.insert(i, value);
      myTree.searchNode(value);
      std::cout << std::endl;
  }



  //Trial #1

//  const unsigned int seed = time(0);
//Tree myTree;
//  std::mt19937_64 rng(seed);
//
//  std::uniform_int_distribution<int> unii(1, 2001);
//
//  for(int i = 0; i < 5; i++){
//    myTree.insert(i, unii(rng));
//  }
//
//
//  myTree.printTree();
//
//  for(int i = 0; i < 5; i++){
//    myTree.searchNode(unii(rng));
//  }








//Trial #2



//
//tree object
//  Tree myTree;
//  std::random_device rd;
//
//  std::mt19937 gen(rd());
//  std::uniform_int_distribution<> dist(1, 2000);
//
//
//  for(int i = 0; i < 5 /*1000*/; i++) {
//
//    myTree.insert(i,(dist(gen)));
//  }
//  myTree.printTree();
//
//  for(int i = 0; i < 5; i++) {
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_int_distribution<> dist(1, 2000);
//    myTree.searchNode((dist(gen)));
//  }




//..... There were many more trials where those came from:(


//Trial #3

//
//  //Insert 1000 nodes
//  std::random_device rd;
//  Tree myTree ;
//  int numberOfNodes = 1000;
//  int val = 0;
//
//  std::mt19937 gen(rd());
//  std::uniform_int_distribution<> dis(1,2000);
//  for(int i = 0; i < numberOfNodes; i++)
//  {
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_int_distribution<> dist(1, 2000);
//    myTree.insert(i,dis(gen));
//  }
//  myTree.printTree();
//
//  //Display left and right subtree height
//  int treeHeight = myTree.height();
//
//  std::cout << "Tree height: " << treeHeight << std::endl;
//
  //Search stuff
//  for(int index = 0; index < 5/*numberOfNodes*/ //index++)
//  {
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_int_distribution<> dist(1, 2000);
//   myTree.searchNode(dis(gen));
//
//  }

/*

  Tree tree;
  tree.insert(0,30);
  tree.insert(1,10);
  tree.insert(2,20);
  tree.insert(3,40);
  tree.insert(4,50);
  tree.insert(5,60);
  tree.insert(6,70);
  tree.insert(7,25);
  tree.insert(8,15);
  tree.insert(9,90);
  tree.insert(10,100);
  //Duplicate case
  tree.insert(11,25);
  tree.insert(12,16);
  tree.insert(13,29);
  tree.insert(14,39);
  tree.insert(15,69);
  tree.insert(16,101);
  tree.insert(17,99);
  // tree.insert(18,102);
  tree.insert(19,44);
  tree.insert(20,17);
  tree.insert(21,28);
  tree.insert(22,18);

  cout << "In order traversal" << endl;
  tree.printTree();
  cout << endl;

  tree.searchNode(20);
  tree.searchNode(40);
  tree.searchNode(1);
  tree.searchNode(30);
*/
  int h = myTree.height();

  std::cout << "height " << h << std::endl;

  return 0;
}