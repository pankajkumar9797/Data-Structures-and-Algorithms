# python3

class HeapBuilder:
  def __init__(self):
    self._swaps = []
    self._data = []

  def readData(self):
    n = int(input())
    self._data = [int(s) for s in input().split()]
    assert n == len(self._data)

  def writeResponse(self):
    print(len(self._swaps))
    for swap in self._swaps:
      print(swap[0], swap[1])

  def shiftdown(self, i):
    minIndex = int(i)
    left = 2*i + 1

    if left < len(self._data) and self._data[left] < self._data[minIndex]:
      minIndex = left

    right = 2*i + 2
    if right < len(self._data) and self._data[right] < self._data[minIndex]:
      minIndex = right

    if i != minIndex:
      self._swaps.append((i, minIndex))
      self._data[i], self._data[minIndex] = self._data[minIndex], self._data[i]
      self.shiftdown(minIndex)


  def generateSwaps(self):
    # The following naive implementation just sorts 
    # the given sequence using selection sort algorithm
    # and saves the resulting sequence of swaps.
    # This turns the given array into a heap, 
    # but in the worst case gives a quadratic number of swaps.
    #
    # TODO: replace by a more efficient implementation
    #for i in range(len(self._data)):
    #  for j in range(i + 1, len(self._data)):
    #    if self._data[i] > self._data[j]:
    #      self._swaps.append((i, j))
    #      self._data[i], self._data[j] = self._data[j], self._data[i]

    size = len(self._data)
    for i in range(len(self._data)//2, -1, -1):
      self.shiftdown(i)


  def solve(self):
    self.readData()
    self.generateSwaps()
    self.writeResponse()


if __name__ == '__main__':
    heap_builder = HeapBuilder()
    heap_builder.solve()
