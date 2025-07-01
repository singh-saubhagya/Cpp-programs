/*ocedure Shortest_Cycle(G, v)
    Let n be the number of vertices in G
    Let dist be a list of size n, initialized with infinity
    Let prev be a list of size n, initialized with None

    Set dist[v] to 0
    Create a queue and enqueue v into it

    While queue is not empty
        Dequeue an element from queue and call it u
        For each vertex w adjacent to u in G
            If dist[w] is infinity
                Set dist[w] to dist[u] + 1
                Set prev[w] to u
                Enqueue w into queue
            Else if w is v
                Return Build_Cycle(prev, u)

    Return None

End Procedure

Procedure Build_Cycle(prev, u)
    Initialize an empty list cycle
    While u is not None
        Append u to cycle
        Set u to prev[u]
    Reverse the list cycle
    Return cycle

End Procedure
