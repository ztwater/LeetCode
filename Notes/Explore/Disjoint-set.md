# Disjoint-set Data Structure 

## Brief Introduction

也被称为Union-find data structure，中文即并查集。用于将一组元素划分成若干个互不相交的子集，其添加新集合/合并子集/判断两元素是否在同一集合的操作可在接近常数时间内完成（基于Inverse Ackermann Function），是Kruskal's algorithm和minimum spanning tree（最小生成树）的基础。

## Representation
```
index: 0 1 2 3 4 5 6  ... 
p    : 0 1 2 3 4 5 6  ...
rank : 0 0 0 0 0 0 0  ...
```

## Operations

### Initialize
```
for (int i = 0; i < size; i++) {
	p[i] = index;
}
```
### Path Compression
```
int find (int index) {
	if (index != p[index]) {
		p[index] = p[p[index]];
	}
	return p[index];
}
```
### Path Halving & Path Splitting
```
//halving
int find (int index) {
	while (index != p[index]) P{
		p[index] = p[p[index]];
		index = p[index];
	}
	return index;
}

//splitting
int find (int index) {
	while (index != p[index]) P{
		int tmp = p[index];
		p[index] = p[p[index]];
		index = tmp;
	}
	return index;
}
```
### Union (By rank or size)	
```
void union_1 (int idx1, int idx2) {
	int p1 = find(idx1);
	int p2 = find(idx2);

	if (p1 == p2) return;

	if (rank[p1] <= rank[p2]) {
		p[p1] = p2;
		if (rank[p1] == rank[p2]) rank[p2]++;
	} 
	else {
		p[p2] = p1;
	}
}
```