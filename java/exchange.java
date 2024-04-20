import org.junit.Test;

public class exchange {
    @Test
    public void test(){


        
        char[][] asd = new char[][]{{'a'}};
       
        System.out.println(exist(asd, "a"));
        


    }


    String word;
    int length;
    public boolean exist(char[][] board, String word) {
        if(board.length == 0) return false;
        this.word = word;
        this.length = word.length();
        int m = board.length, n = board[0].length;
        boolean[][] isVisited = new boolean[m][n];
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(dfs(board, i, j, isVisited, 0)) return true;
            }
        }
        return false;
    }

    public boolean dfs(char[][] board, int m, int n, boolean[][] isVisited, int cur){
        if(m<0||m>board.length-1||n<0||n>board[0].length-1) return false;
        if(isVisited[m][n]==true||board[m][n]!=word.charAt(cur)) return false;
        if(length == cur+1&&board[m][n]==word.charAt(cur)) return true;
        cur++;
        isVisited[m][n] = true;
        if(m>0&&dfs(board, m-1, n, isVisited, cur)) return true;
        if(m<board.length-1&&dfs(board, m+1, n, isVisited, cur)) return true;
        if(n>0&&dfs(board, m, n-1, isVisited, cur)) return true;
        if(n<board[0].length-1&&dfs(board, m, n+1, isVisited, cur)) return true;
        isVisited[m][n] = false;
        return false;
    }
    
}
