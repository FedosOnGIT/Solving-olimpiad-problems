#include<bits/stdc++.h>

using namespace std;

/*
 * Всем известно, что в армии без строевой подготовки и порядка дело не обходится и за этим там строго следят.
 Однажды утром сержант построил всех своих подчиненных в K рядов по N человек в каждом, но оказалось, что солдаты выстроились не по росту, и поэтому сержант решил их наказать.
 Солдаты должны были выстроиться по росту в каждом отдельном ряде так, что слева должны были стоять самые низкие, а справа самые высокие.
 Ну а поскольку в армии виноваты всегда слабые (низкие), то наказание было следующим: каждый солдат должен был отжаться столько раз, сколько солдат стоит от него слева выше его ростом.

 * Оказалось, что все солдаты были разного роста, и многим пришлось отжиматься достаточно много раз.
 Сержанту стало интересно: сколько же раз в общей сложности пришлось отжаться солдатам?

 * Помогите ему решить эту задачу!
 */

static mt19937 engine;

struct node {
    explicit node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        priority = engine();
        size = 1;
    }

    void add(node *son, bool bigger) {
        if (son != nullptr) {
            size += son->size;
        }
        if (bigger) {
            right = son;
        } else {
            left = son;
        }
    }

    node *remove(bool bigger) {
        if (bigger) {
            if (right != nullptr) {
                size -= right->size;
            }
            return right;
        } else {
            if (left != nullptr) {
                size -= left->size;
            }
            return left;
        }
    }

    node *left;
    node *right;
    int priority;
    int value;
    int size;
};

node *merge(node *small, node *big) {
    if (small == nullptr) {
        return big;
    }
    if (big == nullptr) {
        return small;
    }
    if (small->priority > big->priority) {
        small->add(merge(small->remove(true), big), true);
        return small;
    } else {
        big->add(merge(small, big->remove(false)), false);
        return big;
    }
}


pair<node *, node *> split(node *root, int key) {
    if (root == nullptr) {
        return {nullptr, nullptr};
    }
    if (root->value > key) {
        pair<node *, node *> sons = split(root->remove(false), key);
        root->add(sons.second, false);
        return {sons.first, root};
    } else {
        pair<node *, node *> sons = split(root->remove(true), key);
        root->add(sons.first, true);
        return {root, sons.second};
    }
}

pair<int, node *> insert(int value, node *root) {
    pair<node *, node *> parts = split(root, value);
    int size = 0;
    if (parts.second != nullptr) {
        size = parts.second->size;
    }
    return {size, merge(merge(parts.first, new node(value)), parts.second)};
}

int pushUps(vector<vector<int> > &soldiers) {
    int pushUps = 0;
    for (vector<int> &line : soldiers) {
        node *root = nullptr;
        for (int soldier : line) {
            pair<int, node *> added = insert(soldier, root);
            pushUps += added.first;
            root = added.second;
        }
    }
    return pushUps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    engine.seed(std::time(nullptr));
    int members, lines;
    cin >> members >> lines;
    vector<vector<int> > soldiers(lines, vector<int>(members, 0));
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < members; j++) {
            cin >> soldiers[i][j];
        }
    }
    cout << pushUps(soldiers);
}
