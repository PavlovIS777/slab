from importlib.resources import path
import queue
import os.path
import heapq
def find(cache, m):
    found = False
    for x, new_val in enumerate(cache):
        try:
            y = new_val.index(m)
            found = True
        except ValueError:
            found = False
            continue
        if (found):
            return (x, y)
    if (not found):
        return (-1, -1)

testNum = 1
while(os.path.isfile("./tests/test"+str(testNum)+".txt")):
    testPath = "./tests/test"+str(testNum)+".txt"
    with open('./tests/test'+str(testNum)+'.txt', 'r') as my_file:
        lines = my_file.readlines()
        inputSize = lines[0].split()
        testCnt = int(inputSize[0])
        cacheSize = int(inputSize[1])
        Hits = 0
        cache = []
        for i in range(1, testCnt+1):
            elem = find(cache, lines[i])
            if  elem[0] != -1:
                Hits += 1
                newPrior = cache[elem[0]][0] + 1
                cache.remove(cache[elem[0]])
                heapq.heappush(cache, (newPrior, lines[i]))
                heapq.heapify(cache)
            else: 
                if len(cache) >= cacheSize:
                    heapq.heappop(cache)
                heapq.heappush(cache, (1, lines[i]))
        print("test#"+str(testNum)+": "+str(Hits)+" for data from "+testPath)
    testNum += 1

