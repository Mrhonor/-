Description (附加题)
输入一个自然数N，对于一个最简分数a/b（分子和分母互质的分数），满足1<=b<=N,0<=a/b<=1，请找出所有满足条件的分数。例子：当N=5时，所有解为： 0/1 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 1/1 给定一个自然数N，1<=N<=160，请编程按分数值递增的顺序输出所有解。 注：1）0和任意自然数的最大公约数就是该自然数；2）两自然数互质是指这两个自然数的最大公约数等于1。

Input
自然数N，1<=N<=160。

Output
每个分数单独占一行（最后一个分数的后面也有换行），按照大小次序排列。注意：1）要求输出a/b的形式，而不是除法的数值结果。例如应该输出1/2，而不是0.5；2）由于0/1、0/2、…、0/N数值相等，只需输出0/1即可。

Sample Input
5

Sample Output
0/1
1/5
1/4
1/3
2/5
1/2
3/5
2/3
3/4
4/5