func longestOnes(nums []int, k int) int {
	var l, r, cur, result int
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			cur++
		}
		for cur > k {
			if nums[l] == 0 {
				cur--
			}
			l++
		}
		r++
		result = max(result, r-l)
	}
	return result
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}