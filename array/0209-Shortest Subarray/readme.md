可以理解为找一个上三角矩阵的最短路径（重复字符问题）
1.若（left,right)满足target,则（left,right+1....end)满足target
此时向右移动left指针
2.若（left,right)不满足target,则（left+1,right)不满足target
此时向右移动right指针
