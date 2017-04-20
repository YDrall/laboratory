class Solution:
    # @param A : integer
    # @return a list of list of integers
    def prettyPrint(self, A):
        length = 2*(A-1)+1
        result = [ [0 for i in range(length)] for i in range(length)]
        top=0;
        bottom = length-1
        right=length-1
        left = 0
        dir =0
        temp_a = A
        while top<=bottom and left<=right:
            for i in range(left,right+1):
                result[top][i] = temp_a
            top +=1

            for i in range(top,bottom+1):
                result[i][right] = temp_a
            right -=1

            for i in range(right+1,left,-1):
                result[bottom][i] = temp_a
            bottom -=1

            for i in range(bottom+1,top-1,-1):
                result[i][left] = temp_a
            left +=1
            temp_a -=1
        
        return result

if __name__ == "__main__":
    sol = Solution()
    for row in sol.prettyPrint(25):
        print row