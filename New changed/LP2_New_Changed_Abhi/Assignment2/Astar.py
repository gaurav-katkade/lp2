# 8 Puzzle using A*

def Display(arr):
	for i in range(3):
		for j in range(3):
			print(arr[i][j],end=" ")
		print()
		
def make_copy(arr):
	n_arr = []
	for i in range(3):
		n_arr.append([])
		for j in range(3):
			n_arr[i].append(arr[i][j])
	return n_arr
	

start = []
end = []
for i in range(3):
	start.append([])
	end.append([])
	for j in range(3):
		start[i].append([])
		end[i].append([])
		
end[0][0] = 1
end[0][1] = 2
end[0][2] = 3
end[1][2] = 6
end[2][2] = "_"
end[2][1] = 8
end[2][0] = 7
end[1][0] = 4
end[1][1] = 5

k = 1	
pos = []	
for i in range(3):
	for j in range(3):
		ask = input("Enter value for position " + str(k) + " : ")
		k += 1
		if(ask.isnumeric() == True):
			start[i][j] = int(ask)
		else:
			start[i][j] = "_"
			pos = [i,j]
print("pos",pos)
			
print("\nStart node : ")
Display(start)
print("\nGoal node : ")
Display(end) 

def heuristic(x,y):
	count = 0
	for i in range(3):
		for j in range(3):
			if(x[i][j] == y[i][j] and x[i][j] != "_"):
				continue
			elif(x[i][j] == "_"):
				continue
			else:
				count += 1
	return count

count = heuristic(start,end)
print("initially h(n) is : ",count)
while(count != 0):
	m = 9
	tp = []
	# check left
	if(pos[1] >= 1):
		new_copy = make_copy(start)
		l = new_copy[pos[0]][pos[1]-1]
		new_copy[pos[0]][pos[1]] = l
		new_copy[pos[0]][pos[1]-1] = "_"
		k = heuristic(new_copy,end)
		if(k < m):
			m = k
			tp = [pos[0],pos[1]-1]
	# check right
	if(pos[1] < 2):
		new_copy1 = make_copy(start)
		r = new_copy1[pos[0]][pos[1]+1]
		new_copy1[pos[0]][pos[1]] = r
		new_copy1[pos[0]][pos[1]+1] = "_"
		k = heuristic(new_copy1,end)
		if(k < m):
			m = k
			tp = [pos[0],pos[1]+1]
	# check top
	if(pos[0] >= 1):
		new_copy2 = make_copy(start)
		t = new_copy2[pos[0]-1][pos[1]]
		new_copy2[pos[0]][pos[1]] = t
		new_copy2[pos[0]-1][pos[1]] = "_"
		k = heuristic(new_copy2,end)
		if(k < m):
			m = k
			tp = [pos[0]-1,pos[1]]
	# check bottom
	if(pos[0] < 2):
		new_copy3 = make_copy(start)
		b = new_copy3[pos[0]+1][pos[1]]
		new_copy3[pos[0]][pos[1]] = b
		new_copy3[pos[0]+1][pos[1]] = "_"
		k = heuristic(new_copy3,end)
		if(k < m):
			m = k
			tp = [pos[0]+1,pos[1]]
			
	count = m
	old = start[tp[0]][tp[1]]
	start[tp[0]][tp[1]] = "_"
	start[pos[0]][pos[1]] = old
	pos = tp
	
	Display(start)
	print("heuristic value is : ",count)


		
	


