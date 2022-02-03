# 迪克斯特拉算法用于 求 加非负权值的 有向的 无环图 中 任意两点之间 的最短路径；
# 贝尔曼福德算法用于 求 加正、负权值的 有向的 无环图 中 任意两点之间 的最短路径；
# 当所有边的 权值 都一样时，狄克斯特拉算法 退化为BFS算法；

# 创建初始值
infinite = float("inf")
graph = {}
graph["start"] = {'A':6,'B':2 }
graph['A'] = {'final':1}
graph['B'] = {'A':3,'final':5}
graph['final'] = {}

# 起点到每个节点的最小开销
costs = {}
costs["A"] = 6
costs["B"] = 2
costs["final"] = infinite

# 实现最小开销的每个节点的父节点
perants = {}
perants["A"] = "start"
perants["B"] = "start"
perants["final"] = None

# 已处理过的节点
processed = []


print(graph)
print(costs)
print(processed)
print(perants)

# 找到未处理的 节点中 开销 最小的点
def FindLowestCostNode(costs, processed):
    LowestCostNode = None
    LowestCost = float("inf")
    for node in costs.keys():
        if (node not in processed) and (LowestCost > costs[node]):
            LowestCost = costs[node]
            LowestCostNode = node
    return LowestCostNode

LowestCostNode = FindLowestCostNode(costs,processed)
while LowestCostNode is not None:
    #print(LowestCostNode)
    cost = costs[LowestCostNode]
    neighbour = graph[LowestCostNode]
    for node in neighbour.keys():
        NewCost = cost + neighbour[node]
        if NewCost < costs[node]:
            costs[node] = NewCost
            perants[node] = LowestCostNode
    processed.append(LowestCostNode)
    LowestCostNode = FindLowestCostNode(costs, processed)


print(perants)


