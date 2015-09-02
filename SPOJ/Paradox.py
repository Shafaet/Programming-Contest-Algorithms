
def dfs(u, cost):
	if u==0: return
	global flag
	if u in vis and vis[u]==1: 
		if (cost-mem[u])%2==1: 
			flag=0
		return
	mem[u]=cost
	vis[u]=1
	dfs(edg[u], cost+cst[u])
	vis[u]=2
	
while True:
	vis={}
	
	n=int(raw_input())
	if n==0: break
	mem=[0 for i in range(0,n+2)]
	edg=[0 for i in range(0,n+2)]
	cst=[0 for i in range(0,n+2)]
	flag=1
	for i in range(1,n+1):
		s=raw_input().split(" ")
		if int(s[0])==i:
			if s[1]=="false": flag=0
			continue
		edg[i]=int(s[0])
		if s[1]=="false": cst[i]=1
	
	for i in range(1,n+1):
		dfs(i,0)
	
	if flag==0: print "PARADOX"
	else: print "NOT PARADOX"



