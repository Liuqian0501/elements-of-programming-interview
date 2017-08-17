import sys
import random

# @include
RED, WHITE, BLUE = range(3)


def dutch_flag_partition(pivot_index, A):
    pivot = A[pivot_index]
    # Keep the following invariants during partitioning:
    # bottom group: A[0:smaller].
    # middle group: A[smaller+1:equal].
    # top group: A[equal+1:larger-1].
    # unclassified group: A[larger:].
    # 
    smaller, equal, larger = -1, -1, 0
    # Keep iterating as long as there is an unclassified element.,
    while larger  < len(A):
        # A[equal] is the incoming unclassified element.
        if A[larger] < pivot:
            A[larger], A[equal+1] = A[equal+1], A[larger];
            A[smaller+1], A[equal+1] = A[equal+1], A[smaller+1]
            smaller, equal, larger = smaller + 1, equal + 1, larger + 1;
        elif A[larger] == pivot:
            A[larger], A[equal+1] = A[equal+1], A[larger];
            equal, larger = equal + 1, larger + 1; 
        else:  # A[equal] > pivot.
            larger += 1;
# @exclude


def main():
    for _ in range(1000):
        n = int(sys.argv[1]) if len(sys.argv) == 2 else random.randint(1, 100)
        A = [random.randint(0, 2) for _ in range(n)]
        pivot_index = random.randrange(n)
        pivot = A[pivot_index]
        dutch_flag_partition(pivot_index, A)
        i = 0
        while i < len(A) and A[i] < pivot:
            print(A[i],  ' ')
            i += 1
        while i < len(A) and A[i] == pivot:
            print(A[i],  ' ')
            i += 1
        while i < len(A) and A[i] > pivot:
            print(A[i],  ' ')
            i += 1
        print()
        assert i == len(A)


if __name__ == '__main__':
    main()
