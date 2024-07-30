4444444
4333334
4322234
4321234
4322234
4333334
4444444

void getNumberPattern(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            cout << std::max(i, j);
        }
        for (int j = 2; j <= n; j++) {
            cout << std::max(i, j);
        }
        cout << "\n";
    }
    for (int i = 2; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            cout << std::max(i, j);
        }
        for (int j = 2; j <= n; j++) {
            cout << std::max(i, j);
        }
        cout << "\n";
    }
}
