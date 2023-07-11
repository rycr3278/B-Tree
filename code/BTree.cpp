#include "BTree.h"

// constructor, initialize class variables and pointers here if need.
BTree::BTree(){
  // Your code here
}

//deconstructor,
BTree::~BTree(){
}

void BTree::insert(shared_ptr<btree> root, int key){

}

void BTree::remove(shared_ptr<btree> root, int key){

}

shared_ptr<btree> BTree::find(shared_ptr<btree> root, int key){
  if (root == nullptr) {
    return nullptr;
  }

  int i = 0;
  while (i < root->num_keys && key > root->keys[i]) {
    i++;
  }

  if (i < root->num_keys && key == root->keys[i]) {
    return root;
  }

  if (root->is_leaf) {
    return nullptr;
  }

  return find(root->children[i], key);

}

int BTree::count_nodes(shared_ptr<btree> root){
  if (root == nullptr) {
    return 0;
  }

  int count = 1;
  for (int i = 0; i <= root->num_keys; i++) {
    count += count_nodes(root->children[i]);
  }

  return count;

}

int BTree::count_keys(shared_ptr<btree> root){
  if (root == nullptr) {
    return 0;
  }

  int count = root->num_keys;
  for (int i = 0; i <= root->num_keys; i++) {
    count += count_keys(root->children[i]);
  }

  return count;
}