#include <iostream>
#include <vector>

const int SIZE = 8;

bool isValidMove(int x, int y, std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == -1);
}

bool knightTourUtil(int x, int y, int moveCount, std::vector<std::vector<int>>& board, std::vector<std::pair<int, int>>& path) {
    static int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
    static int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

    board[x][y] = moveCount;
    path.push_back(std::make_pair(x, y));

    if (moveCount == SIZE * SIZE) {
        // Выводим найденный маршрут
        for (const auto& pos : path) {
            std::cout << "(" << pos.first << ", " << pos.second << ") ";
        }
        std::cout << std::endl;

        // Возвращаем false, чтобы продолжить поиск других маршрутов
        return false;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValidMove(nextX, nextY, board)) {
            if (knightTourUtil(nextX, nextY, moveCount + 1, board, path)) {
                // Если найден маршрут, возвращаем true и заканчиваем поиск
                return true;
            }
        }
    }

    // Если не найдено ни одного маршрута, отменяем последнее перемещение коня
    board[x][y] = -1;
    path.pop_back();

    // Возвращаем false, чтобы продолжить поиск других маршрутов
    return false;
}

void knightTour(int startX, int startY) {
    std::vector<std::vector<int>> board(SIZE, std::vector<int>(SIZE, -1));
    std::vector<std::pair<int, int>> path;

    knightTourUtil(startX, startY, 1, board, path);
}

int main() {
    int startX, startY;

    std::cout << "Enter the starting position (x, y) of the knight: ";
    std::cin >> startX >> startY;

    knightTour(startX, startY);

    return 0;
}