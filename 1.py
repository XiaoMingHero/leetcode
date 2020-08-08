"""
1.两数之和
https://www.geekxh.com/1.0.%E6%95%B0%E7%BB%84%E7%B3%BB%E5%88%97/007.html#_01%E3%80%81%E9%A2%98%E7%9B%AE%E5%88%86%E6%9E%90
"""


def force_two_sum(nums: list, target: int) -> list:
    """
    Force method
    :param nums:
    :param target:
    :return:
    """
    for i in range(0, len(nums)):
        for j in range(1, len(nums)):
            if target == nums[i] + nums[j]:
                return [nums[i], nums[j]]
    return []


def two_sum(nums: list, target: int) -> list:
    """
    Store by dict
    :param nums:
    :param target:
    :return:
    """
    dict_num = {num: i for i, num in enumerate(nums)}
    for num in nums:
        if (target - num) in dict_num:
            return [num, target - num]
    return []


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    res = two_sum(nums, target)
    print(res)
