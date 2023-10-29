def calculate_expected_gain(p, x):
    r = 1 - p
    L = 0
    W = 0
    max_gain = 0

    for i in range(20528, -1, -1):
        for j in range(0, 2500):
            alpha = r * (W - L)
            beta = r * (W - L)
            P0 = alpha + beta
            expected_gain = P0 * (1 - x)**i
            if expected_gain > max_gain:
                max_gain = expected_gain
                L = i
                W = j
            else:
                break

    return max_gain

x, p = map(float, input().split())
expected_gain = calculate_expected_gain(p, x)
print("Expected Gain:", expected_gain)
