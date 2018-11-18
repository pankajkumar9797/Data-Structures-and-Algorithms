#!/usr/bin/python3

import sys
import threading

sys.setrecursionlimit(10 ** 7)  # max depth of recursion
threading.stack_size(2 ** 25)  # new thread will get stack of such size


def in_order_recursion(i, result, tree):
    if tree[i][1] != -1:
        in_order_recursion(tree[i][1], result, tree)
    result.append(i)
    if tree[i][2] != -1:
        in_order_recursion(tree[i][2], result, tree)


def is_binary_search_tree(tree):
    n = len(tree)

    if n == 0:
        return True

    result_test = []

    in_order_recursion(0, result_test, tree)

    for i in range(0, len(tree) - 1):
        if tree[result_test[i + 1]][0] < tree[result_test[i]][0]:
            return False
        if tree[result_test[i]][0] == tree[result_test[i + 1]][0] and tree[result_test[i + 1]][1] == result_test[i]:
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
