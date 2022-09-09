import queue
import os.path
import heapq
import time
def find(cache, m):
    for i in range(len(cache)):
        for j in range(len(cache[i])):
            try:
                if cache[i][j] == m:
                    return [i, j]
            except IndexError:
                continue
    return [-1, -1]

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
            curtime = time.time()
            elem = find(cache, lines[i])
            if  elem[0] != -1:
                Hits += 1
                newPrior = cache[elem[0]][0][0] + 1
                cache.remove(cache[elem[0]])
                heapq.heappush(cache, ((newPrior, curtime), lines[i]))
                heapq.heapify(cache)
            else: 
                if len(cache) == cacheSize:
                    heapq.heappop(cache)
                heapq.heappush(cache, ((1, curtime), lines[i]))
                heapq.heapify(cache)
        print("test#"+str(testNum)+": "+str(Hits)+" for data from "+testPath)
    testNum += 1

