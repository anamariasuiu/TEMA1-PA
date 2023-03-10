#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    Task() : d(100000, INT_MAX) {}
    void solve() {
        read_input();
        countOperations();
        print_output();
    }

 private:
    int N, K;
    vector<int> targets;
    vector<int> prices;
    vector<int> d;
    void read_input() {
        ifstream fin("prinel.in");
        fin >> N >> K;
        targets.push_back(0);
        for (int i = 1, e; i <= N; i++) {
            fin >> e;
            targets.push_back(e);
        }
        prices.push_back(0);
        for (int i = 1, e; i <= N; i++) {
            fin >> e;
            prices.push_back(e);
        }
        fin.close();
    }
    void countOperations() {
		// caut cel mai mare target
		int nr = targets[1];
		for (int i = 2; i <= N; i++) {
            nr = max(nr, targets[i]);
		}
		d[1] = 0;

		// calculez nr de operatii pentru toti divizorii pana la nr
		for (int i = 1; i <= nr; ++i) {
			for (int j = 1; j <= sqrt(i); ++j) {
				// am gasit divizor pentru i
				if (i % j == 0) {
					// calculam nr de operatii doar pana la cel mai mare target
                    // si alegem minimul de operatii dintre adaugarea
                    // divizorului sau nr de operatii calculat anterior
					if (i + j <= nr) {
						d[i + j] = min(d[i] + 1, d[i + j]);
					}

                    // calculez minimul de operatii dintre adaugarea divizorului
                    // complementar sau nr de operatii calculat anterior
					if ((i + i / j) <= nr) {
						d[i + i / j] = min(d[i] + 1, d[i + i / j]);
					}
				}
			}
		}
    }
    // functie pentru calcularea pretului maxim pentru cat mai multe
    // targeturi alese cu maxim K operatii
    int get_result() {
        vector< vector<int> > dp(N + 1, vector<int>(K + 1, 0));
        for (int cap = 0; cap <= K; ++cap) {
            dp[0][cap] = 0;
        }
        for (int i = 1; i <= N; ++i) {
            for (int cap = 0; cap <= K; ++cap) {
                dp[i][cap] = dp[i-1][cap];
                if (cap - d[targets[i]] >= 0) {
                    int sol_aux = dp[i-1][cap - d[targets[i]]]
                    + prices[i];
                    dp[i][cap] = max(dp[i][cap], sol_aux);
                }
            }
        }
        return dp[N][K];
    }
    void print_output() {
        ofstream fout("prinel.out");
        fout << get_result();
        fout.close();
    }
};
int main() {
    auto* task = new (nothrow) Task();
    task->solve();
    return 0;
}
