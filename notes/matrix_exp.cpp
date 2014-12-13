struct matrix{double data[26][26];};
matrix mul(matrix a,matrix b)
{
    matrix c;
    memset(c.data, 0, sizeof(double)*676);
    loop(i, 0, 26)
        loop(j, 0, 26)
            loop(k, 0, 26)
                c.data[i][j]+=(a.data[i][k]*b.data[k][j]);
    return c;
}
matrix power(matrix mat,ll p)
{
    if(p==1)return mat;
    matrix m = power(mat,p>>1);
    matrix a = mul(m,m);
    if(p&1)return mul(a,mat);
    else return a;
}

// Using this thing
matrix A;
matrix B = power(A, k);
