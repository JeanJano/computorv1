float abso(float n);

float sqrt(float n) {
    float x = n / 2.0f;
    const float precision = 0.00001f;
    const int maxIterations = 10000;

    for (int i = 0; i < maxIterations; ++i) {
        float root = 0.5f * (x + n / x);
        if (abso(root - x) < precision) {
            return root;
        }
        x = root;
    }
    return 0;
}