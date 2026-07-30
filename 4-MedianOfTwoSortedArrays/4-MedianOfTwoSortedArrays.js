// Last updated: 30/07/2026, 10:25:33
function findMedianSortedArrays(nums1, nums2) {
    if (nums1.length > nums2.length) [nums1, nums2] = [nums2, nums1];

    const m = nums1.length, n = nums2.length;
    const half = Math.floor((m + n + 1) / 2);
    let left = 0, right = m;

    while (left <= right) {
        const i = Math.floor((left + right) / 2);
        const j = half - i;

        const maxLeft1  = i > 0 ? nums1[i - 1] : -Infinity;
        const minRight1 = i < m ? nums1[i]     :  Infinity;
        const maxLeft2  = j > 0 ? nums2[j - 1] : -Infinity;
        const minRight2 = j < n ? nums2[j]     :  Infinity;

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 === 1) return Math.max(maxLeft1, maxLeft2);
            return (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2;
        } else if (maxLeft1 > minRight2) {
            right = i - 1;  // too far right in nums1
        } else {
            left = i + 1;   // too far left in nums1
        }
    }
}