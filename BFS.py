# 最大广度优先搜索结合队列实现芒果商搜索问题
# 解决方案包括以下几步：
# 1.创建哈希表(字典)描述 图网络；
# 2.创建队列保存 搜索队列；
# 3.创建列表保存 一个朋友是否被搜索过的信息；

    Thom <-----                            -----------> alice
                claire <-------------- you                    ----> peggy
   jonny <-----                            -----------> bob
                                                              ----> anuj



from collections import deque

# 1.创建哈希表，保存 朋友网络信息
graph = {}
graph["you"] = ["alice","bob","claire"]
graph["bob"] = ["anuj","peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom","jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []

# 2.创建队列 作为搜索队列，保存待搜索对象;
# 根据BFS原理，搜索队列最初只包含 “你” 的朋友，然后根据广度依次向外扩展；
search_queue = deque()
search_queue += graph["you"]

# 3.创建列表 保存 搜索队列中的朋友是否已经被搜索过；开始搜索...
searched = []
# 构造检测一个“朋友”是否为芒果售卖商的函数
def IsSeller(person):
    if person[-1] == 'm':
        return True
    return False

while search_queue:
    person = search_queue.popleft()
    if person not in searched:
        if IsSeller(person):
            print(person + " is a mango seller")
        else:
            searched.append(person)
            search_queue += graph[person]

