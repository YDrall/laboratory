import math
class Solution:
    # @param A : integer
    # @return a boolean
    def isPower(self, A):
        return self.is_power_of_two(A)
    
    def is_exact_power_of(self,num,i):
        while num%i==0:
            num = num//i
        return num==1

    def is_power_of_two(self,num):
        if num==1:
            return False
        for i in range(2, int(math.sqrt(num))+1):
            if (num%i ==0) and self.is_exact_power_of(num,i):
                return True
        return False


sol = Solution()
print(sol.isPower(12))