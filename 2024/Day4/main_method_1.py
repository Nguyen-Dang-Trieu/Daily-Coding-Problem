class FirstMissingPositive:
    def find_missing_positive(self, nums):
        n = len(nums)
        positive_map = {}

        # Đánh dấu các số nguyên dương có mặt trong từ điển
        for num in nums:
            if num > 0:
                positive_map[num] = True
        
        print(positive_map)
        # Kiểm tra số nguyên dương thiếu đầu tiên
        for i in range(1, n + 1):
            if i not in positive_map:
                return i

        # Nếu tất cả các số nguyên dương từ 1 đến n đều có mặt, trả về n + 1
        return n + 1

if __name__ == "__main__":
    fmp = FirstMissingPositive()
    array_sample = [1, 7, 6, -1, 0, 3, -2, 2]
    result = fmp.find_missing_positive(array_sample)
    print("The first missing positive integer is:", result)
