# Simple function that calculates if the permutation is even or odd
# Finds number of even cycles. If the number of even cycles is odd permutation is even.
# Cycle is even if and only if its length is odd.
def is_even(p):
    visited = [False for i in range(len(p))]
    num_of_transpositions = 0
    for i in range(len(p)):
        if (visited[i] == True):
            continue
        cycle_len = 0
        ret = []
        j = i
        while (visited[j] == False):
            ret.append(j)
            visited[j] = True
            j = p[j]
            cycle_len += 1
        num_of_transpositions += (cycle_len - 1)
    return (num_of_transpositions) % 2 == 0



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    p =   [10, 4, 2, 7, 9, 3, 0, 11, 5, 6, 1, 8]
    print(is_even(p))
    p =    [0,3,2,4,5,6,7,1,9,8]
    print(is_even(p))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
