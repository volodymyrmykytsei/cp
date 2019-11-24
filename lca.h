ll up[100500][25], mn[100500][25], tin[100500], tout[100500];
ll timer;

bool upper(ll v, ll u) {
    return tin[u] >= tin[v] && tout[u] <= tout[v];
}
void dfs(ll v, ll curval, ll p = 1) {
    tin[v] = ++timer;

    up[v][0] = p;
    mn[v][0] = curval;
    for (int i = 1; i < 20; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
        mn[v][i] = max(mn[v][i-1], mn[up[v][i-1]][i-1]);
    }

    for (auto tot : tree[v]) {
        ll to = tot.X;
        ll val = tot.Y;
        if (to == p) {
            continue;
        }
        dfs(to, val, v);
    }
    tout[v] = timer;
}

ll find_min(ll x, ll y) {
    ll ans = 0;

    for (int i = 19; i >= 0; i--) {
        if (upper(up[x][i], y)) {
            continue;
        }
        ans = max(ans, mn[x][i]);
        x = up[x][i];
    }
    swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (upper(up[x][i], y)) {
            continue;
        }
        ans = max(ans, mn[x][i]);
        x = up[x][i];
    }
    if (!upper(x, y)) {
        ans = max(ans, mn[x][0]);
    }
    if (!upper(y, x)) {
        ans = max(ans, mn[y][0]);
    }
    return ans;
}
