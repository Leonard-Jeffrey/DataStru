#排序大集合：
# 1-选择排序
# 2-快速排序
# 3-归并排序
# 4-


# 排序算法1-选择排序
# 时间复杂度：n + n-1 + n-2 + ... + 1 = n(n + 1)/2 = O(n^2 + n/2) = O(n^2)
def SelectSort(array):
    array2 = []
    length = len(array)
    for j in range(0, length):
        flag = array[0]
        for i in range(1, len(array)):
            if flag < array[i]:
                flag = array[i]
        array2.append(flag)
        array.remove(flag)
    return array2

# 排序算法2-快速排序
# 时间复杂度：O(n logn)
def QuickSort(array):
    if len(array) <2:
        return array
    else:
        base = array[0]
        less = [i for i in array[1:] if i <= base]
        greater = [i for i in array[1:] if i > base]
        return QuickSort(less) + [base] + QuickSort(greater)

# 3-归并排序


# 测试用例
array=[35,14,33,66,34,678,3768]
array2=QuickSort(array)
print(array2)
