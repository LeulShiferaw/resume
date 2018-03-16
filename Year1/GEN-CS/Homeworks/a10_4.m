fun move(1, s, e) = [(s, e)] |
    move(n, 1, 2) = move(n-1, 1, 3) @ [(1, 2)] @ move(n-1, 3, 2) |
    move(n, 1, 3) = move(n-1, 1, 2) @ [(1, 3)] @ move(n-1, 2, 3) |
    move(n, 2, 1) = move(n-1, 2, 3) @ [(2, 1)] @ move(n-1, 3, 2) |
    move(n, 2, 3) = move(n-1, 2, 1) @ [(2, 3)] @ move(n-1, 1, 3) |
    move(n, 3, 1) = move(n-1, 3, 2) @ [(3, 1)] @ move(n-1, 2, 1) |
    move(n, 3, 2) = move(n-1, 3, 1) @ [(3, 2)] @ move(n-1, 1, 2);

fun hanoi(n) = move(n, 1, 3);
