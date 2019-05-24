while(True):
    n, m, t, p = map(int, input().split())
    if(n==0 and m==0 and t==0 and p==0):
        break
    paper = []
    c1 = 0
    c2 = 0
    for i in range(m*2):
        # 初期の長方形
        paper.append([int(0) for j in range(n*2)])
    for i in range(m):
        for j in range(n):
            paper[i][j]=1
    for i in range(t):
        d, c = map(int, input().split())
        # 折る処理
        if (d == 1):  # 左から右
            if ((n - c1)/2 < c and (n - c1)/2 != c):
                Protrude=c-(n-(c1+c))
                c1 += c

                for j in range(c):
                    for k in range(m):
                        paper[k][n - c1 - j - 1] += paper[k][n - c1 + j]
                        paper[k][n - c1 + j] = 0

                for j in range(m*2):
                    for k in range(Protrude):
                        paper[j].insert(0,int(paper[j][len(paper[j])-Protrude]))
                c1 -= Protrude

            else:# 正常
                c1 += c
                for j in range(c):
                    for k in range(m):
                        paper[k][n - c1 - j - 1] += paper[k][n - c1 + j]
                        paper[k][n - c1 + j] = 0

        if (d == 2):  # 下から上

            if ((m - c2)/2 < c):
                Protrude=c-(m-(c2+c))
                c2 += c
                for j in range(c):
                    for k in range(m):
                        paper[m - c2 - 1 - j][k] += paper[m - c2 + j][k]
                        paper[m - c2 + j][k] = 0

                for k in range(Protrude):
                    paper.insert(0,paper[len(paper[k])-Protrude])
                c2 -= Protrude

            else:# 正常
                c2 += c
                for j in range(c):
                    for k in range(n):
                        paper[m - c2 - 1 - j][k] += paper[m - c2 + j][k]
                        paper[m - c2 + j][k] = 0

    for i in range(p):
        x, y = map(int, input().split())
        # 数える処理
        print(paper[m - 1 - c2 - y][n - 1 - c1 - x])
