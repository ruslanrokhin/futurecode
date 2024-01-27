f = 0
print("A D K M F")
for a in range(2):
    for d in range(2):
        for k in range(2):
            for m in range(2):
                if a == 1 or k == 0:
                    f = 1
                else:
                    f = 0
                
                if f == m * d:
                    f = 0
                else:
                    f = 1
                
                print(a, d, k, m, f)