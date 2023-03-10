#include <bits/stdc++.h>
using namespace std;

// un cuvant din sir, nr de aparitii al literei curente si lungimea sirului
struct Object {
    char cuvant[500];
    int nr_aparitii;
    int len;
};
class Task {
 public:
    void solve() {
        read_input();
        print_output();
    }

 private:
    int N;
    vector<Object> cuvinte;
    vector<string> words;
    void read_input() {
        ifstream fin("statistics.in");
        fin >> N;
        for (int i = 0; i < N; i++) {
            cuvinte.push_back(Object());
            fin>> cuvinte[i].cuvant;
            cuvinte[i].len = strlen(cuvinte[i].cuvant);
        }
        fin.close();
    }
    // functie pentru calcularea nr de aparitii al literei in cuvantul word
    int aparitii(char word[500], int litera) {
        int nr_aparitii_per_cuvant = 0;
        for (unsigned int  j = 0; j <  strlen(word); j++) {
            if (word[j] == litera) {
                nr_aparitii_per_cuvant++;
            }
        }
        return nr_aparitii_per_cuvant;
    }
    int sort_words() {
        int ascii_code = 97;
        int max_words = 0;

        // calculam pentru fiecare litera nr maxim de cuvinte in care e
        // dominanta
        for (int k = 0; k < 26; k++) {
            int nr_chars = 0, nr_words = 0;
            int nr_curent_aparitii = 0;

            // calculam nr de aparitii al literei curente in fiecare cuvant
            // din vector si il retinem
            for (int i = 0; i < N; i++) {
                cuvinte[i].nr_aparitii = aparitii(cuvinte[i].cuvant,
                ascii_code);
            }

            // sortam vectorul de cuvinte in functie de dominanta literei
            // in fiecare cuvant
            sort(cuvinte.begin(), cuvinte.end(),
            [](const Object&a, const Object&b)->bool{
                return (2 * a.nr_aparitii  - a.len)
                > (2 * b.nr_aparitii - b.len);
            });

            // verificam in cate cuvinte concatenate litera este dominanta
            for (int i = 0; i < N; i++) {
                if ((nr_chars +  cuvinte[i].len) / 2
                    < (nr_curent_aparitii + cuvinte[i].nr_aparitii)) {
                        nr_curent_aparitii += cuvinte[i].nr_aparitii;
                        nr_chars += cuvinte[i].len;
                        nr_words++;
                }
            }

            // calculam care este numarul maxim de cuvinte cu litera dominanta
            if (nr_words > max_words) {
                max_words = nr_words;
            }
            ascii_code++;
        }
        return max_words;
    }

    void print_output() {
        ofstream fout("statistics.out");
        fout << sort_words();
        fout.close();
    }
};
int main() {
    auto* task = new (nothrow) Task();
    task->solve();
    return 0;
}
