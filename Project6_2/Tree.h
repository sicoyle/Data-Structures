//
// Created by Greg LaKomski on 3/20/18.
//

#ifndef HOMEWORK6_TREE_H
#define HOMEWORK6_TREE_H

#include<utility>
#include<iostream>
using std::cout;
using std::endl;

// Note the nested classes - look this up!
// I could have added parent pointers to make deletion more efficient
// The node class will have both the key and an associated value you can carry with. Should remind you of a MAP or SET.
class Tree {
 private:

  int leftHeight;
  int rightHeight;
  int treeComparisons;
  int maxComparisons;
  int minComparisons;
  int averageComparisons;
  int totalNumberofComparisons =0;

  class Node {
   private:
    Node * left;
    Node * right;
    int key;
    int value;

   public:
    Node( int key, int value ) {
      this->key = key;
      this->value = value;
      this->left = NULL;
      this->right = NULL;
    }
    friend class Tree;
  };

  // this is part of the Tree class
  Node * head;

  int getLeftHeight(){
    return leftHeight;
  }

  int getRightHeight(){
    return rightHeight;
  }

  void setLeftHeight(int left){
    leftHeight = left;
  }

  void setRightHeight(int right){
    rightHeight = right;
  }

  void setComparisons(int comparison){
    treeComparisons = comparison;
  }

  int getComparisons(){
    return treeComparisons;
  }

  void setMaxComparisons(int max){
    maxComparisons = max;
  }

  int getMaxComparisons(){
    return maxComparisons;
  }

  void setMinComparisons(int min){
    minComparisons = min;
  }

  int getMinComparisons(){
    return minComparisons;
  }

  float getAverageComparisons(){
    return averageComparisons;
  }

  void setAverageComparisons(float average){
    averageComparisons = average;
  }

  void setTotalNumberofComparisons(int comparison){
    totalNumberofComparisons += comparison;
  }

  int getTotalNumberofComparisons(){
    return totalNumberofComparisons;
  }

  // Helper Function for insert
  Node * BSTInsert(Node* y, Node * head) {
//    //Check if head has no value
    if (head == NULL)
      head = new Node(y->key,y->value);
    else{
      //head node has value, so test if add left or add right
      if(y->value < head->value){
        //Add node left for lesser y value
        head->left = BSTInsert(y,head->left);
      }

      else if(y->value > head->value){
        //Add node right for greater y value
        head->right = BSTInsert(y,head->right);
      }
    }
    return head;
  }

  // Helper function for height
  // .............................Add Code

  //Helper function for printTree
  void printInOrder(Node * node) {
    if (node == NULL)
      return;
    else {
      // ............................. ADD CODE
      //Traverse left subtree
      if(node->left != NULL){
        printInOrder(node->left);}

      //Go to root
      printf("%d\n", node->value);

      //Traverse right subtree
      if(node->right != NULL){
        //   std::cout << "right" << endl;
        printInOrder(node->right);}
    }
  }

  // Helper function for search
  std::pair<bool,int> searchHelper(int data){
    Node *temp = head;
    int counter = 0;
    bool flag = false;

    //Check if tree empty
    if (temp == NULL){
      flag = false;}

    //While still nodes, check for value
    while (temp != NULL)
    {
      //Head is value
      if (temp->value == data){
        flag = true;
        break;
      }

      //Move down right side of tree for larger value
      if (data > temp->value){
        counter++;
        temp = temp->right;}

      //Move down left side of tree for smaller value
      if (data < temp->value){
        counter++;
        temp = temp->left;}
    }

    //Return if data present or not
    return std::make_pair(flag,counter);
  }

  //This function is a helper function for the height function
  int heightHelper(Node * node){
    int leftHeight = 0;
    int rightHeight = 0;

    if(node->left != NULL){
      leftHeight = heightHelper(node->left);
    }
    if (node->right != NULL){
      rightHeight = heightHelper(node->right);
    }

    leftHeight = leftHeight + 1;
    rightHeight = rightHeight + 1;

    if(leftHeight > rightHeight){
      return (leftHeight);
    }
    else {
      return (rightHeight);
    }
  }

 public:
  Tree() { head = NULL; }

  Node * createNode(int key, int value){
    Node * temp = new Node(key,value);
    return temp;
  }

  //Prints the keys for the tree in inorder mode
  // Helper function in private section
  void printTree(){
    printInOrder(this->head);
  }

  //Inserts a node into the tree
  // Helper function in private section
  void insert(const int key, const int value){
    Node * temp = new Node(key,value);
    this->head = BSTInsert(temp,this->head);
  }

  int compareHelper(int compares)
  {
    int counter = 0;

    counter++;

    if(compares < getMinComparisons())
      setMinComparisons(compares);

    if(compares > getMaxComparisons())
      setMaxComparisons(compares);

    return counter;
  }

  //Deletes a node with a specific key, returns TRUE or FALSE and the # of compares done. - a pair.
  // Helper function in private section
  std::pair<bool,int> searchNode(int key){
    //................  Insert Code
    std::pair<bool,int> HelperReturnValue = searchHelper(key);

    std::cout << "You are searching for the value of: " << key << std::endl;



    int compares = (HelperReturnValue.second + 1);

    std::cout << "Number of comparisons " << compares << std::endl;

    displayComparisons();

    setTotalNumberofComparisons(compares);
    std::cout << "Total: " << getTotalNumberofComparisons() <<std::endl;

    float average = (float)getTotalNumberofComparisons() / (float)compares;
    std::cout << "Average: " << average << std::endl;

    compareHelper(compares + 1);

    //Check if value found
    if(HelperReturnValue.first == true)
    {
      std::cout << "Node value present" << endl;
    }

    //Check if value not found
    if(HelperReturnValue.first == false){
      std::cout << "Node not present" << endl;
    }


    return HelperReturnValue;
  }

  void displayComparisons(){
    std::cout << "least compares " << getMinComparisons() << std::endl;
    std::cout << "max compares " << getMaxComparisons() << std::endl;
  }

  int height(){
    int treeHeight = -1;
    int leftTreeHeight = -1;
    //Check if tree empty
    if(head == NULL)
      return treeHeight;
    else{
      treeHeight = (1 + std::max(heightHelper(head->left),heightHelper(head->right)));
    }

    leftTreeHeight = (heightHelper(head->left));
    std::cout << "Left subtree height: " << leftTreeHeight << std::endl;

    int rightTreeHeight = heightHelper(head->right);
    std::cout << "Right subtree height: " << rightTreeHeight << std::endl;

    // std::cout << "Tree overall height: " << treeHeight << std::endl;

    return treeHeight;
    //................. Insert code
  }

  // add create a node with key, value and both pointers
  // add insert,search (should return TRUE and
  // number of comparisons to find it or FALSE and number of comparisons) and height methods for the tree class
  // sounds like search should return a pair, yes?
};
#endif //HOMEWORK6_TREE_H