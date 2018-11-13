# python3


class Query:

    def __init__(self, query):
        self.type = query[0]
        if self.type == 'check':
            self.ind = int(query[1])
        else:
            self.s = query[1]


class QueryProcessor:
    _multiplier = 263
    _prime = 1000000007

    def __init__(self, bucket_count):
        self.bucket_count = bucket_count
        # store all strings in one list
        self.elems = [[] for _ in range(bucket_count)]

    def _hash_func(self, s):
        ans = 0
        for c in reversed(s):
            ans = (ans * self._multiplier + ord(c)) % self._prime
        return ans % self.bucket_count

    def add(self, string):
        hashed_string = self._hash_func(string)
        elem = self.elems[hashed_string]

        if string not in elem:
            self.elems[hashed_string] = [string] + elem

    def delete(self, string):
        hashed_string = self._hash_func(string)
        elem = self.elems[hashed_string]

        for i in range(len(elem)):
            if elem[i] == string:
                elem.pop(i)
                break

    def find(self, string):
        hashed_string = self._hash_func(string)

        if string in self.elems[hashed_string]:
            return "yes"
        return "no"

    def check(self, i):
        return self.elems[i]

    def read_query(self):
        return Query(input().split())

    def process_query(self, query):

        if query.type == "check":
            # use reverse order, because we append strings to the end
            print(" ".join(self.check(query.ind)))
        else:
            if query.type == 'find':
                print(self.find(query.s))
            elif query.type == 'add':
                self.add(query.s)
            else:
                self.delete(query.s)

    def process_queries(self):
        n = int(input())
        for i in range(n):
            self.process_query(self.read_query())


if __name__ == '__main__':
    bucket_count = int(input())
    proc = QueryProcessor(bucket_count)
    proc.process_queries()
