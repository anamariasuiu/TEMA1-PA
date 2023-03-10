#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    void solve() {
        allocate_matrix();
        print_values();
    }

 private:
    int N, K, a[2][2];
    void print_values() {
        ifstream fin("walsh.in");
        ofstream fout("walsh.out");
        fin >> N >> K;
        for (int i = 0, x, y; i < K; i++) {
            fin >> x >> y;
            fout << find_value(x, y, N) << endl;
        }
        fin.close();
        fout.close();
    }
    // alocam matricea initiala de 2x2
    void allocate_matrix() {
        a[0][0] = 0;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
    }
    int find_value(int x , int y, int D) {
        // am ajuns la dimensiunea de 2x2, returnam valorea
        if (D == 2) {
            return a[x - 1][y - 1];
        }

        int dx = D, dy = D;
        int mx = (1 + dx) / 2;
        int my = (1 + dy) / 2;
        D = D / 2;

        // daca suntem in cadranul 4 negam valoarea si scadem coordonatele
        // cu jumatatea din dimensiunea patratului
        // daca suntem in alt cadran facem resize doar la coordonata care
        // depaseste jumatatea din dimensiunea patratului

        if ((x >= (mx + 1)) && (y >= (my + 1))) {
            return (!find_value(x - D, y - D, D));
        } else {
            if (x > D) {
                x -= D;
            }
            if (y > D) {
                y -= D;
            }
            return find_value(x, y, D);
        }
        return -1;
    }
};
int main() {
    auto* task = new (nothrow) Task();
    task->solve();
    return 0;
}
