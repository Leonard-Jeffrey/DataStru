# 递归练习
import math

# 1.使用“递归思想”实现对列表所有元素求和；
# 删除法
def Sum(array):
    sum = 0
    if len(array) == 0:
        return sum
    e = array[0]
    array.remove(e)
    sum = e + Sum(array)
    return sum

# 切片法
def Sum2(array):
    if array == []:
        return 0
    else:
        return array[0] + Sum2(array[1::])

# 2.使用“递归思想”计算列表中元素个数；
def Count(array):
    if array == []:
        return 0
    else:
        return 1 + Count(array[1::])

# 3.使用“递归思想”找出列表中最大数；
# 若array为空列表，则返回None, 如果array只有一个值，则返回该值，否则进行比较；
def Maximum(array):
    if array == []:
        return None
    elif len(array) == 1:
        return array[0]
    else:
        if array[0] > Maximum(array[1::]):
            return array[0]
        else:
            return Maximum(array[1::])

# 4.使用“递归思想”实现二分查找；
def BinarySearch2(array, item):
    left = 0
    right = len(array) - 1
    mid = math.floor((left + right)/2)
    if array[mid] == item:
        return mid
    elif array[mid] > item:
        right = mid -1
        if left > right:
            return -1
        return BinarySearch2(array[left:right+1:1],item)
    else:
        left = mid + 1
        if left > right:
            return -1
        f = BinarySearch2(array[left:right+1:1],item)
        if f == -1:
            return -1
        else:
            return mid + 1 + f

# 测试用例
array = [-10,-9,-8,-7,-6,-1]
sum = Sum2(array)
print(sum)
count = Count(array)
print(count)
max = Maximum(array)
print(max)
pos = BinarySearch2(array,-9)
print(pos)
