'''
Merge Sort

Running Time: O(n1+n2)
Divide - Conquer - Combine
'''

## 리스트로 입력 받기
unsorted_list = [int(x) for x in input().split()]

## merge sort algorithm
## ㅜn/2로 나누고, 1개씩의 요소가 남기까지 재귀적으로 conquer 한다.
## 그 후, 그 다음에 2개씩의 요소들을 반복적으로 merge 한다.
def merge_sort(unsorted_list):

    if len(unsorted_list) <= 1:
        #print("데이터가 하나 밖에 없습니다.")
        return unsorted_list

    mid = len(unsorted_list)//2
    left = unsorted_list[:mid] 
    right = unsorted_list[mid:]

    left1 = merge_sort(left) ## 재귀를 이용하여 나눠진 왼쪽 부분을 다시 반으로 나눈다
    right1 = merge_sort(right)
    return merge(left1, right1) ## 큰 그림으로 보면 왼쪽부터 오른쪽으로 순서대로 merge

    
def merge(left, right):
    i = 0
    j = 0
    sorted_list = [] ## 정렬할 리스트

    while (i<len(left)) & (j<len(right)): 
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i+=1
        else:
            sorted_list.append(right[j])
            j+=1
    
    while (i<len(left)): ## 남은 값들을 넣어준다
        sorted_list.append(left[i]) 
        i+=1

    while (j<len(right)):
        sorted_list.append(right[j])
        j+=1
     
    return sorted_list
    
print(merge_sort(unsorted_list))




