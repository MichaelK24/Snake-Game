#include "snake.h"

Snake::Snake(sf::RenderWindow& window)
{
    
    init();
    update();

    float smallerTileWidth = TileWidth * 4 / 5;

    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            array[i][j].setSize({smallerTileWidth, smallerTileWidth});
            array[i][j].setPosition(TOP.x + smallerTileWidth * i - 150, TOP.y + smallerTileWidth * j + 35);
            array[i][j].setOrigin(array[i][j].getSize().x / 2, array[i][j].getSize().y / 2);
            array[i][j].setFillColor(sf::Color::Green);
            array[i][j].setOutlineThickness(1);
            array[i][j].setOutlineColor(sf::Color::Black);
        }
    }
}
void Snake::init()
{
    initBoard();
    board[7][7] = 's';
    board[11][7] = 'A';

    Point initialPosition = {7,7};
    snake.clear();
    snake.push_back(initialPosition);
    dir = " ";
    score = 0;
    gameOver = false;
}

void Snake::initBoard() {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            board[i][j] = ' ';
        }
    }
}

void Snake::update() {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            switch (board[i][j]) {
                case 'S':
                    array[i][j].setFillColor(sf::Color::Blue);
                    break;
                case 'A':
                    array[i][j].setFillColor(sf::Color::Red);
                    break;
                case 's':
                    array[i][j].setFillColor(sf::Color::Yellow);
                    break;
                default:
                    array[i][j].setFillColor(sf::Color::Green);
            }
        }
    }
}

void Snake::turnInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W:
                dir = "up";
                break;
            case sf::Keyboard::S:
                dir = "down";
                break;
            case sf::Keyboard::A:
                dir = "left";
                break;
            case sf::Keyboard::D:
                dir = "right";
                break;
            case sf::Keyboard::Escape:
                dir = "end";
                break;
            default:
                break;
        }
    }
}

bool Snake::actualTurn() {
    if (gameOver) return true;

    Point newH = snake.front();

    if (dir == "up") {
        newH.y--;
    } else if (dir == "down") {
        newH.y++;
    } else if (dir == "right") {
        newH.x++;
    } else if (dir == "left") {
        newH.x--;
    } else if (dir == "end") {
        gameOver = true;
        return true;
    }

    if (newH.x >= 17 || newH.x < 1 || newH.y >= 17 || newH.y < 1) {
        gameOver = true;
        return true;
    }

    for (unsigned i = 0; i < snake.size() - 1; i++) {
        if (snake[i].x == newH.x && snake[i].y == newH.y) {
            gameOver = true;
            return true;
        }
    }

    if (board[newH.x][newH.y] == 'A') {
        score++;
        srand(time(NULL));
        int row, col;
        do {
            row = rand() % 17;
            col = rand() % 17;
        } while (board[row][col] != ' ');
        board[row][col] = 'A';
    } else {
        Point old = snake.back();
        snake.pop_back();
        board[old.x][old.y] = ' ';
    }

    snake.insert(snake.begin(), newH);
    board[newH.x][newH.y] = 'S';
    return false;
}

void Snake::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            window.draw(array[i][j]);
        }
    }
}

bool Snake::isGameOver() {
    return gameOver;
}

int Snake::getScore() {
    return score;
}

void Snake::reset() 
{
    initBoard();
    board[7][7] = 's';
    board[11][7] = 'A';

    Point initialPosition = {7, 7};
    snake.push_back(initialPosition);
    dir = " ";
    score = 0;
    gameOver = false;
    update();
}