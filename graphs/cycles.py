def add_edge(graph, u, v):
    """
    Add an edge from node u to node v in the graph.
    """
    graph[u].append(v)


def add_edge_undirected(graph, u, v):
    """
    Add an undirected edge between node u and node v in the graph.
    """
    graph[u].append(v)
    graph[v].append(u)


def has_cycle_visit(graph, u, visited, parent):
    """
    Helper function to check if there is a cycle in an undirected graph using DFS.
    """
    visited[u] = True
    for v in graph[u]:
        if not visited[v]:
            if has_cycle_visit(graph, v, visited, u):
                return True
        elif v != parent:
            return True
    return False


def has_cycle(graph):
    """
    Check if the undirected graph has a cycle using DFS.
    """
    n = len(graph)
    visited = [False] * n
    for i in range(n):
        if not visited[i]:
            if has_cycle_visit(graph, i, visited, -1):
                return True
    return False


def has_cycle_visit_directed(graph, u, visited, recursion_stack):
    """
    Helper function to check if there is a cycle in a directed graph using DFS.
    """
    visited[u] = True
    recursion_stack[u] = True
    for v in graph[u]:
        if not visited[v]:
            if has_cycle_visit_directed(graph, v, visited, recursion_stack):
                return True
        elif recursion_stack[v]:
            return True
    recursion_stack[u] = False
    return False


def has_cycle_directed(graph):
    """
    Check if the directed graph has a cycle using DFS.
    """
    n = len(graph)
    visited = [False] * n
    recursion_stack = [False] * n
    for i in range(n):
        if not visited[i]:
            if has_cycle_visit_directed(graph, i, visited, recursion_stack):
                return True
    return False


if __name__ == "__main__":
    # Input number of nodes and edges
    n, e = map(int, input().split())

    # Adjacency list for the directed and undirected graphs
    adj_list = [[] for _ in range(n)]
    adj_list_undirected = [[] for _ in range(n)]

    # Adding edges to the graphs
    for _ in range(e):
        u, v = map(int, input().split())
        add_edge(adj_list, u, v)
        add_edge_undirected(adj_list_undirected, u, v)

    # Checking for cycles in directed and undirected graphs
    if has_cycle_directed(adj_list):
        print("Has cycle in directed graph.")
    else:
        print("Doesn't have cycle in directed graph.")

    if has_cycle(adj_list_undirected):
        print("Has cycle in undirected graph.")
    else:
        print("Doesn't have cycle in undirected graph.")
