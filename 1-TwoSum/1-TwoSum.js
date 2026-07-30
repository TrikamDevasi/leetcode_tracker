// Last updated: 30/07/2026, 10:25:38
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const map = new Map();

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    const complement = target - num;

    if (map.has(complement)) {
      return [map.get(complement), i];
    }

    map.set(num, i);
  }

  return [];
};
