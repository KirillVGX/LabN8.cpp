#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Player {
    string name;
    string position;
    int goals;
    int matches;
    double averageRating;
};

void addPlayer(vector<Player>& players) {
    Player p;
    cout << "Введіть ім'я гравця: ";
    cin >> p.name;
    cout << "Введіть позицію гравця (наприклад, 'нападник', 'захисник'): ";
    cin >> p.position;
    cout << "Введіть кількість голів: ";
    cin >> p.goals;
    cout << "Введіть кількість матчів: ";
    cin >> p.matches;
    cout << "Введіть середній рейтинг: ";
    cin >> p.averageRating;
    players.push_back(p);
    cout << "Гравця додано!\n";
}

void displayPlayers(const vector<Player>& players) {
    if (players.empty()) {
        cout << "Список гравців порожній.\n";
        return;
    }
    for (const auto& p : players) {
        cout << "Ім'я: " << p.name
             << ", Позиція: " << p.position
             << ", Голи: " << p.goals
             << ", Матчі: " << p.matches
             << ", Рейтинг: " << p.averageRating << "\n";
    }
}

void calculateTotalGoals(const vector<Player>& players) {
    int totalGoals = 0;
    for (const auto& p : players) {
        totalGoals += p.goals;
    }
    cout << "Загальна кількість голів команди: " << totalGoals << "\n";
}

void findTopScorer(const vector<Player>& players) {
    if (players.empty()) {
        cout << "Список гравців порожній.\n";
        return;
    }

    const Player* topScorer = &players[0];
    for (const auto& p : players) {
        if (p.goals > topScorer->goals) {
            topScorer = &p;
        }
    }
    cout << "Найкращий бомбардир: " << topScorer->name
         << " (Голи: " << topScorer->goals << ")\n";
}

int main() {
    vector<Player> players;
    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати гравця\n";
        cout << "2. Показати гравців\n";
        cout << "3. Підрахувати загальну кількість голів\n";
        cout << "4. Найкращий бомбардир\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            addPlayer(players);
        } else if (choice == 2) {
            displayPlayers(players);
        } else if (choice == 3) {
            calculateTotalGoals(players);
        } else if (choice == 4) {
            findTopScorer(players);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Некоректний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
