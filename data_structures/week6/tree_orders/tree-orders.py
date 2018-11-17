# python3

import sys, threading
sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size


class TreeOrders:
    def read(self):
        self.n = int(sys.stdin.readline())
        self.key = [0 for i in range(self.n)]
        self.left = [0 for i in range(self.n)]
        self.right = [0 for i in range(self.n)]

        for i in range(self.n):
            [a, b, c] = map(int, sys.stdin.readline().split())
            self.key[i] = a
            self.left[i] = b
            self.right[i] = c

    def in_order_recursion(self, i, result):
        if self.left[i] != -1:
            self.in_order_recursion(self.left[i], result)
        result.append(self.key[i])
        if self.right[i] != -1:
            self.in_order_recursion(self.right[i], result)

    def pre_order_recursion(self, i, result):
        result.append(self.key[i])
        if self.left[i] != -1:
            self.pre_order_recursion(self.left[i], result)

        if self.right[i] != -1:
            self.pre_order_recursion(self.right[i], result)

    def post_order_recursion(self, i, result):
        if self.left[i] != -1:
            self.post_order_recursion(self.left[i], result)

        if self.right[i] != -1:
            self.post_order_recursion(self.right[i], result)

        result.append(self.key[i])

    def in_order(self):
        result = []

        self.in_order_recursion(0, result)

        return result

    def pre_order(self):
        result = []
        # Finish the implementation
        # You may need to add a new recursive method to do that
        self.pre_order_recursion(0, result)

        return result

    def post_order(self):
        result = []
        # Finish the implementation
        # You may need to add a new recursive method to do that
        self.post_order_recursion(0, result)
        return result


def main():
    tree = TreeOrders()
    tree.read()
    print(" ".join(str(x) for x in tree.in_order()))
    print(" ".join(str(x) for x in tree.pre_order()))
    print(" ".join(str(x) for x in tree.post_order()))


threading.Thread(target=main).start()
