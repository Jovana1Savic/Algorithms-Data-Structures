# python3


def majority_element_naive(elements):
    assert len(elements) <= 10 ** 5
    for e in elements:
        if elements.count(e) > len(elements) / 2:
            return 1

    return 0



def majority_element(elements):
    assert len(elements) <= 10 ** 5
    candidate = elements[0]
    count = 1
    for i in range(1, len(elements)):
        if (elements[i] == candidate):
            count += 1
        else:
            count -= 1
            if (count == 0):
                candidate = elements[i]
                count = 1

    count = 0
    for elem in elements:
        if (elem == candidate):
            count += 1

    if (count > (len(elements)) // 2):
        return 1
    else:
        return 0


if __name__ == '__main__':
    input_n = int(input())
    input_elements = list(map(int, input().split()))
    assert len(input_elements) == input_n
    print(majority_element(input_elements))
