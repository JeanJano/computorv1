float abs(float n) {
    return n < 0.0 ? -n : n;
}

float sqrt(float n) {
    float x = n / 2.0f;
    const float precision = 0.00001f;
    const int maxIterations = 10000;

    for (int i = 0; i < maxIterations; ++i) {
        float root = 0.5f * (x + n / x);
        if (abs(root - x) < precision) {
            return root;
        }
        x = root;
    }
    return 0;
}