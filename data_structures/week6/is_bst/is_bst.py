#!/usr/bin/python3

import sys, threading

sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**25)  # new thread will get stack of such size

class Node:

  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

  def insert(self, value):
    if value <= self.data:
      if self.left is None:
        self.left = Node(value)
      else:
        self.left.insert(value)
    else:
      if self.right is None:
        self.right = Node(value)
      else:
        self.right.insert(value)

  def in_order(self, result):
    if self.left is not None:
      self.left.in_order(result)
    result.append(self.data)
    if self.right is not None:
      self.right.in_order(result)


def in_order_recursion(i, result, left, right, key):
    if left[i] != -1:
        in_order_recursion(left[i], result, left, right, key)
    result.append(key[i])
    if right[i] != -1:
        in_order_recursion(right[i], result, left, right, key)


def IsBinarySearchTree(tree):
  # Implement correct algorithm here

  n = len(tree)

  if n == 0:
    return True

  key = [0 for i in range(n)]
  left = [0 for i in range(n)]
  right = [0 for i in range(n)]

  for i in range(n):
      [a, b, c] = tree[i]
      key[i] = a
      left[i] = b
      right[i] = c

  result_test = []
  result_correct = []

  in_order_recursion(0, result_test, left, right, key)

  node = Node(key[0])
  for i in range(1, len(key)):
    node.insert(key[i])

  node.in_order(result_correct)

  count = 0
  for i in range(len(result_correct)):
    if result_test[i] == result_correct[i]:
      count = count + 1

  if count == len(result_correct):
    return True
  else:
    return False

def main():
  nodes = int(sys.stdin.readline().strip())
  tree = []
  for i in range(nodes):
    tree.append(list(map(int, sys.stdin.readline().strip().split())))
  if IsBinarySearchTree(tree):
    print("CORRECT")
  else:
    print("INCORRECT")

threading.Thread(target=main).start()
