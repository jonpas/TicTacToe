#pragma once

#include <QList>

class Game : public QObject {
    Q_OBJECT

public:
    enum Player { O, X, None };
    Q_ENUM(Player)
    enum State { Running, XWin, OWin, Draw };
    Q_ENUM(State)

    struct Cell {
        QPoint position;
        Player player;
    };
    typedef QList<Cell> CellList;

    static const uint8_t BoardSize;
    static const uint8_t MaxTurns;
    static const Player StartPlayer;

    Game();
    ~Game();

    // Resets game
    void reset();

    // Performs turn with current player, returns false if wrong move, true if successful
    bool doTurn(QPoint position);

    Player getCurrentPlayer() const;
    bool isOver() const;
    State getCurrentState() const;

private:
    CellList cells;
    uint8_t currentTurn;

    State currentState;
    Player currentPlayer;

    // Checks if reached end state (player win), returns
    void checkEnd();

    Cell *getCell(QPoint position);
};