import random, string
import os.path

def randomword(length):
   letters = string.ascii_lowercase
   return ''.join(random.choice(letters) for i in range(length))

test = []
hits = 0
cacheSize = random.randint(5, 25)
for i in range(1000):
    strTest = randomword(random.randint(5,50))
    for i in range(random.randint(1, 50)):
        test.append(strTest)

random.shuffle(test)

testLen = len(test)
i = 1
while (os.path.isfile("./testSys/randTests/test"+str(i)+".txt")):
    i += 1
if i > 30:
    print("Tests files limit exceeded.")
else:
    with open('./testSys/randTests/test'+str(i)+'.txt', 'w') as my_file:
        my_file.write(str(cacheSize)+" "+str(testLen)+"\n")
        for i in test:
            my_file.write(i+"\n")
