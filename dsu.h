struct DSU {
    DSU() {}

    DSU(int N) {
        color.resize(N);
        siz.resize(N);
        for (int i = 0; i < N; i++) {
            color[i] = i;
            siz[i] = 1;
        }
    }

    int get(int v) {
        return (v == color[v]) ? v : (color[v] = get(color[v]));
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (siz[a] > siz[b]) {
            swap(a, b);
        }
        if (a != b) {
            color[a] = b;
            siz[b] += siz[a];
        }
    }

    int size(int x) {
        return siz[x];
    }

    vector<int> color;
    vector<int> siz;
};
