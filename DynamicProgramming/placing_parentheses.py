# Uses python3
def evaluate(a, b, op):
    if (op == '*'):
        return a * b
    if (op == '+'):
        return a + b
    if (op == '-'):
        return a - b

def minMax(m, M, nums, op, i, j):
    cur_min = evaluate(M[i][i], M[i+1][j], op[i])
    cur_max = evaluate(M[i][i], M[i+1][j], op[i])

    for k in range(i, j):
        a = evaluate(M[i][k], M[k+1][j], op[k])
        b = evaluate(M[i][k], m[k+1][j], op[k])
        c = evaluate(m[i][k], M[k+1][j], op[k])
        d = evaluate(m[i][k], m[k+1][j], op[k])

        cur_min = min(cur_min, a, b, c, d)
        cur_max = max(cur_max, a, b, c, d)

    return cur_min, cur_max

def get_maximum_value(dataset):
    assert 1 <= len(dataset) <= 29

    nums = []
    op = []
    for i, elem in enumerate(dataset):
        if i % 2 == 0:
            nums.append(int(elem))
        else:
            op.append(elem)

    m = [[0 for i in range(len(nums))] for i in range (len(nums))]
    M = [[0 for i in range(len(nums))] for i in range (len(nums))]

    for i in range(len(nums)):
        m[i][i] = nums[i]
        M[i][i] = nums[i]

    for s in range(1, len(nums)):
        for i in range(0, len(nums)-s):
            j = i + s
            m[i][j], M[i][j] = minMax(m, M, nums, op, i, j)

    return M[0][-1]


if __name__ == "__main__":
    print(get_maximum_value(input()))
