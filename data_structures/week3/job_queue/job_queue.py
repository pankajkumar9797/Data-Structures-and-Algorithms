# python3

class MinHeap:
    def __init__(self, number_workers):
        self.n = number_workers
        self._data = []
        for i in range(number_workers):
            self._data.append((i, 0))

    def parent(self, i):
        return (i - 1)//2

    def compare_workers(self, worker1, worker2):
        if worker1[1] != worker2[1]:
            return worker1[1] < worker2[1]
        else:
            return worker1[0] < worker2[0]

    def sift_up(self, i):
        while i > 0 and self.compare_workers(self._data[i], self._data[self.parent(i)]):
            self._data[self.parent(i)], self._data[i] = self._data[i], self._data[self.parent(i)]
            i = self.parent(i)

    def sift_down(self, i):
        minIndex = int(i)
        left = 2 * i + 1

        if left < len(self._data) and self.compare_workers(self._data[left], self._data[minIndex]):
            minIndex = left

        right = 2 * i + 2
        if right < len(self._data) and self.compare_workers(self._data[right], self._data[minIndex]):
            minIndex = right

        if i != minIndex:
            self._data[i], self._data[minIndex] = self._data[minIndex], self._data[i]
            self.sift_down(minIndex)

    def change_priority(self, index, priority):
        priority_old = self._data[index][1]
        self._data[index] = (self._data[index][0], priority)
        if priority < priority_old:
            self.sift_up(index)
        else:
            self.sift_down(index)

        self.sift_down(index)

class JobQueue:
    def read_data(self):
        self.num_workers, m = map(int, input().split())
        self.jobs = list(map(int, input().split()))
        assert m == len(self.jobs)

    def write_response(self):
        for i in range(len(self.jobs)):
          print(self.assigned_workers[i], self.start_times[i])

    def assign_jobs(self):
        # TODO: replace this code with a faster algorithm.
        self.assigned_workers = [None] * len(self.jobs)
        self.start_times = [None] * len(self.jobs)
        min_heap = MinHeap(self.num_workers)

        for i in range(len(self.jobs)):
            self.assigned_workers[i] = min_heap._data[0][0]
            self.start_times[i] = min_heap._data[0][1]
            min_heap.change_priority(0, min_heap._data[0][1] + self.jobs[i])

    def solve(self):
        self.read_data()
        self.assign_jobs()
        self.write_response()

if __name__ == '__main__':
    job_queue = JobQueue()
    job_queue.solve()

