from pymongo import MongoClient
import random, string, time

def generateRandomName(n):
   randlst = [random.choice(string.ascii_letters + string.digits) for i in range(n)]
   return ''.join(randlst)

def connectDB():
    client = MongoClient(host="127.0.0.1", port=27017)
    return client

def main():
    c = connectDB()
    db = c["test"]
    db.test_string.remove({})

    for j in range(10):
        cursol = None
        string = ""
        for i in range(10000):
            string = generateRandomName(20)
            doc = {"key":string} 
            db.test_string.insert_one(doc)
            cursol = db.test_string.find({"key":string})

        for k in range(20):
            cursol = db.test_string.find({"key":string})
            s = time.time()
            list_ = list(cursol) 
            e = time.time()
            print(e-s)

        print()


if __name__ == "__main__":
    main()
