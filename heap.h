#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

template <typename T>
class Heap {
    std::vector<T> data;
    std::unordered_map<T, int> map;

    void upheapify(int ci) {
        int pi = (ci - 1) / 2;
        if (isLarger(data[ci], data[pi])) {
            swap(pi, ci);
            upheapify(pi);
        }
    }

    void downheapify(int pi) {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int mini = pi;

        if (lci < data.size() && isLarger(data[lci], data[mini])) {
            mini = lci;
        }
        if (rci < data.size() && isLarger(data[rci], data[mini])) {
            mini = rci;
        }
        if (mini != pi) {
            swap(mini, pi);
            downheapify(mini);
        }
    }

    bool isLarger(const T &a, const T &b) {
        return a > b; // Assumes T implements `operator>`
    }

    void swap(int i, int j) {
        std::swap(data[i], data[j]);
        map[data[i]] = i;
        map[data[j]] = j;
    }

public:
    void add(const T &item) {
        data.push_back(item);
        map[item] = data.size() - 1;
        upheapify(data.size() - 1);
    }

    T remove() {
        swap(0, data.size() - 1);
        T rv = data.back();
        data.pop_back();
        map.erase(rv);
        downheapify(0);
        return rv;
    }

    void updatePriority(const T &item) {
        int idx = map[item];
        upheapify(idx);
    }

    int size() const {
        return data.size();
    }

    bool isEmpty() const {
        return data.empty();
    }

    void display() const {
        for (const auto &item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};
