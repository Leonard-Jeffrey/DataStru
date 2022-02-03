### 二分查找实现：
import math
def BinarySearch(array, p):
    #设置初始值，left代表查找范围的下限，right代表查找范围的上限;
    left = 0
    right = len(array) - 1
    #保证 查找范围的上限始终大于下限;
    while left <= right:
        #取中间值，检查中间元素
        mid = math.floor((left + right)/2)
        e = array[mid]
        #若中间元素正好是要查找的元素，则返回位置，否则继续缩小范围;
        if e == p:
            return mid
        elif e < p:
            left = mid + 1
        else:
            right = mid - 1
    #若找不到该元素就返回None;
    return None

array = [1,2,4,8,9,13]
num = input("请输入你想要查找的元素：")
c = BinarySearch(array, int(num))
print("您查找的元素 %s 位于位置：%s" %(num,c))