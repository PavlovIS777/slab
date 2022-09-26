import random, string
import os
from tqdm import tqdm
import time

def randomword(length):
   letters = string.ascii_lowercase
   return ''.join(random.choice(letters) for i in range(length))

testsCountInput = int(input("Enter tests count to be generated: "))
i = 1
if not os.path.isdir("./testSys/randTests"):
    os.mkdir("./testSys/randTests")

while (os.path.isfile("./testSys/randTests/test"+str(i)+".dat")):
        i += 1

random.seed(int(time.time())*10**10)

for t in tqdm(range(1, testsCountInput+1)):
    test = []
    hits = 0
    cacheSize = random.randint(50, 500)
    for k in range(random.randint(2000, 10000)):
        strTest = randomword(random.randint(5, 40))
        for j in range(random.randint(50, 100)):
            test.append((k, strTest))

    random.shuffle(test)

    testLen = len(test)
    with open('./testSys/randTests/unittest'+str(i)+'.dat', 'w') as my_file:
        my_file.write(str(cacheSize)+" "+str(testLen)+"\n")
        for l in test:
            my_file.write(str(l[0])+" "+l[1]+"\n")
    with open('./testSys/randTests/test'+str(i)+'.txt', 'w') as my_file:
        my_file.write(str(cacheSize)+" "+str(testLen)+"\n")
        i += 1
        for l in test:
            my_file.write(l[1]+"\n")
