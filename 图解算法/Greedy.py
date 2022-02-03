# 广播电台
import time
# 建立集合 包含所有要包含的州
AllStates = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])
# 建立字典 字典里的每个元素是一个集合 包含所有广播电台 及其范围内的州
stations = {}
stations["kone"] = set(["id","nv","ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or","nv","ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])
#print(stations)

# 建立集合 保存最终选择的广播台有哪些
FinalStations = set()

# 定义变量BestStation来保存每一次搜索得到的覆盖范围最广的广播站
# StatesCovered表示 BestStation 所覆盖的 之前尚未被覆盖的州

while AllStates:
    BestStation = None
    StatesCovered = set()
    for Station, StatesOfStation in stations.items():
        Covered = StatesOfStation & AllStates
        if len(Covered) > len(StatesCovered):
            BestStation = Station
            StatesCovered = StatesOfStation
    time.sleep(5)
    FinalStations.add(BestStation)
    AllStates -= StatesCovered
print(FinalStations)


