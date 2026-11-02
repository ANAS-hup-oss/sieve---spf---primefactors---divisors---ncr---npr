const int N = 1e6 + 5;
int spf[N];

void sieve() {
    for (int i = 1; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<pair<int,int>> primeFactors(int n) {
    vector<pair<int,int>> res;

    while (n > 1) {
        int p = spf[n], cnt = 0;

        while (n % p == 0) {
            n /= p;
            cnt++;
        }

        res.push_back({p, cnt});
    }

    return res;
}
