inp = list(map(int , input().split()))
sinp = sorted(inp , reverse = True)
def main():
     if sum(inp) % 2 == 1:
          print("NO")
          return
     for i in range(6):
          for j in range(6):
               for jj in range(6):
                    if i != j and j != jj and i != jj:
                         if sum(inp) - (sinp[i] + sinp[j] + sinp[jj]) == sum(inp) // 2:
                              print("YES")
                              return
                              print("NO")
     print("NO")
main()