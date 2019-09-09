ll fac[MAXN], invfac[MAXN];

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

ll C(ll n, ll m) {
    if (n < m) {
        return 0;
    }
    return fac[n] * invfac[m] % MOD * invfac[n-m] % MOD;
}

void precalc_facs() {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = inv(fac[i]);
    }
}
