#排序大集合：
# 1-选择排序
# 2-快速排序


# 排序算法1-选择排序
def SelectSorting(array):
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

array=[1,3,6,6,6,6,6]
array2=SelectSorting(array)
#print(array2)

#排序算法2-快速排序
