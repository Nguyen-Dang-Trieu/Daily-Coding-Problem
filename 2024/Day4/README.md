## Problem
*Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.*

*For example, the input* `[3, 4, -1, 1]` *should give* `2`. *The input* `[1, 2, 0]` *should give* `3`. *The input* `[7, 9, 8]` *should give* `1` *as it is the minimum positive integer.*

**Solution**
- Tìm xem `array` đã cho có chứa số `1` hay chưa? Nếu chưa `return 1`.
- Bởi vì đề yêu cầu là số dương nên khi gặp số nguyên <= 0 thì ta sẽ loại ( ở đây ta sẽ chuyển thành `1`).
- Số nguyên dương cần tìm nằm trong khoảng `[1, n + 1]`. </br>

Example: </br>
+a = [ 1, 2, 3], n = 3 => số cần tìm: 4 </br>
+b = [ 2, 4, 1, 5], n = 4  => số cần tìm: 3 </br>
+c = [ 7, 9, 8], n = 3 => số cần tìm: 1 </br>

- Với số nguyên dương đã xuất hiện thì ta sẽ biến nó thành số âm tại index = số nguyên dương - 1.

## Reference 
- https://christeena-borah.medium.com/daily-coding-problem-4-first-missing-positive-63e4dfdb38ce
