// 10807 : 개수 세기
#include <stdio.h>

int main(void) {
    int n;
    int arr[100][2];
    int arr_size = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d",&tmp);
        if(arr_size == 0) {
            arr[arr_size][0] = tmp;
            arr[arr_size++][1] = 1;
        }
        else {
            int done = 0;
            for(int i = 0; i < arr_size; i++) {
                if(arr[i][0] == tmp) {
                    arr[i][1]++;
                    done = 1;
                    break;
                }
            }
            if(done == 0) {
                arr[arr_size][0] = tmp;
                arr[arr_size++][1] = 1;
            }
        }
    }
    int v;
    int result = 0;
    scanf("%d",&v);
    for(int i = 0; i < arr_size; i++) {
        if(arr[i][0] == v) {
            result = arr[i][1];
            break;
        }
    }
    printf("%d",result);
    return 0;
}