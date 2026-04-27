from collections import deque
from collections import namedtuple


def bfs(start_node, end_node, graph):  # 开始节点  目标节点 图字典
    node = namedtuple('node', 'name, from_node')    # 使用namedtuple定义节点，用于存储前置节点
    search_queue = deque()  # 使用双端队列，这里当作队列使用，根据先进先出获取下一个遍历的节点
    name_search = deque()   # 存储队列中已有的节点名称
    visited = {}            # 存储已经访问过的节点

    search_queue.append(node(start_node, None))  # 填入初始节点，从队列后面加入
    name_search.append(start_node)               # 填入初始节点名称
    path = []               # 用户回溯路径
    path_len = 0            # 路径长度

    print('开始搜索...')
    while search_queue:     # 只要搜索队列中有数据就一直遍历下去
        print('待遍历节点: ', name_search)
        current_node = search_queue.popleft()  # 从队列前边获取节点，即先进先出，这是BFS的核心
        name_search.popleft()                  # 将名称也相应弹出
        if current_node.name not in visited:   # 当前节点是否被访问过
            print('当前节点: ', current_node.name, end=' | ')
            if current_node.name == end_node:  # 退出条件，找到了目标节点，接下来执行路径回溯和长度计算
                pre_node = current_node        # 路径回溯的关键在于每个节点中存储的前置节点
                while True:                    # 开启循环直到找到开始节点
                    if pre_node.name == start_node:  # 退出条件：前置节点为开始节点
                        path.append(start_node)      # 退出前将开始节点也加入路径，保证路径的完整性
                        break
                    else:
                        path.append(pre_node.name)   # 不断将前置节点名称加入路径
                        pre_node = visited[pre_node.from_node]  # 取出前置节点的前置节点，依次类推
                path_len = len(path) - 1       # 获得完整路径后，长度即为节点个数-1
                break
            else:
                visited[current_node.name] = current_node   # 如果没有找到目标节点，将节点设为已访问，并将相邻节点加入搜索队列，继续找下去
                for node_name in graph[current_node.name]:  # 遍历相邻节点，判断相邻节点是否已经在搜索队列
                    if node_name not in name_search:        # 如果相邻节点不在搜索队列则进行添加
                        search_queue.append(node(node_name, current_node.name))
                        name_search.append(node_name)
    print('搜索完毕,最短路径为:', path[::-1], "长度为:", path_len)  # 打印搜索结果


if __name__ == "__main__":

    graph = dict()      # 使用字典表示有向图
    graph[1] = [3, 2]
    graph[2] = [5]
    graph[3] = [4, 7]
    graph[4] = [6]
    graph[5] = [6]
    graph[6] = [8]
    graph[7] = [8]
    graph[8] = []
    bfs(1, 8, graph)    # 执行搜索