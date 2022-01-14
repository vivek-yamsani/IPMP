int matSearch (int N, int M, int matrix[][M], int x)
{
    int i = 0,j = M-1;
    while(i < N && j >= 0){
        if(matrix[i][j] > x) j--;
        else if(matrix[i][j] < x) i++;
        else return 1;
    }
    
    return 0;
}