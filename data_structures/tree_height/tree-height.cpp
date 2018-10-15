#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int compute_height(Node *N){
    int maxHeight = 0;
    if (N == nullptr){
        return 0;
    }
    else{
        for (size_t i = 0; i < N->children.size(); ++i) {
            int temp = compute_height(N->children[i]); // recursion of using childrens of childrens
            if (temp > maxHeight)
                maxHeight = temp;
        }
    }
    return 1 + maxHeight;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);

    nodes[child_index].key = child_index;
  }

  /* Replace this code with a faster implementation.
   * Implementing the depth first for traversing the tree and counting the
   * number of branches and taking the maximum depth. Binary tree algorithm
   * cannot be implemented since there can be more than 2 childrens.
   * Algorithm to be implemented is postorder.
   */
  int maxHeight = 0;

  int root = -1;

  for (int child_index = 0; child_index < n; ++child_index) {
      if (nodes[child_index].parent == nullptr)
          root = child_index;  // finds the root node
  }

  maxHeight = compute_height(&nodes[root]);
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
