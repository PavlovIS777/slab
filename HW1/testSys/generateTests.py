import random, string
import os.path
from tqdm import tqdm
import time
def randomword(length):
   letters = string.ascii_lowercase
   return ''.join(random.choice(letters) for i in range(length))

testsCountInput = int(input("Enter tests count to be generated: "))
i = 1
while (os.path.isfile("./testSys/randTests/test"+str(i)+".txt")):
    i += 1

for t in tqdm(range(1, testsCountInput+1)):
    test = []
    hits = 0
    random.seed(int(time.time()*10**10))
    cacheSize = random.randint(5, 5000)
    for k in range(random.randint(1000, 5000)):
        strTest = randomword(random.randint(5,50))
        for j in range(random.randint(50, 150)):
            test.append(strTest)

    random.shuffle(test)

    testLen = len(test)
    with open('./testSys/randTests/test'+str(i)+'.txt', 'w') as my_file:
        my_file.write(str(cacheSize)+" "+str(testLen)+"\n")
        i += 1
        for l in test:
            my_file.write(l+"\n")
