
CHAR_SIZE = 26
class Trie:
    def __init__(self):
        self.isLeaf = False
        self.children = [None] * CHAR_SIZE
    def insert(self, key):
        print('Inserting…', key)
        curr = self
        for i in range(len(key)):
            index = ord(key[i]) - ord('a')
            if curr.children[index] is None:
                curr.children[index] = Trie()
            curr = curr.children[index]
        curr.isLeaf = True
    def search(self, key):
        print('Searching', key, end=': ')
        curr = self
        for c in key:
            index = ord(c) - ord('a')
            curr = curr.children[index]
            if curr is None:
                return False
        return curr.isLeaf
 
 
if __name__ == '__main__':
    head = Trie()
    head.insert('xyz')
    print(head.search('xyz'))
