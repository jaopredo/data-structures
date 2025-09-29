
def binary_search(ordered_list, search_value, leftIdx = 0, rightIdx = None):
    if rightIdx is None:
        rightIdx = len(ordered_list)-1
    
    midIdx = (rightIdx + leftIdx) // 2

    if ordered_list[midIdx] == search_value:
        return midIdx
    elif ordered_list[midIdx] > search_value:
        return binary_search(ordered_list, search_value, leftIdx, midIdx-1)
    else:
        return binary_search(ordered_list, search_value, midIdx+1, rightIdx)
