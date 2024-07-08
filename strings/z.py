def calculate_z(s):
    n = len(s)  # Length of the input string
    Z = [0] * n  # Initialize the Z-array with zeros
    L, R, K = 0, 0, 0  # Initialize left and right pointers of the Z-box

    for i in range(1, n):
        if i > R:
            # Case 1: i is outside the current Z-box
            L, R = i, i
            while R < n and s[R] == s[R - L]:
                R += 1
            Z[i] = R - L
            R -= 1
        else:
            # Case 2: i is inside the current Z-box
            K = i - L
            if Z[K] < R - i + 1:
                Z[i] = Z[K]
            else:
                L = i
                while R < n and s[R] == s[R - L]:
                    R += 1
                Z[i] = R - L
                R -= 1
    return Z

def z_algorithm_search(text, pattern):
    # Concatenate pattern, special character, and text
    concat = pattern + "$" + text
    # Compute Z-array for the concatenated string
    Z = calculate_z(concat)
    print(Z)
    pattern_length = len(pattern)  # Length of the pattern
    result = []  # List to store the indices of pattern occurrences

    for i in range(len(Z)):
        if Z[i] == pattern_length:
            # If Z[i] is equal to the length of the pattern, it means a match is found
            result.append(i - pattern_length - 1)

    return result

# Example usage
text = "ababcababcababc"
pattern = "ababc"
occurrences = z_algorithm_search(text, pattern)

print("Pattern found at indices:", occurrences)
