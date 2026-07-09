int* grayCode(int n,int* returnSize){
*returnSize=1<<n;
int* ans=(int*)malloc(sizeof(int)*(*returnSize));
for(int i=0;i<*returnSize;i++){
ans[i]=i^(i>>1);
}
return ans;
}
