def main():
    array = [7, 9, 8, 1, 3, 2, 4]
    
    # Base case check: if '1' is not present, return 1.
    contain_One = False # type data: bool
    for num in array:
        if num == 1:
            contain_One = True 
            break
    if not contain_One:
        return 1
    
    # Modify the array to prepare for pressing
    n = len(array)
    for i in range(0, n):
        #  0 <= i <= n
        if array[i] <= 0 or array[i] > n:
            array[i] = 1


    # array = [1, 1, 1, 4, 2, 1]
    # Mark the presence of positive integers by negating values.
    for i in range(0,n):
        x = abs(array[i])
        array[x - 1] = -abs(array[x - 1])
    
    # array = [-1, -1, 1, -4, 2, 1]
    for i in range(0,n): # n = 6
        if array[i] > 0:
            return i + 1
        
if __name__ == '__main__':
    x = main()
    print(x)
