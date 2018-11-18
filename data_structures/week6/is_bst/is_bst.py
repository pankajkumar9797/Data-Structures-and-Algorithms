#!/usr/bin/python3

import sys
import threading

sys.setrecursionlimit(10 ** 7)  # max depth of recursion
threading.stack_size(2 ** 25)  # new thread will get stack of such size


def in_order_recursion(i, result, left, right, key):
    if left[i] != -1:
        in_order_recursion(left[i], result, left, right, key)
    result.append(key[i])
    if right[i] != -1:
        in_order_recursion(right[i], result, left, right, key)


def is_binary_search_tree(tree):
    n = len(tree)

    if n == 0:
        return True

    key = [0 for i in range(n)]
    left = [0 for i in range(n)]
    right = [0 for i in range(n)]

    for i in range(n):
        key[i] = tree[i][0]
        left[i] = tree[i][1]
        right[i] = tree[i][2]

    result_test = []

    in_order_recursion(0, result_test, left, right, key)

    for i in range(1, len(key)):
        if result_test[i] < result_test[i - 1]:
            return False

    return True


def main():
    nodes = int(sys.stdin.readline().strip())
    tree = []
    for i in range(nodes):
        tree.append(list(map(int, sys.stdin.readline().strip().split())))
    if is_binary_search_tree(tree):
        print("CORRECT")
    else:
        print("INCORRECT")


threading.Thread(target=main).start()
