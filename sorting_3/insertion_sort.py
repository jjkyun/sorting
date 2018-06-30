'''
insertion sort

1. input을 리스트 형태로 받고
2. 그 리스트를 insertion sort 함수에 입력
3. 출력하기

running time = O(n^2)
space consumption = O(n)
'''

## 리스트로 입력 받기
unsorted_list = [int(x) for x in input().split()]

## 리스트로 저장하되, 띄어쓰기를 기준으로 입력받아 이를 정수형으로 저장해라 

'''
unsorted_list = []
for x in input().split():
    unsorted_list.append(int(x))
'''

## insertion sorting 알고리즘
def insertion_sort(unsorted_list):
    j = 1
    for j in range(j,len(unsorted_list)):
        key = unsorted_list[j]
        i = j - 1 ## 바로 이전 값에 위치를 가리키고
        while i >= 0 and unsorted_list[i] > key: ## 몇번째 자리에 값을 넣어야하는지 찾는 과정
            unsorted_list[i+1] = unsorted_list[i] ## 조건 만족하면 swap
            i = i - 1
        unsorted_list[i+1] = key 

    return unsorted_list

sorted_list = insertion_sort(unsorted_list)
print(sorted_list)

