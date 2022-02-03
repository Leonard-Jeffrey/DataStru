# 动态规划： 通过解决子问题，再根据子问题的答案来解答大问题，但是，这些子问题 必须是 离散的，一个子问题  不能依赖于其他任何子问题;
# knapsack problem 背包问题

# 求最大公共子串、最大公共子序列
# 为了解决 第一行、第一列的取值问题，即当i-1,j-1为负时，无法取值的问题；设置第一行和第一列为全0状态; 这样，元素取值时从 i=1 j=1 开始，就可以避免下标为负的情况；
# 0 0 0 0 0
# 0 * * * *
# 0 * * * *
# 0 * * * *
# 0 * * * *


def maximum(a,b): #输出两个值中的较大值
    if a > b:
        return a
    else:
        return b

def print_matrix(matrix): #格式化输出矩阵
    # matrix_1 = []
    # for k in range(1,len(matrix)):
    #     matrix_1.append(matrix[k][1::])
    # print(matrix_1)
    for k in range(1,len(matrix)):
        print(matrix[k][1::])
    print("\n")

#比较两个字符串
series1 = list("fish")
series2 = list("fosh")

#开始求最大公共串
matrix = [[0 for i in range(0,len(series1) + 1)] for j in range(0,len(series2) + 1)]
for i in range(1, len(series1)+1):
    for j in range(1,len(series2)+1):
        if series1[i-1] == series2[j-1]:
            matrix[i][j] = matrix[i-1][j-1] + 1
        else:
            matrix[i][j] = 0
print_matrix(matrix)


# 开始求最大公共子序列
for i in range(1,len(series1) + 1):
    for j in range(1,len(series2) + 1):
        if series1[i-1] == series2[j-1]:
            matrix[i][j] = matrix[i-1][j-1] + 1
        else:
            matrix[i][j] = maximum(matrix[i-1][j],matrix[i][j-1])
print_matrix(matrix)