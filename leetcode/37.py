class Solution:
    def is_valid(self, board, r, c, digit):
        R, C = len(board), len(board[0])
        
        for i in range(R):
            if board[i][c] == digit:
                return False
        
        for i in range(C):
            if board[r][i] == digit:
                return False
        
        srb = r - r%3
        src = c - c%3
        
        for i in range(srb,srb+3):
            for j in range(src,src+3):
                if i == r and j == c:
                    continue
                
                if board[i][j] == digit:
                    return False
        
        return True
    
    def empty_slots(self, board):
        R, C = len(board), len(board[0])
        ret = []
        for i in range(R):
            for j in range(C):
                if board[i][j] == '.':
                    ret.append([i,j])
        return ret
    
    def backtrack(self, board, empty, start, N):
        if start >= N:
            return True
        
        r,c = empty[start]
        
        for digit in range(1,10):
            if self.is_valid(board,r,c,str(digit)):
                board[r][c] = str(digit)
                if(self.backtrack(board, empty, start+1, N)):
                    return True
        
        board[r][c] = '.'
        return False
    
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0 or len(board[0]) == 0:
            return
        
        empty_slots = self.empty_slots(board)
        self.backtrack(board, empty_slots, 0, len(empty_slots))
