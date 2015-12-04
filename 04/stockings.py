import hashlib

def hashHasTarget( phrase, target ):
    m = hashlib.md5()
    m.update(phrase)
    return m.hexdigest()[0:6] == target

key = "yzbqklnj"
target = "000000"

i = 0
while not hashHasTarget( key+str(i), target ):
    i += 1

print i