# lc705.py

# LeetCode 705. Design HashSet `E`
# acc | 99% | 15'
# A~0h01

class MyHashSet:

    def __init__(self):
        self.hs = bytearray(1000001)

    def add(self, key: int) -> None:
        if not self.hs[key]:
            self.hs[key] = True

    def remove(self, key: int) -> None:
        if self.hs[key]:
            self.hs[key] = False

    def contains(self, key: int) -> bool:
        return self.hs[key]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
