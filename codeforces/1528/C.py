#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase

# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
    
class FenwickTree:
    def __init__(self, x):
        """transform list into BIT"""
        self.bit = x
        for i in range(len(x)):
            j = i | (i + 1)
            if j < len(x):
                x[j] += x[i]
    def update(self, idx, x):
        """updates bit[idx] += x"""
        while idx < len(self.bit):
            self.bit[idx] += x
            idx |= idx + 1

    def query(self, end):
        """calc sum(bit[:end])"""
        end += 1
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x

    def findkth(self, k):
        """Find largest idx such that sum(bit[:idx]) <= k"""
        idx = -1
        for d in reversed(range(len(self.bit).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(self.bit) and k >= self.bit[right_idx]:
                idx = right_idx
                k -= self.bit[idx]
        return idx + 1

g1 = []
g2 = []
st = []
ft = []

def dfs1(graph, start=0):
    n = len(graph)
    tim = 1
    visited = [False] * n    
    stack = [start]
    while stack:
        start = stack[-1]
        if not visited[start]:
            st[start] = tim
            tim = tim + 1
            visited[start] = True
            for child in graph[start]:
                if not visited[child]:
                    stack.append(child)
        else:
            stack.pop()
            ft[start] = tim



def Do(v):
    global ans , cnt , mem
    fen.update(st[v] , 1);
    if(fen.query(ft[v] - 1) - fen.query(st[v])):
        mem += [[v , 0 , 0]]
        return;
    u = fen2.query(st[v]);
    ok[v] = 1
    cnt += 1
    fen2.update(st[v] , v - u)
    fen2.update(ft[v] , u - v)
    mem += [[v , u , ok[u]]]
    cnt -= ok[u]
    ok[u] = 0
    return;



def undo():
    global cnt , ans , mem
    [v , u , a] = mem[-1]
    if(a != 0):
        ok[u] = 1
        cnt += 1
    cnt -= 1
    ok[v] = 0
    fen.update(st[v] , -1)
    fen2.update(st[v] , u - v)
    fen2.update(ft[v] , v - u)
    mem.pop()
    return;


def dfs(graph, start=0):
    global ans , cnt
    n = len(graph)
    visited = [False] * n   
    stack = [start]
    while stack:
        start = stack[-1]
        if not visited[start]:
            Do(start)
            ans = max(ans , cnt)
            visited[start] = True
            for child in graph[start]:
                if not visited[child]:
                    stack.append(child)
        else:
            stack.pop()
            undo()



def solve():
    global n, g1 , g2 , V , st , ft , fen , fen2 , mem , ok , cnt , ans 
    n = int(input())
    if(n == 1):
        print(1)
        exit(0)
    
    g1 = [] ; g2 = []
    
    for i in range(n):
        g1.append([])
        g2.append([])
    
    # 0 base 
    
    V = list(map(int , input().split()))
    
    for i in range ( 1 , n ):
        v = V[i - 1]-1
        g1[v].append(i)
    
    V = list(map(int , input().split()))    
    
    for i in range ( 1 , n ):
        v = V[i-1]-1
        g2[v].append(i)
    st = [0] * (n + 100)
    ft = [0] * (n + 100)
    fen = FenwickTree([0] * (n + 3))
    fen2 = FenwickTree([0] * (n + 3))
    mem = []
    ok = [0]*(n + 100)
    cnt = 0
    ans = 0
    dfs1(g2)
    dfs(g1)
    print(ans)

q = int(input())
for i in range (q):
    solve()
